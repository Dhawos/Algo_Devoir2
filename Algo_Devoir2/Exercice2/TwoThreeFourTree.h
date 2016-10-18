#pragma once
#include "TwoThreeFourNode.h"
template<typename T>
class TwoThreeFourTree
{
private:
	int nbNodes;
	TwoThreeFourNode root;
public:
	Arbre();
	~Arbre();
	bool isEmpty() const;
	void addNode(const TwoThreeFourNode<T> &);
	Node removeNode(const TwoThreeFourNode<T> &);
	const T & max() const;
	const T & min() const;
	int getNbNodes() const;
	bool search(const T &) const;
};

template<typename T>
inline TwoThreeFourTree<T>::Arbre()
{
	root = NULL;
	nbNodes = 0;
}


template<typename T>
inline TwoThreeFourTree<T>::~Arbre()
{
}

template<typename T>
inline bool TwoThreeFourTree<T>::isEmpty() const
{
	return root == NULL;
}

template<typename T>
inline void TwoThreeFourTree<T>::addNode(const TwoThreeFourNode<T> & node)
{
	if (this->isEmpty()) { //Insert as root
		this->root = node;
	}
	else {
		//First we have to find where to insert the node
		TwoThreeFourNode<T> currentNode = this->root;
		if (currentNode.getChildren().size() == 4) {
			TwoThreeFourNode<T>* = currentNode.children.at(2);
			//TODO
		}
	}
}

template<typename T>
inline Node TwoThreeFourTree<T>::removeNode(const TwoThreeFourNode<T> & node)
{
	//C'est chaud aussi
	return Node();
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
	return 0;
}

template<typename T>
inline bool TwoThreeFourTree<T>::search(const T &) const
{
	return false;
}
