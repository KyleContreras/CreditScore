#ifndef Credit_H
#define Credit_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Credit
{
	public:
		// Default constructor for Credit
		Credit();

		void compareMinScore(Credit record);
		void compareMaxScore(Credit record);

		// Return static min and max scores
		static int getMinScore();
		static int getMaxScore();
		static int getAvgScore();

		// Set static min and max scores
		// Practicing some overloaded functions
		static void setMinScore(Credit people[], int lastItem);
		static void setMinScore(int score);
		static void setMaxScore(Credit people[]);
		static void setMaxScore(int score);
		static void setAvgScore(Credit people[], int counter);

		// Overloaded << operator
		friend std::ostream& operator<<(ostream& out, const Credit& account);

		// Overloaded >> operator
		friend std::istream& operator>>(istream& in, Credit& account);

		// Overloaded > operator
		friend bool operator>(Credit account, Credit accountTwo);

		// Accessor functions for Credit's private variables
		string getLastName();
		string getFirstName();
		int getIncome();
		int getCreditScore();

		// Mutator functions for Credit's private variables
		void setLastName(string lName);
		void setFirstName(string fName);
		void setIncome(int earnedIncome);
		void setCreditScore(int credScore);

	private:
		string lastName;			// Person's last name
		string firstName;			// Person's first name
		int income;					// Person's income
		int creditScore;			// Person's credit score

		static int maxCreditScore;	// Overall maximum credit score
		static int minCreditScore;	// Overall minimum credit score
		static int avgCreditScore;	// Overall average credit score
};
#endif