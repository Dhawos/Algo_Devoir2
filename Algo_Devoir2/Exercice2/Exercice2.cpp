// Exercice2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LegoPart.h"
#include "TwoThreeFourTree.h"
#include "RNTree.h"
#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <sstream>
#include <regex>

using std::ifstream;
using std::stringstream;
using std::regex_search;


TwoThreeFourTree<LegoPart> parseText(TwoThreeFourTree<LegoPart>& tree, int nbPieces)
{
	ifstream file("legoPieces.txt");
	string line;
	if (file)
	{
		int n = 0;
		if (nbPieces == 0) {
			n = -1;
		}
		bool isFirst = true;
		while (getline(file, line) && n < nbPieces)
		{
			std::cout << n << std::endl;
			if (isFirst) {
				isFirst = false;
				getline(file, line);
				getline(file, line);
			}
			
			std::regex rgx("^((([^\",]*)|(\"[^\"]*\")),){2}(([^\",]*)|(\"[^\"]*\"))$");
			std::smatch match;

			std::cout << line << std::endl;
			if (std::regex_search(line, match, rgx)) {
				string pieceId;
				string description = match[2];
				string category = match[5];
				string resizelineToPieceId = match[0];
				resizelineToPieceId.resize(resizelineToPieceId.size() - description.size() - category.size() - 2);
				pieceId = resizelineToPieceId;

				if (pieceId[0] == '"') {
					pieceId = pieceId.substr(1, pieceId.size() - 2);
				}
				if (description[0] == '"') {
					description = description.substr(1, description.size() - 2);
				}
				if (category[0] == '"') {
					category = category.substr(1, category.size() - 2);
				}

				std::cout << "pieceId : " << pieceId << std::endl;
				std::cout << "description : " << description << std::endl;
				std::cout << "category : " << category << std::endl;
				tree.insertValue(LegoPart(pieceId, description, category), tree.getRoot());
			}
			std::cout << "-------------------" << std::endl;
			if (nbPieces != 0) {
				n++;
			}
		}
	}
	return tree;
		
}


int main()
{
	TwoThreeFourTree<LegoPart> treeTest =TwoThreeFourTree<LegoPart>();

	string input;
	int nbPieces;
	bool answered = false;
	while (!answered) {
		std::cout << "how many pieces do you want to load in the tree ?" << std::endl;
		std::cout << "if 0 then all pieces will be loaded" << std::endl;
		std::getline(std::cin, input);
		try {
			nbPieces = std::stoi(input);
			if (nbPieces >= 0 && nbPieces <= 20944) {
				answered = true;
			}
			else {
				std::cout << "Please enter an integer between 0 and 20944 (which is the maximum minus 1)" << std::endl;
			}
		}
		catch (...) {
			std::cout << "Please enter an integer between 0 and 20944 (which is the maximum minus 1)" << std::endl;
		}
	}
	std::cout << "you chose " << nbPieces << " pieces to be loaded" << std::endl;


	treeTest = parseText(treeTest, nbPieces);

	std::cout << treeTest << std::endl;

	RNTree<LegoPart> rnTree = RNTree<LegoPart>(treeTest);
	std::cout << rnTree << std::endl;

	TwoThreeFourTree<LegoPart> newTree = TwoThreeFourTree<LegoPart>(rnTree);
	std::cout << newTree << std::endl;
	system("pause");
    return 0;
}

