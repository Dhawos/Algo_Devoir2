#include "stdafx.h"
#include "LegoPart.h"


LegoPart::LegoPart()
{
}

LegoPart::LegoPart(string pieceId, string description, string category)
{
	this->pieceId = pieceId;
	this->description = description;
	this->category = category;
}


LegoPart::~LegoPart()
{
}

string LegoPart::getPieceId()
{
	return this->pieceId;
}

string LegoPart::getDescription()
{
	return this->description;
}

string LegoPart::getCategory()
{
	return this->category;
}

void LegoPart::setPieceId(string newId)
{
	this->pieceId = newId;
}

void LegoPart::setDescription(string newDescription)
{
	this->description = newDescription;
}

void LegoPart::setCategory(string newCategory)
{
	this->category = newCategory;
}

bool & LegoPart::operator<(LegoPart legoPart)
{
	bool answer = this->pieceId < legoPart.pieceId;
	return answer;
}

bool & LegoPart::operator>(LegoPart legoPart)
{
	bool answer = this->pieceId > legoPart.pieceId;
	return answer;
}

bool & LegoPart::operator==(LegoPart legoPart)
{
	bool answer = false;
	if (this->pieceId == legoPart.pieceId) {
		answer = true;
	}
	return answer;
}
