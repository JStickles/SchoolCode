//Josiah Stickle
//RomanNumeral.cpp - converts decimal numbers to roman numerals

#include <iostream>
#include <string>
using namespace std;



int main()
{
	int input;
	string romanNumeral = "";
	int numberEquivalent[7] = { 1000, 500, 100, 50, 10, 5, 1 };
	char numeralEquivalent[7] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };

	cout << "Input a number between 1 and 4999 to convert to a roman numeral" << endl;
	cin >> input;		//get the number from the user
	
	if (input > 4999)		//maxes the number size at 4999
	{
		cout << "That number is too large to convert\n";
		return 0;		//gives the user an error message, then ends the program
	}

	for (int i = 0; i < 7; i += 2)	//runs through the arrays picking numbers that are powers of 10
	{
		int numeralCount = input / numberEquivalent[i];		//finds how many times that power of 10 is in the number
		if (numeralCount == 4 && i > 0)		//this if statement for numerals that have the 1 before the 5
		{
			romanNumeral = romanNumeral + numeralEquivalent[i] + numeralEquivalent[i - 1];
		}
		else if (numeralCount == 9 && i >= 2) // this if statement is for numerals that have the 1 before the 10
		{
			romanNumeral = romanNumeral + numeralEquivalent[i] + numeralEquivalent[i - 2];
		}
		else //normal roman numerals
		{
			if (numeralCount >= 5)	//if the numeral has a 5 in it, uses the numeral that is 5 times higher
			{
				numeralCount = numeralCount - 5;
				romanNumeral = romanNumeral + numeralEquivalent[i - 1];
			}
			
			for (int j = 0; j < numeralCount; j++)	//if the numeral doesn't have a 5 here, only uses that numeral
			{
				romanNumeral = romanNumeral + numeralEquivalent[i];
			}
		}
		input = input % numberEquivalent[i];	//removes that power of 10 from the number
	}
	
	cout << romanNumeral <<endl;

	return 0;
}

