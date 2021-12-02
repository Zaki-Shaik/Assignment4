#include "libraryitemfactory.h"

 LibraryItemFactory::LibraryItemFactory()
 {
         // A is 0 index
    sizeOfHashTable = 16;
    HashTable = new LibraryItem*[16];
    
    for (int i = 0; i < 16; i++){

        HashTable[i] = nullptr;
    }
    HashTable[2] = new ChildrenBook;
    
    HashTable[5] = new FictionBook;
    
    HashTable[15] = new Periodical;
    
 }

 LibraryItem* LibraryItemFactory::createItem(int ch)
 const {
    
LibraryItem* ddd = HashTable[ch]->createIt();

    return ddd;

    //  return nullptr;

    
    
 }

 LibraryItemFactory::~LibraryItemFactory()
 {
    for (int i = 0 ; i < sizeOfHashTable; i++){

        delete HashTable[i];
        HashTable[i] = nullptr; 
    }

    delete [] HashTable;
    HashTable = nullptr;
 }