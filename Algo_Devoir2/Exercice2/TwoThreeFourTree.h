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
	void removeValue(const T &);
	int getNbNodes() const;
	TwoThreeFourNode<T> search(const T &) const;
	int getNextNodeToVisit(T value, TwoThreeFourNode<T>* currentNode);

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
		//First we have to find where to insert the node
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
			if (currentNode->isRoot()) {
				TwoThreeFourNode<T>* newRoot = new TwoThreeFourNode<T>();
				newRoot->pushKey(middleValue);
				newRoot->addChild(node1);
				newRoot->addChild(node2);
				currentNode = newRoot;
				this->root = newRoot;
			}
			else {
				currentNode->getParent()->getKeys().push_back(middleValue);
			}
			this->nbNodes+=2;
		}
		if (currentNode->isRoot() && currentNode->isLeaf()) {
			/*for (int i = 1; i < currentNode->getKeys().size(); i++) {
				if (value > currentNode->getKeys()[i-1]) {
					currentNode->getKeys().insert(value,i - 1);
				}
			}*/
			currentNode->pushKey(value);
			
		}
		else {
			//Find the child whose interval contains the value to be inserted
			TwoThreeFourNode<T>* childFound;
			childFound = currentNode->getChildren()[getNextNodeToVisit(value, currentNode)];
			if (childFound->isLeaf()) {
				childFound->pushKey(value);
			}
			else {
				this->insertValue(value, childFound);
			}
		}
	}
}

template<typename T>
inline void TwoThreeFourTree<T>::removeValue(const T & value)
{
	TwoThreeFourNode<T> currentNode;
	TwoThreeFourNode<T> nextNode = this->root;
	bool found = false;
	while (!found) {
		currentNode = nextNode;	
		if (!currentNode.isRoot()) {
			int i = 0;
			for (T element : currentNode.getKeys()) {
				if element == value() {
					found = true;
					currentNode.getKeys().erase(i);
				}
				i++;
			}
		}
		int indexNodeToVisit = getNextNodeToVisit(value, currentNode)
		nextNode = currentNode.getChildren()[indexNodeToVisit];
		nearestSibling = currentNode.getChildren()[indexNodeToVisit + 1];
		//If nextNode is not a 2 node 
		if (nextNode.is2Node()) {
			if (nearestSibling.is2Node()) {
				if (currentNode.is2Node()) { //currentNode must be root

				}
				else {

				}
			}
			else if (nearestSibling.is3Node() || nearestSibling.is4Node()) {
				T tmp = currentNode.getKeys()[0];
				currentNode.getKeys()[0] = nearestSibling.getKeys()[0];
				nextNode.getKeys().insert(tmp)
			}
		}
	}
}


template<typename T>
inline int TwoThreeFourTree<T>::getNbNodes() const
{
	return this->nbNodes;
}

template<typename T>
inline TwoThreeFourNode<T> TwoThreeFourTree<T>::search(const T & value) const
{
	TwoThreeFourNode<T> currentNode;
	TwoThreeFourNode<T> nextNode = this->root;
	bool found = false;
	while (!found) {
		currentNode = nextNode;
		for (T element : currentNode.getKeys()) {
			if element == value() {
				found = true;
			}
		}
		if (!found) {
			//Case of a Leaf
			if (currentNode.isLeaf()) {
				return NULL;
			}
			else {
				nextNode = currentNode.getChildren()[getNextNodeToVisit(value,currentNode)];
			}
			
		}
		else {
			return currentNode;
		}
			
	}
	return false;


}

template<typename T>
inline int TwoThreeFourTree<T>::getNextNodeToVisit(T value, TwoThreeFourNode<T>* currentNode)
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

