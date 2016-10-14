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
	Person(string lastName, string firstName, int birthYear, EyeColor eyecolor);
	virtual ~Person();
	string getLastName();
	string getFirstName();
	int getBirthYeah();
	EyeColor getEyeColor();
private:
	string lastName;
	string firstName;
	int birthYear;
	EyeColor eyeColor;
};

