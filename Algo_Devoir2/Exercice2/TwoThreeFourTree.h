#pragma once
#include "TwoThreeFourNode.h"
#include <iostream>
template <class T>
class RNTree;
template<typename T>
class TwoThreeFourTree
{
private:
	int nbNodes;
	TwoThreeFourNode<T>* root;
public:
	TwoThreeFourTree();
	TwoThreeFourTree(RNTree<T> other);
	~TwoThreeFourTree();
	bool isEmpty() const;
	TwoThreeFourNode<T>* getRoot();
	void insertValue(const T &value, TwoThreeFourNode<T>* currentNode);
	void removeValue(const T &, TwoThreeFourNode<T>* currentNode, TwoThreeFourNode<T>* nodeToDelete = NULL);
	int getNbNodes() const;
	TwoThreeFourNode<T>* search(const T &, TwoThreeFourNode<T>* currentNode) const;
	int getNextNodeToVisit(T value, TwoThreeFourNode<T>* currentNode) const;
	int getNextNodeToVisitGoE(T value, TwoThreeFourNode<T>* currentNode ) const;
	template <typename U> friend std::ostream& operator<<(std::ostream& stream, const TwoThreeFourTree<U> tree) {
		stream << *(tree.root);
		return stream;
	}
};


template<typename T>
inline TwoThreeFourTree<T>::TwoThreeFourTree()
{
	nbNodes = 0;
}

template<typename T>
inline TwoThreeFourTree<T>::TwoThreeFourTree(RNTree<T> other)
{
	nbNodes = 0;
	this->root = other.getRoot()->getEquivalentTwoThreeFourNode();
}

template<typename T>
inline TwoThreeFourTree<T>::~TwoThreeFourTree()
{
}

template<typename T>
inline bool TwoThreeFourTree<T>::isEmpty() const
{
	return this->getNbNodes() == 0;
}

template<typename T>
inline TwoThreeFourNode<T>* TwoThreeFourTree<T>::getRoot()
{
	return this->root;
}

template<typename T>
inline void TwoThreeFourTree<T>::insertValue(const T & value, TwoThreeFourNode<T>* currentNode)
{
	if (this->isEmpty()) { //Insert as root
		this->root = new TwoThreeFourNode<T>();
		this->root->pushKey(value);
		this->nbNodes++;
	}
	else {
		//Splitting all 4 nodes during pass
		if (currentNode->is4Node()) {
			//Removing middle value
			T middleValue = currentNode->getKeys()[1];
			vector<T>::iterator it = currentNode->getKeys().begin();
			it++;
			currentNode->getKeys().erase(it);
			//Splitting remaining node into a pair of 2-nodes
			TwoThreeFourNode<T>* node1 = new TwoThreeFourNode<T>();
			node1->pushKey(currentNode->getKeys()[0]);
			TwoThreeFourNode<T>* node2 = new TwoThreeFourNode<T>();
			node2->pushKey(currentNode->getKeys()[1]);
			if (!currentNode->isLeaf()) {
				node1->addChild(currentNode->getChildren()[0]);
				node1->addChild(currentNode->getChildren()[1]);
				node2->addChild(currentNode->getChildren()[2]);
				node2->addChild(currentNode->getChildren()[3]);
			}
			if (currentNode->isRoot()) {
				TwoThreeFourNode<T>* newRoot = new TwoThreeFourNode<T>();
				newRoot->pushKey(middleValue);
				newRoot->addChild(node1);
				newRoot->addChild(node2);
				currentNode = newRoot;
				this->root = newRoot;
				this->nbNodes += 2;
			}
			else {
				TwoThreeFourNode<T>* parent = currentNode->getParent();
				parent->pushKey(middleValue);
				parent->removeChild(currentNode);
				currentNode = parent;
				parent->addChild(node1);
				parent->addChild(node2);
				this->nbNodes += 1;
			}
		}
		if (currentNode != NULL) {
			if (currentNode->isRoot() && currentNode->isLeaf()) {
				currentNode->pushKey(value);
			}
			else {
				if (currentNode->isLeaf()) {
					currentNode->pushKey(value);
				}
				else {
					//Find the child whose interval contains the value to be inserted
					TwoThreeFourNode<T>* childFound;
					childFound = currentNode->getChildren()[getNextNodeToVisit(value, currentNode)];
					this->insertValue(value, childFound);
				}
			}
		}
	}
}


template<typename T>
inline void TwoThreeFourTree<T>::removeValue(const T & value, TwoThreeFourNode<T>* currentNode, TwoThreeFourNode<T>* nodeToDelete)
{
	for (vector<T>::iterator it = currentNode->getKeys().begin(); it != currentNode->getKeys().end(); ++it) {
		if (*it == value) {
			nodeToDelete = currentNode;
		}
	}
	if (currentNode->isLeaf()) {
		if (nodeToDelete == currentNode) {
			for (vector<T>::iterator it = currentNode->getKeys().begin(); it != currentNode->getKeys().end(); ++it) {
				if (*it == value) {
					currentNode->getKeys().erase(it); //VALUE HAS BEEN FOUND AND DELETED
					return;
				}
			}
		}
		else if(nodeToDelete != NULL) {
			for (vector<T>::iterator it = nodeToDelete->getKeys().begin(); it != nodeToDelete->getKeys().end(); ++it) {
				if (*it == value) {
					nodeToDelete->getKeys().erase(it);
					break;
				}
			}
			nodeToDelete->pushKey(currentNode->getKeys()[0]);
			currentNode->getKeys().erase(currentNode->getKeys().begin());
		}
		return;
	}
	else {
		TwoThreeFourNode<T>* nextNode;
		TwoThreeFourNode<T>* siblingRight = NULL;
		TwoThreeFourNode<T>* siblingLeft = NULL;
		TwoThreeFourNode<T>* nodeToStealFrom = NULL;
		int indexNodeToVisit;
		if (nodeToDelete == NULL) {
			indexNodeToVisit = getNextNodeToVisit(value, currentNode);
		}
		else {
			indexNodeToVisit = getNextNodeToVisitGoE(value, currentNode);
		}
		nextNode = currentNode->getChildren()[indexNodeToVisit];
		if (nextNode->is2Node()) { //If following node is not a 2 node then nothing to do
			//Look for a sibling that has at least 2 keys
			//First let's retrieve those siblings
			if (indexNodeToVisit > 0) {
				siblingLeft = currentNode->getChildren()[(indexNodeToVisit-1)];
			}
			if (indexNodeToVisit < currentNode->getChildren().size()-1) {
				siblingRight = currentNode->getChildren()[(indexNodeToVisit+1)];
			}
			//First try from the left, if possible
			if(siblingLeft != NULL && !siblingLeft->is2Node()){
				//Then we can steal from it
				nodeToStealFrom = siblingLeft;
				nextNode->pushKey(currentNode->getKeys()[indexNodeToVisit-1]);
				if (!nodeToStealFrom->isLeaf()) {
					nextNode->addChild(nodeToStealFrom->getChildren()[nodeToStealFrom->getChildren().size() - 1]);
					nodeToStealFrom->getChildren().erase(nodeToStealFrom->getChildren().end());
				}
				currentNode->getKeys()[indexNodeToVisit] = nodeToStealFrom->getKeys()[nodeToStealFrom->getChildren().size() - 1];
				nodeToStealFrom->getKeys().erase(nodeToStealFrom->getKeys().end());
			}
			//Then we try from the right, again if possible
			else if (siblingRight != NULL && !siblingRight->is2Node()) {
				//Then we can steal from it
				nodeToStealFrom = siblingRight;
				nextNode->pushKey(currentNode->getKeys()[indexNodeToVisit]);
				if (!nodeToStealFrom->isLeaf()) {
					nextNode->addChild(nodeToStealFrom->getChildren()[0]);
					nodeToStealFrom->getChildren().erase(nodeToStealFrom->getChildren().begin());
				}
				currentNode->getKeys()[indexNodeToVisit] = nodeToStealFrom->getKeys()[0];
				nodeToStealFrom->getKeys().erase(nodeToStealFrom->getKeys().begin());
			}
			//In this case no sibling is more than a 2 node so we have to merge with parent
			else {
				if (!currentNode->isRoot()) {
					TwoThreeFourNode<T>* newNode = new TwoThreeFourNode<T>();
					if (siblingLeft != NULL) 
					{
						newNode->pushKey(siblingLeft->getKeys()[0]);		
						newNode->pushKey(currentNode->getKeys()[indexNodeToVisit-1]);
						newNode->pushKey(nextNode->getKeys()[0]);
						if (!nextNode->isLeaf()) {
							newNode->addChild(siblingLeft->getChildren()[0]);
							newNode->addChild(siblingLeft->getChildren()[1]);
							newNode->addChild(nextNode->getChildren()[0]);
							newNode->addChild(nextNode->getChildren()[1]);
						}
						vector<TwoThreeFourNode<T>*>::iterator it = currentNode->getChildren().begin();
						for (int i = 0; i != indexNodeToVisit-1; i++) {
							++it;
						}
						currentNode->getChildren().erase(it, it+2);
						vector<T>::iterator itKeys = currentNode->getKeys().begin() + indexNodeToVisit-1;
						currentNode->getKeys().erase(itKeys);
							it = currentNode->getChildren().begin();
						for (int i = 0; i != indexNodeToVisit-1; i++) {
							++it;
						}
						currentNode->getChildren().insert(it, newNode);
						newNode->setParent(currentNode);
					}
					else if (siblingRight != NULL) {
						newNode->pushKey(nextNode->getKeys()[0]);
						newNode->pushKey(currentNode->getKeys()[indexNodeToVisit]);
						newNode->pushKey(siblingRight->getKeys()[0]);
						if (!nextNode->isLeaf()) {
							newNode->addChild(nextNode->getChildren()[0]);
							newNode->addChild(nextNode->getChildren()[1]);
							newNode->addChild(siblingRight->getChildren()[0]);
							newNode->addChild(siblingRight->getChildren()[1]);
						}
						vector<TwoThreeFourNode<T>*>::iterator it = currentNode->getChildren().begin();
						for (int i = 0; i != indexNodeToVisit; i++) {
							++it;
						}
						currentNode->getChildren().erase(it, it+2);
						vector<T>::iterator itKeys = currentNode->getKeys().begin() + indexNodeToVisit;
						currentNode->getKeys().erase(itKeys);
						it = currentNode->getChildren().begin();
						for (int i = 0; i != indexNodeToVisit; i++) {
							++it;
						}
						currentNode->getChildren().insert(it,newNode);
						newNode->setParent(currentNode);
					}
					delete nextNode;
					nextNode = newNode;
					this->nbNodes -= 1;
				}
				else {//Special operation if we are at root
					TwoThreeFourNode<T>* newRoot = new TwoThreeFourNode<T>();
					if (siblingLeft != NULL) {
						newRoot->pushKey(currentNode->getKeys()[0]);
						newRoot->pushKey(siblingLeft->getKeys()[0]);
						newRoot->pushKey(nextNode->getKeys()[0]);
						if (!siblingLeft->isLeaf()) {
							newRoot->addChild(siblingLeft->getChildren()[0]);
							newRoot->addChild(siblingLeft->getChildren()[1]);
							newRoot->addChild(nextNode->getChildren()[0]);
							newRoot->addChild(nextNode->getChildren()[1]);
						}
						delete siblingLeft;
					}
					else if (siblingRight != NULL) {
						newRoot->pushKey(currentNode->getKeys()[0]);
						newRoot->pushKey(nextNode->getKeys()[0]);
						newRoot->pushKey(siblingRight->getKeys()[0]);
						if (!siblingRight->isLeaf()) {
							newRoot->addChild(nextNode->getChildren()[0]);
							newRoot->addChild(nextNode->getChildren()[1]);
							newRoot->addChild(siblingRight->getChildren()[0]);
							newRoot->addChild(siblingRight->getChildren()[1]);
						}
						delete siblingRight;
					}
					this->root = newRoot;
					this->nbNodes -= 2;
					delete currentNode;
					delete nextNode;
					siblingLeft = NULL;
					siblingRight = NULL;
					currentNode = NULL;
					nextNode = newRoot;
				}
			}
		}
		removeValue(value, nextNode,nodeToDelete);
	}
}


template<typename T>
inline int TwoThreeFourTree<T>::getNbNodes() const
{
	return this->nbNodes;
}

template<typename T>
inline TwoThreeFourNode<T>* TwoThreeFourTree<T>::search(const T & value, TwoThreeFourNode<T>* currentNode) const
{
	TwoThreeFourNode<T>* nextNode = this->root;
	bool found = false;
	while (!found) {
		currentNode = nextNode;
		for (T element : currentNode->getKeys()) {
			if (element == value) {
				found = true;
			}
		}
		if (!found) {
			//Case of a Leaf
			if (currentNode->isLeaf()) {
				return NULL;
			}
			else {
				nextNode = currentNode->getChildren()[getNextNodeToVisit(value,currentNode)];
			}
			
		}
		else {
			return currentNode;
		}
			
	}
	return false;
}

template<typename T>
inline int TwoThreeFourTree<T>::getNextNodeToVisit(T value, TwoThreeFourNode<T>* currentNode) const
{
//Two node
	if (currentNode->getChildren().size() == 2) {
		if (value < currentNode->getKeys()[0]) {
			return 0;
		}
		else if (value > currentNode->getKeys()[0]) {
			return 1;
		}
	}
//Three node
	else if (currentNode->getChildren().size() == 3) {
		if (value < currentNode->getKeys()[0]) {
			return 0;
		}
		else if (value > currentNode->getKeys()[1]) {
			return 2;
		}
		else if (value > currentNode->getKeys()[0] && value < currentNode->getKeys()[1]) {
			return 1;
		}
	}
//Four node
	else if (currentNode->getChildren().size() == 4) {
		if (value < currentNode->getKeys()[0]) {
			return 0;
		}
		else if (value > currentNode->getKeys()[2]) {
			return 3;
		}
		else if (value > currentNode->getKeys()[0] && value < currentNode->getKeys()[1]) {
			return 1;
		}
		else if (value > currentNode->getKeys()[1] && value < currentNode->getKeys()[2]) {
			return 2;
		}
	}
}

template<typename T>
inline int TwoThreeFourTree<T>::getNextNodeToVisitGoE(T value, TwoThreeFourNode<T>* currentNode) const
{
	//Two node
	if (currentNode->getChildren().size() == 2) {
		if (value < currentNode->getKeys()[0]) {
			return 0;
		}
		else if (value >= currentNode->getKeys()[0]) {
			return 1;
		}
	}
	//Three node
	else if (currentNode->getChildren().size() == 3) {
		if (value < currentNode->getKeys()[0]) {
			return 0;
		}
		else if (value >= currentNode->getKeys()[1]) {
			return 2;
		}
		else if (value >= currentNode->getKeys()[0] && value < currentNode->getKeys()[1]) {
			return 1;
		}
	}
	//Four node
	else if (currentNode->getChildren().size() == 4) {
		if (value < currentNode->getKeys()[0]) {
			return 0;
		}
		else if (value >= currentNode->getKeys()[2]) {
			return 3;
		}
		else if (value >= currentNode->getKeys()[0] && value < currentNode->getKeys()[1]) {
			return 1;
		}
		else if (value >= currentNode->getKeys()[1] && value < currentNode->getKeys()[2]) {
			return 2;
		}
	}
}