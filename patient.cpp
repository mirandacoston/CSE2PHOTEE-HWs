
#include "patient.h"
#include <iostream>
#include <string>

using namespace std;

// Q1 Patient (2 points)
// Patient() constructor assigns the following default values to class data members
// name: abc
// age: 19
// DOByear: 2000
// ID: 0
Patient::Patient()
{
	name = "abc";
	age = 19;
	DOByear = 2000;
	ID = 0;
}
// Q2 (18 points)
// setName assigns 'name_input' to class data member 'name'
void Patient::setName(string name_input)
{
	this->name = name_input;
}
// setAge assigns age_input to class data member 'age'
void Patient::setAge(int age_input)
{
	this->age = age_input;
}
// setDOByear assigns 'DOByear_input' to class data member 'DOByear'
void Patient::setDOByear(int DOByear_input)
{
	this->DOByear = DOByear_input;
}
// setID assigns 'ID_input' to class data member 'ID'
void Patient::setID(int ID_input)
{
	this->ID = ID_input;
}
// displayPatients displays the name, age, year of birth and ID of the patient
void Patient::displayPatient()
{
	cout << "Name: "<< this->name << endl;
	cout << "Age: " << this->age << endl;
	cout << "Year of birth: " << this->DOByear << endl;
	cout << "ID: " << this->ID << endl;
}
// getName returns the class data member 'name'.
string Patient::getName()
{
	return this->name;
}

// getAge returns the class data member 'age'.
int Patient::getAge()
{
	return this->age;
}

// getDOByear returns the class data member 'DOByear'.
int Patient::getDOByear()
{
	return this->DOByear;
}

// getID returns the class data member 'ID'.
int Patient::getID()
{
	return this->ID;
}
