/* Filename: listnode.cpp

   Programmer:  Br. David Carlson

   Date:  October 7, 1997

   Modified:  August 8, 1998.

   This file implements the class functions for the ListNodeClass, which
   is declared in listnode.h.  Since no code is needed for the
   constructor, only the GetInfo function is found here.
*/

#include "listnode.h"


/* Given:  Nothing other than the implicit object.
   Task:   To look up the Info field of the object.
   Return: A copy of this data in TheInfo.
*/
void ListNodeClass::GetInfo(ItemType & TheInfo) const
   {
   TheInfo = Info;   // assumes assignment works on this type
   }

