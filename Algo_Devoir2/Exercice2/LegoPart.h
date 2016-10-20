#pragma once
#include <string>
#include <iostream>
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
	bool operator< (LegoPart legoPart);
	bool operator>(LegoPart legoPart);
	bool operator>=(LegoPart legoPart);
	bool operator==(LegoPart legoPart);
	friend std::ostream& operator<< (std::ostream&, const LegoPart);
private:
	string pieceId;
	string description;
	string category;
};

