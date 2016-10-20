// Exercice2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LegoPart.h"
#include "TwoThreeFourTree.h"
#include <string>
#include <iostream>
#include <fstream>

using std::ifstream;
using std::cout;
using std::endl;
const int MAX_CHARS_PER_LINE = 512;
const char* const DELIMITER = ",";

void parseText(TwoThreeFourTree<LegoPart> tree)
{
	ifstream fin;
	fin.open("legoPieces.txt"); // open a file
	if (!fin.good()) {
		std::cout << "error, file not found" << std::endl; // exit if file not found
	}
	// read each line of the file
	
	//while (!fin.eof())
	//For testing purposes
	int n = 0;
	for (int i = 0; i < 2; i++) {
		char buf[MAX_CHARS_PER_LINE];
		fin.getline(buf, MAX_CHARS_PER_LINE);
	}
	while(n < 15)
	{
		// read an entire line into memory
		char buf[MAX_CHARS_PER_LINE];
		
		fin.getline(buf, MAX_CHARS_PER_LINE);

		const char* parseParts = strtok(buf, DELIMITER);
		string pieceId = parseParts;
		parseParts = strtok(NULL, DELIMITER);
		string description = parseParts;
		parseParts = strtok(NULL, DELIMITER);
		string category = parseParts;
		tree.insertValue(LegoPart(pieceId, description, category), tree.getRoot());
		n++;
	}
	cout << tree << endl << endl;

	/*Testing search*/
	LegoPart partToSearch = LegoPart("10019stk01", "Sticker for Set 10019 - (43274 / 4170393)", "Non - LEGO");

	TwoThreeFourNode<LegoPart>* nodeFound = tree.search(partToSearch,tree.getRoot());
	if (nodeFound != NULL) {
		for (LegoPart part : nodeFound->getKeys()) {
			cout << part.getPieceId() << " " << part.getCategory() << " " << part.getDescription() << endl << endl;
		}
	}

	/*Testing delete*/
	LegoPart partToDelete = LegoPart("10019stk01", "Sticker for Set 10019 - (43274 / 4170393)", "Non - LEGO");
	cout << "Attempting to remove : " << partToDelete << endl;
	tree.removeValue(partToDelete,tree.getRoot());
	cout << tree << endl << endl;
	partToDelete = LegoPart("0903", "Baseplate 16 x 24 with Set 080 Red House Print", "Baseplates");
	cout << "Attempting to remove : " << partToDelete << endl;
	tree.removeValue(partToDelete, tree.getRoot());
	cout << tree << endl << endl;


}


int main()
{
	TwoThreeFourTree<LegoPart> treeTest = TwoThreeFourTree<LegoPart>();
	parseText(treeTest);


	system("pause");
    return 0;
}

