/*
#include "library.h"
#include <iostream>

using namespace std;

int main(){
    Library * a = new Library;
    cout << "adress of the main" << a << endl;
    ifstream myfile ("data4books.txt");
    a->initializeLibraryItems(myfile);
    
    return 0;
}
*/
#include "library.h"
#include <iostream>

using namespace std;

int main(){
    Library  a;
    ifstream myfile ("data4books.txt");
    ifstream myFile2("data4patrons.txt");
    ifstream myfile3("data4commands.txt");
    a.initializeLibraryItems(myfile);
    a.processPatrons(myFile2); // processes the patrons from the data file
    a.processCommands(myfile3);
    cout<< a;
    cout<<endl;
    return 0;
}