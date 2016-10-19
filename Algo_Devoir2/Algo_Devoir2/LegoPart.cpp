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
