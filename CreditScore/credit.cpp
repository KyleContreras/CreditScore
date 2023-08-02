#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "credit.h"

using namespace std;

// initializing private static variables
int Credit::maxCreditScore = 0;
int Credit::minCreditScore = 0;
int Credit::avgCreditScore = 0;

// Default constructor
Credit::Credit()
{
	lastName = "J";
	firstName = "Doe";
	income = 0;
	creditScore = 0;
}


// Checks to see if the Credit instance has a lower credit score than minCreditScore
// Changes minCreditScore if necessary
void Credit::compareMinScore(Credit record)
{
	int score = record.getCreditScore();
	int currentMin = record.getMinScore();

	if (score < currentMin)
	{
		record.setMinScore(score);
		cout << "The new min score is: " << score << endl;
	}
	else
	{
		cout << "The score of " << score << " is not less than " << currentMin << endl;
	}
}

// Checks to see if the Credit instance has a higher credit score than maxCreditScore
// Changes maxCreditScore if necessary
void Credit::compareMaxScore(Credit record)
{
	int score = record.getCreditScore();
	int currentMax = record.getMaxScore();

	if (score > currentMax)
	{
		record.setMaxScore(score);
		cout << "The new max score is: " << score << endl;
	}
	else
	{
		cout << "The score of " << score << " is not greater than " << currentMax << endl;
	}
}

// Returns minCreditScore
int Credit::getMinScore()
{
	return Credit::minCreditScore;
}
// Returns maxCreditScore
int Credit::getMaxScore()
{
	return Credit::maxCreditScore;
}
// Returns avgCreditScore
int Credit::getAvgScore()
{
	return Credit::avgCreditScore;
}

// Overloaded - Sets minCreditScore
void Credit::setMinScore(Credit people[], int lastItem)
{
		int lastThing = lastItem - 1;
	Credit::minCreditScore = people[lastThing].getCreditScore();
}
// Overloaded - Sets minCreditScore
void Credit::setMinScore(int score)
{
	Credit::minCreditScore = score;
}

// Overloaded - Sets maxCreditScore
void Credit::setMaxScore(Credit people[])
{
	int lowestScore = people[0].getCreditScore();
	Credit::maxCreditScore = people[0].getCreditScore();
}
// Overloaded - Sets maxCreditScore
void Credit::setMaxScore(int score)
{
	Credit::maxCreditScore = score;
}

// Sets avgCreditScore
void Credit::setAvgScore(Credit people[], int counter)
{
	int overallTotal = 0;
	int lastThing = counter - 1;

	for (int i = 0; i < lastThing; i++)
	{
		overallTotal += people[i].getCreditScore();
	}

	Credit::avgCreditScore = overallTotal / lastThing;
}

// Overloaded << operator to write Credit objects to console
std::ostream& operator<<(ostream& out, const Credit& account)
{
	out << account.lastName << ", " << account.firstName << ", " << "$" << account.income << ", " "credit score: " << account.creditScore << endl;
	out << endl;

	return out;
}

// Overloaded >> operator to create Credit objects from text file
std::istream& operator>>(istream& in, Credit& account)
{
	in >> account.lastName >> account.firstName >> account.income >> account.creditScore;
	cout << endl;
	
	return in;
}

// Overloaded > operator
bool operator>(Credit account, Credit accountTwo)
{
	return account.getCreditScore() > accountTwo.getCreditScore();
}

// Accessor functions for Credit's private variables
string Credit::getLastName()
{
	return lastName;
}
string Credit::getFirstName()
{
	return firstName;
}
int Credit::getIncome()
{
	return income;
}
int Credit::getCreditScore()
{
	return creditScore;
}

// Mutator functions for Credit's private variables
void Credit::setLastName(string lName)
{
	lastName = lName;
}
void Credit::setFirstName(string fName)
{
	firstName = fName;
}
void Credit::setIncome(int earnedIncome)
{
	income = earnedIncome;
}
void Credit::setCreditScore(int credScore)
{
	creditScore = credScore;
}