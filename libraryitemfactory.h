// Assignment 4: Design
// Team: Oliver Jeremiah Fernandez, Nicola Mihai, Zaki Shaik, Andy Zhong

// libraryitemfactory.h
// Definition of class LibraryItemFactory

#ifndef LIBRARYITEMFACTORY_H
#define LIBRARYITEMFACTORY_H

#include <string>  
#include "childrenbook.h"
#include "fictionbook.h"
#include "periodical.h"


using namespace std;

//---------------------------------------------------------------------------
// LibraryItemFactory: 
//
//  -- Implements a LibraryItemFactory class that creates LibraryItem class 
//  -- derived instances based on char parameter passed to createItem method
//  -- Items supported: C - ChildrenBook, F - FictionBook, P - Periodical
//
//  Assumptions:
//
//  -- Factory can accommodate up to 26 different library item types per 
//  -- current implementation
//  

class LibraryItemFactory
{

private:
// it will be passed the array
    // hashtable
    // default types are intialized in Library constructor
    // can be resized with new book types using the method
    // hashtableInsert (char c, LibraryItem*& P)
    // assumes P is a dynamically allocated object already

    LibraryItem** HashTable;
    int sizeOfHashTable;

   // int hash(char ch) const { return ch-'A'; } // Hash function with no 
                                               // collisions

    

public:
    LibraryItemFactory();   // Default class constructor
    ~LibraryItemFactory();  // Class destructor
    LibraryItem* createItem(int) const; // Creates LibraryItem instances by 
        // invoking createItem method on instances stored by objFactory array
};

#endif
