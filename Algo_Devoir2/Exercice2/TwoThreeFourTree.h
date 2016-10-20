#pragma once
#include "TwoThreeFourNode.h"
#include <iostream>

template<typename T>
class TwoThreeFourTree
{
private:
	int nbNodes;
	TwoThreeFourNode<T>* root;
public:
	TwoThreeFourTree();
	~TwoThreeFourTree();
	bool isEmpty() const;
	TwoThreeFourNode<T>* getRoot();
	void insertValue(const T &value, TwoThreeFourNode<T>* currentNode);
	void removeValue(const T &, TwoThreeFourNode<T>* currentNode);
	int getNbNodes() const;
	TwoThreeFourNode<T>* search(const T &) const;
	int getNextNodeToVisit(T value, TwoThreeFourNode<T>* currentNode) const;
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
inline TwoThreeFourTree<T>::~TwoThreeFourTree()
{
	//delete this->root;
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
inline void TwoThreeFourTree<T>::removeValue(const T & value, TwoThreeFourNode<T>* currentNode)
{
	if (currentNode->isLeaf()) {
		for (vector<T>::iterator it = currentNode->getChildren().begin(); it != currentNode->getChildren().end; ++it) {
			if (*it == value) {
				currentNode->getChildren().erase(it); //VALUE HAS BEEN FOUND AND DELETED
				return;
			}
		}
		//VALUE WAS NOT IN TREE
	}
	else {
		TwoThreeFourNode<T> nextNode;
		int indexNodeToVisit = getNextNodeToVisit(value, currentNode);
		nextNode = currentNode.getChildren()[indexNodeToVisit];
		if (nextNode->is2Node()) { //If following node is not a 2 node then nothing to do
			if(){

			}
		}
		removeValue(value, nextNode);
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
	TwoThreeFourNode<T>* currentNode;
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