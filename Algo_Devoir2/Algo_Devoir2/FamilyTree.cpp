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
	if (node != NULL && node->getMother() == NULL && mother != NULL) {
		node->setMother(mother);
		this->nbNodes++;
	}
	else {
		throw std::invalid_argument("NULL pointer passed as argument");
	}
}

void FamilyTree::attachFather(Node<Person>* node, Node<Person>* father)
{
	if (node != NULL && node->getFather() == NULL && father != NULL) {
		node->setFather(father);
		this->nbNodes++;
	}
	else {
		throw std::invalid_argument("NULL pointer passed as argument");
	}
}

std::list<Node<Person>*> FamilyTree::printLineage_inOrder(Node<Person>* node, Node<Person>* ancestor, std::list<Node<Person>*>list, bool* found)
{
	if (node != NULL) {
		list = printLineage_inOrder(node->getFather(),ancestor,list, found);
		if (node->getData() == ancestor->getData()){
			*found = true;
		}
		if (!*found) {
			list = printLineage_inOrder(node->getMother(), ancestor, list,found);
		}
		if (*found) {
			list.push_back(node);
		}
	}
	return list;
}

std::list<Node<Person>*> FamilyTree::printLineage_preOrder(Node<Person>* node, Node<Person>* ancestor, std::list<Node<Person>*>list, bool* found)
{
	if (node != NULL) {
		if (node->getData() == ancestor->getData()) {
			*found = true;
		}
		if (!*found) {
			list = printLineage_preOrder(node->getFather(), ancestor, list, found);
		}
		if (!*found) {
			list = printLineage_preOrder(node->getMother(), ancestor, list, found);
		}
		if (*found) {
			list.push_back(node);
		}
	}
	return list;
}

std::list<Node<Person>*> FamilyTree::printLineage_postOrder(Node<Person>* node, Node<Person>* ancestor, std::list<Node<Person>*>list, bool* found)
{
	if (node != NULL) {
		if (!*found) {
			list = printLineage_preOrder(node->getFather(), ancestor, list, found);
		}
		if (!*found) {
			list = printLineage_preOrder(node->getMother(), ancestor, list, found);
		}
		if (node->getData() == ancestor->getData()) {
			*found = true;
		}
		if (*found) {
			list.push_back(node);
		}
	}
	return list;
}

void FamilyTree::listSameEyeColor(Node<Person>* node, EyeColor color, std::list<Node<Person>*>* list)
{
	if (node != NULL) {
		listSameEyeColor(node->getFather(), color, list);
		if (node->getData().getEyeColor() == color) {
			list->push_back(node);
		}
		listSameEyeColor(node->getMother(), color, list);
	}
	
}

void FamilyTree::listAllSameEyeColor(EyeColor color, std::list<Node<Person>*>* list)
{
	this->listSameEyeColor(this->root, color, list);

}

float FamilyTree::getAverageAge()
{
	int sum = getSumOfAges(this->root);
	return (float)sum / (float)this->getSize();
}

int FamilyTree::getSumOfAges(Node<Person>* node)
{
	if (node == NULL) {
		return 0;
	}
	else {
		return node->getData().getAge() + getSumOfAges(node->getFather()) + getSumOfAges(node->getMother());
	}
}


