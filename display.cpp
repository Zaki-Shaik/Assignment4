#include "display.h"

Display::Display()
{

}

Display::~Display()
{

}
bool Display::execute() const
{
    cout<<"this ran";
    return true;
}

string Display::getString() const
{
    return "Display";
}