// Algo_Devoir2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Person.h"
#include "FamilyTree.h"
#include "Node.h"
using std::cout;
using std::endl;

int main()
{

	Person pA = Person("aaa", "aaa", 1990, blue);
	Person pB = Person("bbb", "bbb", 1991, green);
	Person pC = Person("ccc", "ccc", 1992, brown);
	Person pD = Person("ddd", "ddd", 1993, blue);
	Person pE = Person("eee", "eee", 1994, blue);
	Person pF = Person("fff", "fff", 1995, gray);
	Person pG = Person("ggg", "ggg", 1996, brown);
	Person pH = Person("hhh", "hhh", 1997, blue);
	Person pI = Person("iii", "iii", 1998, brown);
	Person pJ = Person("jjj", "jjj", 1999, blue);
	Person pK = Person("kkk", "kkk", 2000, brown);
	Person pL = Person("lll", "lll", 2001, blue);

	Node<Person> A = Node<Person>(pA);
	Node<Person> B = Node<Person>(pB);
	Node<Person> C = Node<Person>(pC);
	Node<Person> D = Node<Person>(pD);
	Node<Person> E = Node<Person>(pE);
	Node<Person> F = Node<Person>(pF);
	Node<Person> G = Node<Person>(pG);
	Node<Person> H = Node<Person>(pH);
	Node<Person> I = Node<Person>(pI);
	Node<Person> J = Node<Person>(pJ);
	Node<Person> K = Node<Person>(pK);
	Node<Person> L = Node<Person>(pL);

	FamilyTree familyTree01 = FamilyTree(&A);
	familyTree01.attachFather(&A, &B);
	familyTree01.attachFather(&B, &C);
	familyTree01.attachFather(&C, &D);
	familyTree01.attachMother(&C, &E);
	familyTree01.attachMother(&B, &F);
	familyTree01.attachFather(&F, &G);
	familyTree01.attachMother(&F, &H);
	familyTree01.attachMother(&A, &I);
	familyTree01.attachFather(&I, &J);
	familyTree01.attachFather(&J, &K);
	familyTree01.attachMother(&J, &L);

	std::list<Node<Person>*> inorderList = std::list<Node<Person>*>();
	std::list<Node<Person>*> preOrderList = std::list<Node<Person>*>();
	std::list<Node<Person>*> postOrderList = std::list<Node<Person>*>();
	bool found = false;
	inorderList = familyTree01.printLineage_inOrder(&A, &G, inorderList, &found);
	found = false;
	preOrderList = familyTree01.printLineage_preOrder(&A, &G, preOrderList, &found);
	found = false;
	postOrderList = familyTree01.printLineage_postOrder(&A, &G, postOrderList, &found);
	
	std::cout << "inOrder Test" << std::endl;
	for(Node<Person>* person : inorderList)
	{
		std::cout << *person << std::endl;
	}

	std::cout << "---------------------" << std::endl;
	std::cout << "preOrder Test" << std::endl;
	for (Node<Person>* person : preOrderList)
	{
		std::cout << *person << std::endl;
	}

	std::cout << "---------------------" << std::endl;
	std::cout << "postOrder Test" << std::endl;
	for (Node<Person>* person : postOrderList)
	{
		std::cout << *person << std::endl;
	}

	std::cout << "---------------------" << std::endl;
	std::cout << "Average Age Test" << std::endl;
	std::cout << "average Age : " << familyTree01.getAverageAge() << std::endl;

	std::cout << "---------------------" << std::endl;
	std::cout << "list Eye Color Test" << std::endl;
	std::list<Node<Person>*> listEyeColor = std::list<Node<Person>*>();
	familyTree01.listSameEyeColor(&B, blue, &listEyeColor);
	std::cout << "ancestors of " << B << " with the color blue" << std::endl;
	for (Node<Person>* person : listEyeColor)
	{
		std::cout << *person << std::endl;
	}

	std::cout << "---------------------" << std::endl;
	std::cout << "list All Same Eye Color Test" << std::endl;
	std::list<Node<Person>*> listAllSameEyeColor = std::list<Node<Person>*>();
	familyTree01.listAllSameEyeColor(brown, &listAllSameEyeColor);
	std::cout << "persons in the family tree with the color brown" << std::endl;
	for (Node<Person>* person : listAllSameEyeColor)
	{
		std::cout << *person << std::endl;
	}
	system("pause");
    return 0;
}

