#include "stdafx.h"
#include "FamilyTree.h"
#include <algorithm>


FamilyTree::FamilyTree()
{
	this->root = NULL;
	this->nbNodes = 0;
}

FamilyTree::FamilyTree(Node<Person>* root)
{
	this->root = root;
	this->nbNodes = 0;
}


FamilyTree::~FamilyTree()
{
}

bool FamilyTree::isEmpty()
{
	return (this->root==NULL);
}

bool FamilyTree::isLeaf(Node<Person>* node)
{
	if (node != NULL) {
		return (node->getFather() == NULL && node->getMother() == NULL);		
	}
	else {
		throw std::invalid_argument("NULL pointer passed as argument");
	}
}

int FamilyTree::getSize()
{
	return nbNodes;
}

int FamilyTree::getHeight(Node<Person>* node)
{
	if (node == NULL) {
		return 0;
	}
	else {
		return 1 + std::max(getHeight(node->getFather()), getHeight(node->getMother()));
	}
}

void FamilyTree::attachMother(Node<Person>* node, Node<Person>* mother)
{
	if (node != NULL && mother !=NULL) {
		node->setMother(mother);
		this->nbNodes++;
	}
	else {
		throw std::invalid_argument("NULL pointer passed as argument");
	}
}

void FamilyTree::attachFather(Node<Person>* node, Node<Person>* father)
{
	if (node != NULL && father == NULL) {
		node->setMother(father);
		this->nbNodes++;
	}
	else {
		throw std::invalid_argument("NULL pointer passed as argument");
	}
}

void FamilyTree::printLineage_inOrder(Node<Person>* node, Node<Person>* ancestor)
{
	if (node != NULL) {
		std::stack<Node<Person>*> stack = std::stack<Node<Person>*>();
		bool found = false;
		stack.push(node);
		printLineage_inOrder(node->getFather(),ancestor);
		if (node->getData() == ancestor->getData()) {
			found = true;
		}
		printLineage_inOrder(node->getMother(),ancestor);
	}
}



