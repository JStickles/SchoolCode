// The file provides the declaration of the class Drug.

#include <iostream>
#include <iomanip>   // Added so that setw, etc. can be used.
#include <string>

using namespace std;

class Drug
   {
   private:
      // The 5 private fields of data about a particular drug:
      string DrugName;
      string TargetDisease;
      int Effectiveness;
      int Toxicity;
      int Approved;

   public:
      friend ostream & operator<<(ostream & OutputStream, const Drug & DrugObj);

      // Default constructor:
      Drug(string DrugNameValue = "", string TargetDiseaseValue = "",
         int EffectivenessValue = 0, int ToxicityValue = 0, int ApprovedValue = 0);

      // The 5 set functions:
      void SetDrugName(string DrugNameValue);
      void SetTargetDisease(string TargetDiseaseValue);
      void SetEffectiveness(int EffectivenessValue);
      void SetToxicity(int ToxicityValue);
      void SetApproved(int ApprovedValue);

      // The 5 get functions:
      string GetDrugName(void) const;
      string GetTargetDisease(void) const;    
      int GetEffectiveness(void) const;
      int GetToxicity(void) const;      
      int GetApproved(void) const;
   };
