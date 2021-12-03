#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

class LibraryItem
{
        friend ostream & operator<<(ostream &, const LibraryItem &);
    protected:
        // initialize will be set true thru createIt
        bool initialize;
        // initialize this for error checking later
        int MaxCopies;
        int CopiesLeft;
        string* ArrayOfParameters;
        int sizeOfArrayOfParameters;
        // for loop in createIt initializes this
        // this has a custom size, may be different from other arrays
        string** ArrayOfSortingPrio;
        int sizeOfArrayOfSortingPrio;
        string typeOfBook;
                
        // ArrayOfFileInitializeOrder should be same size as
        // array of parameters and point to it in order
        //string ArrayOfFileInitializeOrder;
        //int sizeOfArrayOfFileInitialize;





    public:
        LibraryItem();
    
        virtual ~LibraryItem();

        // new stuff from today, 11/24
        bool operator==(const LibraryItem&) const;
        bool operator!=(const LibraryItem&) const;
        bool operator<(const LibraryItem&) const;
        bool operator>(const LibraryItem&) const;
      //  LibraryItem(const LibraryItem&);
        LibraryItem & operator=(const LibraryItem&);
        
        //virtual void copyLibrary(const LibraryItem&) = 0;

        //
// this function will:
//    set All arrays (3) to dynamically allocated size
//    Sorting array may have different size (eg: no date)
        virtual void makeEmpty();
        virtual LibraryItem* createIt() const = 0;
        virtual bool setData(ifstream& file) = 0;
        virtual bool setData2(ifstream& file) = 0;
        //http://courses.washington.edu/css343/zander/Labs/Book/output.txt
        // checks if initialize is true -> output contents of Array
        // Output amount of copies left at the start
        // adds custom spacing between each parameter
        // eg:  cout << ...
//   << left << setw(TITLE_MAX_LENGTH+2) << title.substr(0, TITLE_MAX_LENGTH)
//   << right << setw(MONTH_OUTPUT_WIDTH) << month
//   << ...
        // the column headers will be formatted properly by
        // the for loop that calls this calls a endl after this function
        void OutputAll();
        virtual string atArrayIndex(int atIndex);
        virtual int getCopiesLeft();
        virtual void setCopiesLeft(int);
        virtual int getMaxCopies();
        
};

#endif // LibraryItem_H