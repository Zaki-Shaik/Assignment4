// Assignment 4: Design
// Team: Oliver Jeremiah Fernandez, Nicola Mihai, Zaki Shaik, Andy Zhong

// showhistory.h
// Definition of class ShowHistory

#ifndef SHOWHISTORY_H
#define SHOWHISTORY_H

#include "command.h"

using namespace std;

//---------------------------------------------------------------------------
// ShowHistory: 
//
//  Implementation:
//
//  -- Implements a ShowHistory of commands for Patron operation as a Command 
//  -- derived class
//
//  Assumptions:
//
//  -- Patron associated with Command must not be null
//

class ShowHistory : public Command
{

public:
    ShowHistory();      // Class default constructor
    ~ShowHistory();     // Class destructor

private:

    virtual bool execute() const;   // Overrides execute inherited from Command
    
    virtual string getString() const;
};

#endif