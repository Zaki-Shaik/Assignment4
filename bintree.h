//---------------------------------------------------------------------------
// bintree.H
// Binary Search Tree
// Authors: Zaki Shaik
//---------------------------------------------------------------------------
// bintree class:  Binary Tree class with aadditional features
//   includes  features:
//   -- allows output of the whole tree
//   -- allows insert and remove for the tree
//   -- gets sibling and parent of passed node
//   -- Turns a tree into a inorder array
//   -- turns array into a bstree
//
// Implementation and assumptions:
//   -- array is assumed to be sorted
//   -- Array has 100 elements
//   -- Only Passes string in the NodeData
//---------------------------------------------------------------------------
#ifndef BINTREE_H
#define BINTREE_H

#include "libraryitem.h"
#include<iostream>
using namespace std;

class BinTree 
{
//----------------------------------------------------------------------------
// operator<<
// Preconditions: need to pass ostream object and BinTree object
// Postconditions: prints the tree with inorder traversal
    friend ostream & operator<<(ostream &, const BinTree &);
public:
//----------------------------------------------------------------------------
// Default constructor 
// Preconditions: none
// Postconditions: sets root to null
    BinTree();
//----------------------------------------------------------------------------
// copy constructor
// Preconditions: Need to pass a Bintree object to the function
// Postconditions: copies the tree
    BinTree(const BinTree &);
//----------------------------------------------------------------------------
// Destructor()
// Preconditions: none
// Preconditions: Deallocates memory of the tree
    ~BinTree();
//----------------------------------------------------------------------------
// isEmpty()
// Preconditions: none
// Postconditions: checks to see if tree is empty and returns boolean
    bool isEmpty() const;
//----------------------------------------------------------------------------
// makeEmpty()
// Preconditions: none
// Postconditions: Empties the tree
    void makeEmpty();
//----------------------------------------------------------------------------
// operator=
// Preconditions: need to pass a BinTree object
// Postconditions: assigns the passed tree to this tree
    BinTree & operator=(const BinTree &);
//----------------------------------------------------------------------------
// operator==
// Preconditions: need to pass a BinTree object
// Postconditions: returns a boolean if two trees are equal to each other
    bool operator==(const BinTree &) const;
//----------------------------------------------------------------------------
// operator!=
// Preconditions: need to pass a BinTree object
// Postconditions: returns a boolean if two trees are not equal 
// to each other
    bool operator!=(const BinTree &) const;
//----------------------------------------------------------------------------
// insert
// Preconditions: need to pass a NodeData Object
// Postconditions: returns a boolean if insertion of object was successful
    bool insert(LibraryItem*&);

 //   bool findLibraryItem(LibraryItem*&) const;
//----------------------------------------------------------------------------
// retrieve
// Preconditions: need to pass a NodeData object and a NodeData 
// object for the retrieved node
// Postconditions: returns a boolean if nodeData exists or not 
// and retrieves the node
    bool retrieve(const LibraryItem&, LibraryItem*&) const;
//----------------------------------------------------------------------------
// getSibling
// Preconditions: need to pass a NodeData object and a NodeData 
// object for the retrieved node
// Postconditions: returns a boolean if sibling of the node exists and 
// returns the sibling
   // bool getSibling(const NodeData &, NodeData&) const;
//----------------------------------------------------------------------------
// getParent
// Preconditions: need to pass a NodeData object and a NodeData 
// object for the retrieved node
// Postconditions: returns a boolean if parent of the node exists and 
// returns the parent
  //  bool getParent(const NodeData &, NodeData&) const;
//----------------------------------------------------------------------------
// bstreeToArray
// Preconditions: need to pass a NodeData array
// Postconditions: fills a array with tree data using inorder traversal
// the tree is empty
   // void bstreeToArray(NodeData* []);
//----------------------------------------------------------------------------
// arrayToBSTree
// Preconditions: need to pass a NodeData array
// the tree is empty and array is sorted
// Postconditions: fills a tree with array data
  //  void arrayToBSTree(NodeData* []);
  //void arrayToBSTree(NodeData * arrayOfNodeData[]);
  void arrayToBSTree(LibraryItem * []);
  
//----------------------------------------------------------------------------
// displaySideways
// Preconditions: none
// Postconditions: displays the tree sidewqays
    void displaySideways() const;
    int getSizeOfArray() const;
    int getSizeOfIndex(int) const;
   // void OutputWithFormat(int*&) const;
private:

int sizeOfArray;
int* maxSizeOfEachIndexOfArrayOfParameter;
    struct Node 
    {
    
    LibraryItem* data; // pointer to data object
    Node* left; // left subtree pointer
    Node* right; // right subtree pointer

    };
    Node * root;
   // void OutputWithFormatHelper(int*& ,const Node*)const;
//----------------------------------------------------------------------------
// inorderHelper
// Preconditions: need to pass a Node object for root of tree
// Postconditions: prints the tree with inorder traversal
   void inorderHelper(const Node*, ostream &) const;
//----------------------------------------------------------------------------
// sidewaysHelper
// Preconditions: need to passa Node for root of tree and int
// Postconditions: displays the tree sidewqays
    void sidewaysHelper(Node*, int) const;
//----------------------------------------------------------------------------
// makeEmptyHelper()
// Preconditions: need to pass a Node object
// Postconditions: Empties the tree
    void makeEmptyHelper(Node*&) const;
//----------------------------------------------------------------------------
// copyHelper
// Preconditions: need to pass root and root of tree that needs to be 
// copied
// Postconditions: this tree has copied all the nodes from the cPtr
  //  void copyHelper(Node*&, const Node*) const;
//----------------------------------------------------------------------------
// equalHelper
// Preconditions: need to pass root and root of tree that needs to be 
// compared
// Postconditions: returns a boolean if two trees are equal to each other
    bool equalHelper(const Node*, Node*) const;
//----------------------------------------------------------------------------
// retrieveHelper
// Preconditions: need to pass a NodeData object and a NodeData 
// object for the retrieved node and a Node ptr for root
// Postconditions: returns a boolean if nodeData exists or not 
// and retrieves the node
    bool retrieveHelper(Node *,
    const LibraryItem&, LibraryItem*&) const;
//----------------------------------------------------------------------------
// getSiblingHelper
// Preconditions: need to pass a NodeData object and a NodeData 
// object for the retrieved node and a Node ptr for root
// Postconditions: returns a boolean if sibling of the node exists and 
// returns the sibling
    // bool getSiblingHelper(Node*, 
    // const NodeData &, NodeData&) const;
//----------------------------------------------------------------------------
// getParentHelper
// Preconditions: need to pass a NodeData object and a NodeData 
// object for the retrieved node
// Postconditions: returns a boolean if parent of the node exists and 
// returns the parent
    // bool getParentHelper(Node*, 
    // const NodeData &, NodeData&) const;
//----------------------------------------------------------------------------
// bstreeToArrayHelper
// Preconditions: need to pass a NodeData array, Node ptr for root, 
// and index 
// Postconditions: fills a array with tree data using inorder traversal
// the tree is empty
// int  bstreeToArrayHelper(Node*, NodeData* [], int);
  Node * arrayToBSTree(LibraryItem * myArray[], int start, int end);
//----------------------------------------------------------------------------
// arrayToBSTreeHelper
// Preconditions: need to pass a NodeData array,
// 2 ints for splitting array
// the tree is empty and array is sorted
// Postconditions: fills a tree with array data
// tree is balanced
 //   void arrayToBSTreeHelper(NodeData* [], int, int);
//void bstreeToArray(NodeData * []);

};


#endif