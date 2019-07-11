// This file implements the functions for the Drug class that is set up in drug.h.

#include "drug.h"

/* Given:  DrugNameValue - the string to place into the DrugName field
 *         TargetDiseaseValue - the string to place into the TargetDisease field
 *         EffectivenessValue -- the int to place into the Effectiveness field
 *         ToxicityValue -- the int to place into the Toxicity field
 *         ApprovedValue -- the int to place into the Approved field 
 * Task:   To construct a new Drug object containing the given data.
 * Return: Nothing, though the new object is created.
 */
Drug::Drug(string DrugNameValue, string TargetDiseaseValue,
         int EffectivenessValue, int ToxicityValue, int ApprovedValue)
   {
   DrugName = DrugNameValue;
   TargetDisease = TargetDiseaseValue;
   Effectiveness = EffectivenessValue;
   Toxicity = ToxicityValue;
   Approved = ApprovedValue;
   }

        
/* Given:  DrugNameValue - the string to be placed into the implicit object
 * Task:   To copy DrugNameValue into the DrugName field of the implicit object
 * Return: Nothing, though the implicit object is modified.
 */
void Drug::SetDrugName(string DrugNameValue)
   {
   DrugName = DrugNameValue;
   }


/* Given:  TargetDiseaseValue - the string to be placed into the implicit object
 * Task:   To copy TargetDiseaseValue into the TargetDisease field of the implicit object
 * Return: Nothing, though the implicit object is modified.
 */
void Drug::SetTargetDisease(string TargetDiseaseValue)
   {
   TargetDisease = TargetDiseaseValue;
   }


/* Given:  Effectiveness - the string to be placed into the implicit object
 * Task:   To copy EffectivenessValue into the Effectiveness field of the implicit object
 * Return: Nothing, though the implicit object is modified.
 */
void Drug::SetEffectiveness(int EffectivenessValue)
   {
   Effectiveness = EffectivenessValue;
   }


/* Given:  ToxicityValue - the string to be placed into the implicit object
 * Task:   To copy ToxicityValue into the Toxicity field of the implicit object
 * Return: Nothing, though the implicit object is modified.
 */
void Drug::SetToxicity(int ToxicityValue)
   {
   Toxicity = ToxicityValue;
   }


/* Given:  ApprovedValue - the string to be placed into the implicit object
 * Task:   To copy ApprovedValue into the Approved field of the implicit object
 * Return: Nothing, though the implicit object is modified.
 */
void Drug::SetApproved(int ApprovedValue)
   {
   Approved = ApprovedValue;
   }
   

/* Given:  Nothing, other than the implicit object
 * Task:   To look up the DrugName in the implicit object
 * Return: This DrugName string in the function name.
 */
string Drug::GetDrugName(void) const
   {
   return DrugName;
   }


/* Given:  Nothing, other than the implicit object
 * Task:   To look up the TargetDisease in the implicit object
 * Return: This TargetDisease string in the function name.
 */
string Drug::GetTargetDisease(void) const
   {
   return TargetDisease;
   }



/* Given:  Nothing, other than the implicit object
 * Task:   To look up the Effectiveness in the implicit object
 * Return: This Effectiveness int in the function name.
 */
int Drug::GetEffectiveness(void) const
   {
   return Effectiveness;
   }
   
   
/* Given:  Nothing, other than the implicit object
 * Task:   To look up the Toxicity in the implicit object
 * Return: This Toxicity int in the function name.
 */
int Drug::GetToxicity(void) const
   {
   return Toxicity;
   }
   
   
/* Given:  Nothing, other than the implicit object
 * Task:   To look up the Approved field in the implicit object
 * Return: This Approved int in the function name.
 */
int Drug::GetApproved(void) const
   {
   return Approved;
   }


/* Given:  OutputStream   An output file stream.
           DrugObj  An object of class Drug.
   Task:   To print the contents of DrugObj onto the OutputStream in a nicely formatted way.
   Return: The modified file stream is returned in the function name.
           This allows one to chain together more than one << operator as in:
		   cout << Drug1 << endl << Drug2 << endl;
*/
ostream & operator<<(ostream & OutputStream, const Drug & DrugObj)
   {
   OutputStream << setw(17) << "Drug name: " << DrugObj.DrugName << endl;
   OutputStream << setw(17) << "Target disease: " << DrugObj.TargetDisease << endl;
   OutputStream << setw(17) << "Effectiveness: " << DrugObj.Effectiveness << endl;
   OutputStream << setw(17) << "Toxicity: " << DrugObj.Toxicity << endl;
   if (DrugObj.Approved == 1)
      OutputStream << setw(17) << "Approved: " << "yes" << endl << endl;
   else
      OutputStream << setw(17) << "Approved: " << "no" << endl << endl;

   return OutputStream;
   }
