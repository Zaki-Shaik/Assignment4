#ifndef DISPLAY_H
#define DISPLAY_H
#include "command.h"

using namespace std;
class Display: public Command
{
    public:
        Display();
        ~Display();

    private:
        virtual bool execute() const; // Overrides execute inherited from Command
        virtual string getString() const;
};


#endif