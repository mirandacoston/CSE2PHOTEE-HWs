// CSE240 Spring A
// @author Miranda Coston, Acuna
// @version 1.22
// Compiler used: Visual studio
#include "patient.h"
#include <iostream>
#include <string>
#define MAX_PATIENTS 5
using namespace std;
// forward declaration of functions (already implemented)
void executeAction(char);
int addPatient(string name_input, int age_input, int DOByear_input, int
	ID_input); // 10 points
void displayPatients(); // 5 points
void sort(); // 10 points
void oldestPatient(); // 5 points
Patient s[MAX_PATIENTS]; // array of objects
int currentCount = 0; // number of patients in the list
int main()
{
	char choice = 'i'; // initialized to a dummy value
	do
	{
		cout << "\nCSE240 HW06\n";
		cout << "Please select an action:\n";
		cout << "\t a: add a new patient\n";
		cout << "\t d: display patient list\n";
		cout << "\t s: sort the patients in descending order based on age (within a range)\n";
		cout << "\t n: display the oldest patient whose name starts with a specific letter\n";
		cout << "\t q: quit\n";
		cin >> choice;
		cin.ignore(); // ignores the trailing \n
		executeAction(choice);
	} while (choice != 'q');
	return 0;
}
// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
	string name_input;
	int age_input, DOByear_input, ID_input, result, upperbound, lowerbound = 0;
	switch (c)
	{
	case 'a': // add patient
	// input patient details from user
		cout << "Please enter patient name: ";
		getline(cin, name_input);
		cout << "Please enter age: ";
		cin >> age_input;
		cin.ignore();
		cout << "Please enter year of birth: ";
		cin >> DOByear_input;
		cin.ignore();
		cout << "Please enter ID: ";
		cin >> ID_input;
		cin.ignore();
		// add the patient to the list
		result = addPatient(name_input, age_input, DOByear_input, ID_input);
		if (result == 0)
			cout << "\nThat patient is already in the list or list is full! \n\n";
		else
			cout << "\nPatient successfully added to the list! \n\n";
		break;
	case 'd': // display the list
		displayPatients();
		break;
	case 's': // sort the list
		sort();
		break;
	case 'n': // find and display oldestt patient
		oldestPatient();
		break;
	case 'q': // quit
		break;
	default: cout << c << " is invalid input!\n";
	}
}
int addPatient(string name_input, int age_input, int DOByear_input, int ID_input)
{
	int gtg = 0;
	Patient newP;
	newP.setName(name_input);
	newP.setAge(age_input);
	newP.setDOByear(DOByear_input);
	newP.setID(ID_input);
	if (currentCount < MAX_PATIENTS) {
		for (int i = 0;i < currentCount;i++) //loop to check if patient already exists in array;
		{
			if ((s[i].getName() == name_input) && (s[i].getAge() == age_input) && (s[i].getDOByear() == DOByear_input) && (s[i].getID() == ID_input))
			{
				gtg = 1;
			}
		}
		if (gtg == 0) {
			s[currentCount+1] = newP;
			currentCount++;
			return 1;
		} return 0;
	} return 0;
}
// Q4 displayPatients (5 points)
void displayPatients()
{
	for (int i = 0;i < currentCount;i++)
	{
		s[i].displayPatient();
		cout << endl;
	}
}
// Q5 sort (10 points)
// This function sorts the patients in descending order of age within a given range and then displays them
void sort()
{
	int upperbound, lowerbound;
	cout << "\nPlease enter an upper age bound: ";
	cin>> upperbound;
	cout << "\nPlease enter a lower age bound: ";
	cin >> lowerbound;
	Patient temp;
	for (int step = 0;step < currentCount; ++step) { //loop to access each patient
		for (int i = 0; i < currentCount - step;++i) { //loop to compare each patient
			if (s[i].getAge() < s[i + 1].getAge()) { //compare adjacent patients
				temp = s[i];						//swap patient array positions if out of order
				s[i] = s[i + 1];
				s[i + 1] = temp;
			}
		}
	}
	for (int i = 0;i < currentCount;i++)
	{
		if (s[i].getAge() >= upperbound && s[i].getAge() <= lowerbound)
		{
			s[i].displayPatient();
			cout << endl;
		}
	}
}
// Q6 oldestPatient (5 points)
	void oldestPatient()
{
	char startingCharacter; // Ask the user for a character
	cout << "\nEnter specific starting character: " << endl;
	cin >> startingCharacter;
	Patient* newPatient = new Patient;
	if (currentCount == 0) {
		cout << "This patient list is empty." << endl;
	}else if (currentCount > 0) {
		sort(); 
	} else {
		for (int i = 0;i < currentCount;i++) {
			if (s[i].getName().at(0) == startingCharacter) {
				newPatient->setName(s[i].getName());
				newPatient->setAge(s[i].getAge());
				newPatient->setDOByear(s[i].getDOByear());
				newPatient->setID(s[i].getID());
				newPatient->displayPatient();
			}
		} delete newPatient;
	}
}
