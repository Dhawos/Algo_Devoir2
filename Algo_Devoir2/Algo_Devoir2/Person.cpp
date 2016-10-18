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

std::ostream & operator<<(std::ostream & stream, const Person person)
{
	stream << "Last Name : " << person.lastName << " -- First Name : " << person.firstName << " -- Year of birth : " << person.birthYear << " -- Eye Color : " << person.eyeColor << std::endl;
	return stream;
}
