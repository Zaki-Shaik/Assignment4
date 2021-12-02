// checkout.h
// Definition of class Checkout

#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "command.h"

using namespace std;

//---------------------------------------------------------------------------
// Checkout: 
//
//  Implementation:
//
//  -- Implements a library item Checkout operation as a Command derived class
//
//  Assumptions:
//
//  -- LibraryItem associated with Command must not be null
//  -- Execution of Checkout operation depends on item's availability 
//  -- (LibraryItem count attribute must be greater than 1)
//

class Checkout : public Command
{

public:
    Checkout();     // Class default constructor
    ~Checkout();    // Class destructor

private:
    virtual bool execute() const; // Overrides execute inherited from Command
    virtual string getString() const;
};

#endif