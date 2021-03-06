#pragma once
#include <string>
using std::string;

class LegoPart
{
public:
	LegoPart();
	LegoPart(string pieceId, string description, string category);
	~LegoPart();
	string getPieceId();
	string getDescription();
	string getCategory();
	void setPieceId(string newId);
	void setDescription(string newDescription);
	void setCategory(string newCategory);

private:
	string pieceId;
	string description;
	string category;
};

