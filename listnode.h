/* Filename:  listnode.h

   Programmer:  Br. David Carlson

   Date:  October 7, 1997

   Modified:  August 8, 1998

   Modified:  June 27, 2000

   This is the header file to accompany listnode.cpp.  These 2 files
   provide ListNodeClass as shown below.  Also provided is the
   ListNodePtr type.
*/

#include "itemtype.h"


class ListNodeClass
   {
   private:
      ItemType Info;
      ListNodeClass * Next;
   public:
      // First, the constructor:
      ListNodeClass(const ItemType & Item, ListNodeClass * NextPtr = NULL):
         Info(Item), Next(NextPtr)
            {
            };
      void GetInfo(ItemType & TheInfo) const;
   friend class ListClass;   // very convenient to allow this
   };

typedef ListNodeClass * ListNodePtr;

