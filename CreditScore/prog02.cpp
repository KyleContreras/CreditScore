//Name: Kyle Contreras
//Program: CSC 275 Program 2
//Due Date: 25 Sept 2022
//Compiler: Microsoft C++ Compiler (MSVC)

#include <iostream>
#include <fstream>
#include <sstream>

#include "credit.h"

using namespace std;

// Declare sort
void sort(Credit A[], int count);

int main()
{
	Credit peopleInfo[30];   // Array of Credit objects read from 'creditPeople.txt'
	Credit account;			// Instance of Credit class
	int counter = 0;		// Counter for looping through peopleInfo array			
	ifstream fileToRead;    // Read stream variable
	Credit maxPerson;

	// Open file to read stream. I got the people info from the list you gave in the assignment page.
	fileToRead.open("CreditPeople.txt");

	// Convert each line of the file into a Credit object
	while (!fileToRead.eof())
	{
		fileToRead >> account;

		peopleInfo[counter] = account;

		counter++;
	}

	// Sort Objects by their creditScore property
	sort(peopleInfo, counter);

	// Set the max, min, and avg static scores
	Credit::setMaxScore(peopleInfo);
	Credit::setMinScore(peopleInfo, counter);
	Credit::setAvgScore(peopleInfo, counter);

	// Print out the people and their information
	for (int i = 0; i < counter; i++)
	{
		cout << peopleInfo[i];
	}

	// Print out the max, min, and avg static scores
	cout << "Maximum credit score: " << Credit::getMaxScore() << endl;
	cout << "Minimum credit score: " << Credit::getMinScore() << endl;
	cout << "The average credit score: " << Credit::getAvgScore() << endl;

}


// Define sorting alrogithm
void sort(Credit A[], int count) {
	int i, j;
	for (i = 1; i < count; i++)
	{
		for (j = i; (j > 0) && A[j].getCreditScore() > A[j - 1].getCreditScore(); j--)
		{
			swap(A[j], A[j - 1]);
		}
	}
}
