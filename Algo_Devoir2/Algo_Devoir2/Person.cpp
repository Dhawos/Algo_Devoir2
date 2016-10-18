#include "stdafx.h"
#include "Person.h"


Person::Person()
{
}

Person::Person(string lastName, string firstName, int birthYear, EyeColor eyecolor)
{
	this->lastName = lastName;
	this->firstName = firstName;
	this->birthYear = birthYear;
	this->eyeColor = eyecolor;
}


Person::~Person()
{
}

string Person::getLastName() {
	return this->lastName;
}

string Person::getFirstName() {
	return this->firstName;
}

int Person::getBirthYeah() {
	return this->birthYear;
}

EyeColor Person::getEyeColor() {
	return this->eyeColor;
}

int Person::getAge()
{
	time_t curTime = time(NULL);
	struct tm timeinfo;
	localtime_s(&timeinfo, &curTime);
	int year = timeinfo.tm_year + 1900;
	return year - birthYear;
}
