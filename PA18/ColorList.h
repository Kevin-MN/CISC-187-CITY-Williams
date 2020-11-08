/**Date:7/9/2020
 * Name:Kevin Morales-Nguyen
 * Assignment: Linked Lists, Chapter 18
 * 
 * This is the specification file for the ColorList class, it declares a node struct that is 
 * integral to implementing the LinkedList data structure. There are also prototypes for member
 * methods, constructor, and destructor. The default constructor is defined  below.
 *
 * */
#ifndef COLORLIST_H //.h file is the specification file and is used for 
#define COLORLIST_H  // class decleration
#include <string>

using namespace std;

class ColorList{
    private:
      struct ListNode  // struct for nodes, 
      {
          string color; // private data member variable to hold color
          ListNode * next; // ListNode pointer variable to link to next node
      };
      ListNode * head; // ListNode pointer that points to first node
    public:
        ColorList(){ // default constructor
            head = nullptr; // set head to null = no nodes
        };
        ~ColorList(); // destructor is used to free up memory
        // prototypes for methods specified by assignment
        void append(string);
        int insert(string,int);
        int deleteNode(int);
        void printList() const;
        void reverse();
        int search(string) const;
        int getListSize() const;
};
#endif