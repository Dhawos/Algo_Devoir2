#pragma once
#include <string>
#include <ctime>
using std::string;
using std::time;

enum EyeColor {
	brown,
	blue,
	green,
	gray
};
class Person
{
public:
	Person(string lastName, string firstName, int birthYear, EyeColor eyecolor);
	virtual ~Person();
	string getLastName();
	string getFirstName();
	int getBirthYeah();
	EyeColor getEyeColor();
	int getAge();
	bool operator==(const Person& p2)
	{
		return this->birthYear == p2.birthYear && this->eyeColor == p2.eyeColor && this->firstName == p2.firstName && this->lastName == p2.lastName;
	}
private:
	string lastName;
	string firstName;
	int birthYear;
	EyeColor eyeColor;
};

