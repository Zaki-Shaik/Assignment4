// book.h
// Definition of class Book

#ifndef BOOK_H
#define BOOK_H


#include "libraryitem.h"

using namespace std;

//---------------------------------------------------------------------------
// Book: 
//
//  Implementation:
//
//  -- Implements a Book ADT as a LibraryItem derived class
//  -- All other forms of books (Fiction, Children, EBook) derive from it
//  -- Specific attribute: author
//  -- Other fields: title, year inherited from base class
//
//  Assumptions:
//
//  -- Data Extensibility is modeled through "attributes" list inherited from
//  -- LibraryItem base class
//

class Book : public LibraryItem
{

public:
  //  Book();  // Class default constructor
   //virtual ~Book(); // Class destructor
  // virtual LibraryItem* createIt() const;
   virtual bool setData(ifstream& file);
   virtual bool setData2(ifstream& file);
protected:
   

};

#endif
