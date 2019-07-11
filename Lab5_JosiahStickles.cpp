/* Filename:  lab5_JosiahStickles.cpp
*
* Author:  Br. David Carlson
*
* Edited By: Josiah Stickles
*
* Date:  Jan 2, 2015
* Edited:Fed 26, 2016
*
* Description:  This program prompts the user to enter the data for one drug trial,
* places it into a Drug object, and then retrieves and prints this data.
*/

#include "drug.h"


int main(void)
{
	string junk;

	string DrugNameTemp;
	string TargetDiseaseTemp;
	int EffectivenessTemp;
	int ToxicityTemp;
	int ApprovedTemp;

	Drug DrugObject;


	// Prompt the user to enter the data for this new object. Read the values into the obvious variables.
	// The first one has been completed for you.
	cout << "Enter the name of the drug: ";
	getline(cin, DrugNameTemp);
	DrugObject.SetDrugName(DrugNameTemp);
	cout << "Enter the disease targeted by the drug: ";
	getline(cin, TargetDiseaseTemp);
	DrugObject.SetTargetDisease(TargetDiseaseTemp);
	cout << "Enter the effectiveness of the drug: ";
	cin >> EffectivenessTemp;
	DrugObject.SetEffectiveness(EffectivenessTemp);
	cout << "Enter the toxicity of the drug: ";
	cin >> ToxicityTemp;
	DrugObject.SetToxicity(ToxicityTemp);
	cout << "Was this drug approved? (1 for yes, 0 for no): ";
	cin >> ApprovedTemp;
	DrugObject.SetApproved(ApprovedTemp);

	// Print all of the data about this drug by retrieving the data using the get functions
	// from within the appropriate command(s) to print.  The first part of this has been done for you:
	cout << endl << "Drug name: " << DrugObject.GetDrugName() << endl;
	cout << "Target Disease: " << DrugObject.GetTargetDisease() << endl;
	cout << "Effectiveness: " << DrugObject.GetEffectiveness() << endl;
	cout << "Toxicity: " << DrugObject.GetToxicity() << endl;
	cout << "Approved: ";
	if (DrugObject.GetApproved() == 0)
		cout << "No";
	else
		cout << "Yes";
	cout << endl;

	getline(cin, junk, '\n');   // Clear the newline from the input buffer.
	cout << endl << "Press Enter" << endl;
	getline(cin, junk, '\n');   // Pause the screen for those running the program outside of Visual Studio.

	return 0;
}
