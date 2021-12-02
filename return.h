// return.h
// Definition of class Return

#ifndef RETURN_H
#define RETURN_H

#include "command.h"

using namespace std;

//---------------------------------------------------------------------------
// Return: 
//
//  Implementation:
//
//  -- Implements a library item Return operation as a Command derived class
//
//  Assumptions:
//
//  -- LibraryItem associated with Command must not be null
//

class Return : public Command
{

public:
    Return();       // Class default constructor
    ~Return();      // Class destructor

private:

    virtual bool execute() const;   // Overrides execute inherited from Command
    virtual string getString() const;
};

#endif
