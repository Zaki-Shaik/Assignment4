// periodical.h
// Definition of class Periodical

#ifndef PERIODICAL_H
#define PERIODICAL_H

//#include <string>  
#include "libraryitem.h"

using namespace std;

//---------------------------------------------------------------------------
// Periodical: 
//
//  -- Implements a Periodical ADT as a LibraryItem derived class
//  -- Attributes: author title, year inherited from base class/es
//  -- Specific attributes: month
//
//  Assumptions:
//
//  -- Class is used for both storage and retrieval purposes/use cases
//  -- Data Extensibility is modeled through "attributes" list inherited from 
//  -- LibraryItem base class
//

class Periodical : public LibraryItem
{

public:
    //Periodical();       // Class default constructor
    ~Periodical();      // Class destructor

    // Method invoked by LibraryItemFactory class
    virtual LibraryItem* createIt() const;   

     // Displays Periodical attributes       
    //virtual void print() const;

    // Extracts data attributes from line of text
    virtual bool setData(ifstream& file);

    // Extracts data attributes from line of text containing a patron's 
    // command (e.g. Checkout, Return)
    //virtual void setDataFromCommand(string line) const;

private:
   // int month;  // Periodical's month of publication

};

#endif
