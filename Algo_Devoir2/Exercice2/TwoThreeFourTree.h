#pragma once
#include "TwoThreeFourNode.h"
template<typename T>
class TwoThreeFourTree
{
private:
	int nbNodes;
	TwoThreeFourNode root;
public:
	TwoThreeFourTree();
	~TwoThreeFourTree();
	bool isEmpty() const;
	void insertValue(const T &value, TwoThreeFourNode<T> currentNode);
	void removeValue(const T &);
	const T & max() const;
	const T & min() const;
	int getNbNodes() const;
	TwoThreeFourNode<T> search(const T &) const;
};

template<typename T>
inline TwoThreeFourTree<T>::TwoThreeFourTree()
{
	root = NULL;
	nbNodes = 0;
}


template<typename T>
inline TwoThreeFourTree<T>::~TwoThreeFourTree()
{
}

template<typename T>
inline bool TwoThreeFourTree<T>::isEmpty() const
{
	return root == NULL;
}

template<typename T>
inline void TwoThreeFourTree<T>::insertValue(const T & value, TwoThreeFourNode<T> currentNode = this->root)
{
	if (this->isEmpty()) { //Insert as root
		this->root = TwoThreeFourNode<T>();
		this->root.getKeys().insert(value);
		this->nbNodes + 1;
	}
	else {
		//First we have to find where to insert the node
		if (currentNode.getChildren().size() == 4) {
			//Removing middle value
			T middleValue = currentNode.getKeys()[1];
			currentNode.getKeys().erase[1];
			//Splitting remaining node into a pair of 2-nodes
			TwoThreeFourNode<T> node1 = TwoThreeFourNode<T>();
			node1.getKeys().insert(currentNode.getKeys()[0]);
			node1.addChild(currentNode.getChildren()[0]);
			node1.addChild(currentNode.getChildren()[1]);
			TwoThreeFourNode<T> node2 = TwoThreeFourNode<T>();
			node2.getKeys().insert(currentNode.getKeys()[1]);
			node2.addChild(currentNode.getChildren()[2]);
			node2.addChild(currentNode.getChildren()[3]);
			if (currentNode.isRoot()) {
				TwoThreeFourNode<T> newRoot = TwoThreeFourNode<T>();
				newRoot.getKeys().insert(middleValue);
				newRoot.addChild(node1);
				newRoot.addChild(node2);
				currentNode = newRoot;
				this->root = newRoot;
			}
			else {
				currentNode.getParent().getKeys().insert(middleValue);
			}
			this->nbNodes + 1;
		}
		//Find the child whose interval contains the value to be inserted
		TwoThreeFourNode<T> childFound;
		//If this is a 2 node
		if (currentNode.getChildren().size() == 2) {
			if (value < currentNode.getKeys()[0]) {
				childFound = currentNode.getChildren()[0];
			}
			else if (value > currentNode.getKeys()[0]){
				childFound = currentNode.getChildren()[1];
			}
		}
		//If this is a 3 node
		else if (currentNode.getChildren().size() == 3) {
			if (value < currentNode.getKeys()[0]) {
				childFound = currentNode.getChildren()[0];
			}
			else if (value > currentNode.getKeys()[1]){
				childFound = currentNode.getChildren()[2];
			}
			else if(value < currentNode.getKeys()[0] && value > currentNode.getKeys()[1]){
				childFound = currentNode.getChildren()[1];
			}
		}
		if (childFound.isLeaf()) {
			childFound.getKeys().insert(value);
		}
		else {
			this->insertValue(value, childFound);
		}
	}
}

template<typename T>
inline void TwoThreeFourTree<T>::removeValue(const T & value)
{
	//C'est chaud aussi
}

template<typename T>
inline const T & TwoThreeFourTree<T>::max() const
{
	// TODO: insert return statement here
}

template<typename T>
inline const T & TwoThreeFourTree<T>::min() const
{
	// TODO: insert return statement here
}

template<typename T>
inline int TwoThreeFourTree<T>::getNbNodes() const
{
	return this->nbNodes
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
			if (currentNode.isLeaf) {
				return NULL;
			}
			//Two node
			else if (currentNode.getChildren().size() == 2) {
				if (value < currentNode.getKeys()[0]) {
					nextNode = currentNode.getChildren()[0];
				}
				else if (value > currentNode.getKeys()[0]){
					nextNode = currentNode.getChildren()[1];
				}
			}
			//Three node
			else if (currentNode.getChildren().size() == 3) {
				if (value < currentNode.getKeys()[0]) {
					nextNode = currentNode.getChildren()[0];
				}
				else if (value > currentNode.getKeys()[1]) {
					nextNode = currentNode.getChildren()[2];
				}
				else if (value > currentNode.getKeys()[0] && value < currentNode.getKeys()[1]) {
					nextNode = currentNode.getChildren()[1];
				}
			}
			//Four node
			else if (currentNode.getChildren().size() == 4) {
				if (value < currentNode.getKeys()[0]) {
					nextNode = currentNode.getChildren()[0];
				}
				else if (value > currentNode.getKeys()[2]) {
					nextNode = currentNode.getChildren()[3];
				}
				else if (value > currentNode.getKeys()[0] && value < currentNode.getKeys()[1]) {
					nextNode = currentNode.getChildren()[1];
				}
				else if (value > currentNode.getKeys()[1] && value < currentNode.getKeys()[2]) {
					nextNode = currentNode.getChildren()[2];
				}
			}
		}
		else {
			return currentNode;
		}
			
	}
	return false;
}
