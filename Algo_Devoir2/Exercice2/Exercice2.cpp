// Exercice2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LegoPart.h"
#include "TwoThreeFourTree.h"
#include <string>
#include <iostream>
#include <fstream>

using std::ifstream;

const int MAX_CHARS_PER_LINE = 512;
const char* const DELIMITER = ",";

void parseText(TwoThreeFourTree<LegoPart> tree)
{
	ifstream fin;
	fin.open("legoPieces.txt"); // open a file
	if (!fin.good())
		std::cout << "error, file not found" << std::endl; // exit if file not found

	// read each line of the file
	//while (!fin.eof())
	//For testing purposes
	int n = 0;
	while(n < 10)
	{
		// read an entire line into memory
		char buf[MAX_CHARS_PER_LINE];
		fin.getline(buf, MAX_CHARS_PER_LINE);

		const char* parseParts = strtok(buf, DELIMITER);
		string pieceId = parseParts;
		string description = parseParts;
		string category = parseParts;
		tree.insertValue(LegoPart(pieceId, description, category));
		n++;
	}
}


int main()
{
	TwoThreeFourTree<LegoPart> treeTest = TwoThreeFourTree<LegoPart>();
	parseText(treeTest);


	system("pause");
    return 0;
}

