/**Date:7/14/2020
 * Name:Kevin Morales-Nguyen
 * Assignment: Stacks, Chapter 19
 * 
 * This is the specification file for the WordStack class, contains default constructor, destructor, and prototypes.
 * */
#ifndef WORDSTACK_H //.h file is the specification file and is used for 
#define WORDSTACK_H  // class decleration
#include <string>
using namespace std;

class WordStack{
    private:
      struct ListNode  // struct for nodes, 
      {
          string word; // private data member variable to hold word
          ListNode * next; // ListNode pointer variable to link to next node
      };
      ListNode * top; // ListNode pointer that points to first node
    public:
        WordStack(){ // default constructor
            top = nullptr; // set head to null = no nodes
        };
        ~WordStack(); // destructor is used to free up memory
        // prototypes for methods specified by assignment
       void push(string);
       void pop(string &);
       string pop(); // overloaded pop method which does not store value to a argument variable
       void addS();
       void concatenate();
        void printStack() const;
        //other mehtods that are used inside methods or give useful information in main
        int getStackSize() const;
        bool isEmpty();
};
#endif