#pragma once
#include "Node.h"
#include "Person.h"
#include <list>

class FamilyTree
{
private:
	Node<Person>* root;
	int nbNodes;
public:
	FamilyTree();
	FamilyTree(Node<Person>* root);
	virtual ~FamilyTree();
	bool isEmpty();
	bool isLeaf(Node<Person>* node); //Tells if a node is a Leaf
	int getSize(); //Returns the size (the number of nodes in the tree)
	int getHeight(Node<Person>* node); //Returns the height of a node, and the height of the tree if no argument is provided
	void attachMother(Node<Person>* node, Node<Person>* mother); //Adds a node to the tree as a Mother
	void attachFather(Node<Person>* node, Node<Person>* father); //Adds a node to the tree as a Father
	std::list<Node<Person>*> printLineage_inOrder(Node<Person>* node, Node<Person>* ancestor, std::list<Node<Person>*> list, bool* found); //Affiche la descendance d'un noeud
	std::list<Node<Person>*> printLineage_preOrder(Node<Person>* node, Node<Person>* ancestor, std::list<Node<Person>*> list, bool* found); //Affiche la descendance d'un noeud
	std::list<Node<Person>*> printLineage_postOrder(Node<Person>* node, Node<Person>* ancestor, std::list<Node<Person>*> list, bool* found); //Affiche la descendance d'un noeud
	void listSameEyeColor(Node<Person>* node, EyeColor color, std::list<Node<Person>*>* list);
	void listAllSameEyeColor(EyeColor color, std::list<Node<Person>*>* list);
	float getAverageAge(); //Returns the average age of all people in the tree
	int getSumOfAges(Node<Person>* node); //Returns the sum of the ages from a given node
};

