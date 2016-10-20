// Exercice2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LegoPart.h"
#include "TwoThreeFourTree.h"
#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <sstream>
#include <list>

using std::list;
using std::ifstream;
using std::stringstream;

const int MAX_CHARS_PER_LINE = 512;
const char* const DELIMITER = ",";

void parseText(TwoThreeFourTree<LegoPart> tree)
{
	/*
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
		std::cout << "new LegoPart added, loop iteration : " << n << std::endl;
		n++;
	}
	*/
	ifstream file("legoPieces.txt");
	string line;
	if (file)
	{
		string tempArray[10];
		string token;
		stringstream iss;
		while (getline(file, line))
		{
			iss << line;

			int i = 0;
			while (getline(iss, token, ','))
			{
				tempArray[i] = token;
				i++;
			}
			iss.clear();
		}
		string pieceId = tempArray[0];
		if (tempArray[1][0] == '"') {
			string tempString = tempArray[1];
			int n = 2;
			while (tempArray[n][tempArray[n].size()] != '"') {
				n++;
			}

		}
	}
}


int main()
{
	TwoThreeFourTree<LegoPart> treeTest = TwoThreeFourTree<LegoPart>();
	parseText(treeTest);


	system("pause");
    return 0;
}

