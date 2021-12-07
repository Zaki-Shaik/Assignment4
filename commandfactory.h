// commandfactory.h
// Definition of class CommandFactory

#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include <string>  
#include "command.h"

#include "showhistory.h"
#include "checkout.h"
#include "return.h"
#include "display.h"

// showhistory, display, return, checkout
// since they already include library item
#include "libraryitem.h"


using namespace std;

//---------------------------------------------------------------------------
// CommandFactory: 
//
//  Implementation:
//
//  -- Implements a CommandFactory class that creates Command class derived 
//  -- instances based on char parameter passed to createCommand method
//  -- Current commands: C - Checkout, R - Return, H - Show History
//
//  Assumptions:
//
//  -- Factory can accommodate up to 26 different command types per current 
//  -- implementation
//  

class CommandFactory
{

private:
    Command** factoryOfCommand; // Array containing pointers to instances of  
                             //Command derived classes recognized by factory
                             // initialize unused to nullptr
    int sizeOfFactoryCommand;

   // int hash(char ch) const { return ch-'A'; } // Hash function with no 
                                               //collisions


public:
    Command *createCommand(int hashedChar); // Creates Command instances by 
    
    bool checkValid(int hashedChar); // checks if command char is valid
    // invoking createCommand method on instances stored by objFactory array
    CommandFactory();   // Default class constructor
    ~CommandFactory();  // Class destructor

};

#endif
