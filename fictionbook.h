#ifndef FICTIONBOOK_H
#define FICTIONBOOK_H


#include "book.h"

using namespace std;

//---------------------------------------------------------------------------
// FictionBook: 
//
//  Implementation:
//
//  -- Implements a FictionBook ADT as a Book derived class
//  -- Attributes: author title, year inherited from base class/es
//
//  Assumptions:
//
//  -- Class is used for both storage and retrieval purposes/use cases
//  -- Data Extensibility is modeled through "attributes" list inherited from
//  -- LibraryItem base class
//

class FictionBook : public Book
{

public:
   // FictionBook();      // Class default constructor
    ~FictionBook();     // Class destructor
    // Method invoked by LibraryItemFactory class
    virtual LibraryItem* createIt() const;    
//virtual bool setData(ifstream& file);
    // Displays Book attributes
    // virtual void print() const; 

    // Extracts data attributes from line of text 
    // virtual void setData(string line) const;    

    // Extracts data attributes from line of text containing a patron's 
    // command (e.g. Checkout, Return)
    // virtual void setDataFromCommand(string line) const;

};

#endif