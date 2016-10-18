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

std::ostream & operator<<(std::ostream & stream, const Person person)
{
	stream << " Last name : " << person.lastName << " -- First name : " << person.firstName << " -- Year of Birth : " << person.birthYear << " -- Eye color : ";
		if (person.eyeColor == 0) {
			stream << "brown";
		}
		if (person.eyeColor == 1) {
			stream << "blue";
		}
		if (person.eyeColor == 2) {
			stream << "green";
		}
		if (person.eyeColor == 3) {
			stream << "gray";
		}
		stream << std::endl;
	return stream;
}
