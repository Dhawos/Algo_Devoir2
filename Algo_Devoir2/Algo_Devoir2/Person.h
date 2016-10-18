#pragma once
#include <string>
using std::string;

enum EyeColor {
	brown,
	blue,
	green,
	gray
};

class Person
{
public:
	Person();
	Person(string lastName, string firstName, int birthYear, EyeColor eyecolor);
	virtual ~Person();
	string getLastName();
	string getFirstName();
	int getBirthYeah();
	EyeColor getEyeColor();
	bool operator==(const Person& p2)
	{
		return this->birthYear == p2.birthYear && this->eyeColor == p2.eyeColor && this->firstName == p2.firstName && this->lastName == p2.lastName;
	}
	friend std::ostream& operator<< (std::ostream&, const Person);
private:
	string lastName;
	string firstName;
	int birthYear;
	EyeColor eyeColor;
};

