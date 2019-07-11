/*
File Name: Homework6_JosiahStickles.cpp

Author: Josiah Stickles

Date: 2/24/2016

Modified: 4/17/2016

This program asks the user to enter the name of a binary file and reads a list of drugs from the binary
file and stores them in a linked list of drug objects.

For each drug the program asks the user to make
a decision whether to approve it for further development. It then allows the user to interactively print
the drug data or search through the drug data
based on disease or a range of effectiveness repeatedly.
*/

#include "list.h"

#include <fstream>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

typedef struct
{
	char DrugName[32];
	char TargetDisease[32];
	int Effectiveness;
	int Toxicity;
} drugStructure;

void readData(fstream & inStream, ListClass & DrugList);
bool userDecision(Drug singleDrug);
void searchOrPrint(ListClass & DrugList); 
void search(ListClass & DrugList);


int main()
{
	ListClass DrugList;
	fstream inStream;
	string fileName;
	int recordSize;
	int numberOfDrugs;
	cout << "Enter the name of your data file for drug trial information: ";
	getline(cin, fileName);
	inStream.open(fileName, ios::in | ios::binary);
	if (inStream.fail())
	{
		cout << "Could not open the file." << endl;
		system("pause > nul");
		delete &DrugList;
		exit(1);
	}

	inStream.seekg(0L, ios::end);   // Go to the end of the file, zero bytes after the end.
	recordSize = sizeof(drugStructure);
	numberOfDrugs = inStream.tellg() / recordSize;
	inStream.seekg(0L, ios::beg);   // Return to start of the file so we can read it from the beginning.
	
	readData(inStream, DrugList);
	inStream.close();
	searchOrPrint(DrugList);
	return 0;
}


/*
Given: inStream -- An ifsteam object that is opened into a binary file constaining drug data
Task: Read in an list of drugs from the binary file that inStream is opened to
		and store it in a linked list of drug objects
Return: DrugList -- A linked list of drug objects containing the drug data that has been read in
*/
void readData(fstream & inStream, ListClass & DrugList)
{
	drugStructure tempDrug;
	int drugSize;
	Drug newDrug;

	drugSize = sizeof(tempDrug);

	inStream.read(reinterpret_cast <char *> (&tempDrug), drugSize);

	while (!inStream.fail()) 
												  
	{
		newDrug.SetDrugName(tempDrug.DrugName);
		newDrug.SetTargetDisease(tempDrug.TargetDisease);
		newDrug.SetEffectiveness(tempDrug.Effectiveness);
		newDrug.SetToxicity(tempDrug.Toxicity);
		newDrug.SetApproved(userDecision(newDrug));

		DrugList.InsertRear(newDrug);

		
		inStream.read(reinterpret_cast <char *> (&tempDrug), sizeof(tempDrug));
	}
} 


/*
Given: singleDrug - a single drug object
Task: Ask the user whether the item should be used in futher developments
Return: A boolean holding the user's decision is returned through the function name
*/
bool userDecision(Drug singleDrug)
{
	int decision;

	cout.setf(ios::left);		//makes cout left justified
	cout << endl;
	cout.width(18);
	cout << "Drug name:";
	cout << singleDrug.GetDrugName() << endl;
	cout.width(18);
	cout << "Target disease:";
	cout << singleDrug.GetTargetDisease() << endl;
	cout.width(18);
	cout << "Effectiveness:";
	cout << singleDrug.GetEffectiveness() << endl;
	cout.width(18);
	cout << "Toxicity:";
	cout << singleDrug.GetToxicity() << endl << endl;

	cout << "Enter the decision whether to approve this drug for futher development" << endl;
	cout << "(0 = No, 1 = Yes): ";
	cin >> decision;
	if (decision == 1)
		return 1;
	else
		return 0;
}


/*
Given: DrugList - A linked list of drug objects
Task: Repeatedly ask the user whether they want to print the array, search the array, or quit
Return: None
*/
void searchOrPrint(ListClass & DrugList)
{
	int choice = 0;
	while (choice != 3)
	{
		cout << endl;
		cout << "Menu of options:" << endl << endl;
		cout << "1) Print all of the drug trial data" << endl;
		cout << "2) Search for drugs that fit a certain target disease or effectiveness range" << endl << endl;
		cout << "3) Quit the program" << endl << endl;
		cout << "Enter the number for you choice: ";
		cin >> choice;
		while (choice != 1 && choice != 2 && choice != 3) //*** Good input checking
		{
			cout << endl << choice << " is not a valid choice. Use 1, 2, or 3 only";

			cout << endl << endl;
			cout << "Menu of options:" << endl << endl;
			cout << "1) Print all of the drug trial data" << endl;
			cout << "2) Search for drugs that fit a certain target disease or effectiveness range" << endl << endl;
			cout << "3) Quit the program" << endl << endl;
			cout << "Enter the number for you choice: ";
			cin >> choice;
		}

		if (choice == 1)
		{
			DrugList.print(cout);
		}
		else if (choice == 2)
		{
			search(DrugList);
		}
	}
}


/*
Given: DrugList -- A linked list of drug object
Task: search the array for every drug that meets criteria inputed by the user with regards
		to the diseas, minimum effectiveness, and maximum effectiveness and prints them out
		as it finds them.
Return: None
   */
void search(ListClass & DrugList)
{
	string junk;
	string disease;
	int minEffectiveness;
	int maxEffectiveness;

	cout << endl;
	cout << "First you must specify the target disease." << endl;
	cout << "You may enter ALL to avoid retricting the results by target disease." << endl << endl;
	cout << "Desired target disease (or ALL): ";
	getline(cin, junk);
	getline(cin, disease);

	cout << endl;
	cout << "Next you need to specify the effectiveness range (using numbers from 0 to 100" << endl;
	cout << "You may use a range of 0 to 100 to avoid restricting results by effectiveness." << endl << endl;
	cout << "Enter the lowest effectiveness rating desired for this search: ";
	cin >> minEffectiveness;
	cout << endl;
	cout << "Enter the highest effectiveness rating desired for this search: ";
	cin >> maxEffectiveness;

	DrugList.search(disease, minEffectiveness, maxEffectiveness);
}