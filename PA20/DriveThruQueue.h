/**Date:7/22/2020
 * Name:Kevin Morales-Nguyen
 * Assignment: Recursion and Queue's, Chapter 20
 * 
 * This is the specification file for the DriveThruQueue class, contains default constructor, destructor, and prototypes.
 * */
#ifndef DRIVETHRUQUEUE_H //.h file is the specification file and is used for 
#define DRIVETHRUQUEUE_H  // class decleration
#include <string>
using namespace std;

class DriveThruQueue{
    private:
      struct ListNode  // struct for nodes, 
      {
          string name; // private data member variable to hold name
          int numKids;
          ListNode * next; // ListNode pointer variable to link to next node
      };
      ListNode * front; // ListNode pointer that points to first node
    public:
        DriveThruQueue(){ // default constructor
          front = nullptr;  
        };
        ~DriveThruQueue(); // destructor is used to free up memory
        
        // prototypes for methods specified by assignment
        void append(string,int);
        void placeOrder(); // basically dequeue() from front, print front name info and delete front node
        int countCars() const; //DONE RECURSIVELY
        void moveKids(); // recursive
        void letInFriend(string); // recursive
        void printQueue() const;
        
        //helper methods that are used to carry out recursive tasks
        int recurNodeCount(ListNode *) const;
        int recurFindFriend(struct ListNode *,ListNode *, string);
        void recurKidTraverse(ListNode *, ListNode *, ListNode *, ListNode *,int);
        
        //misc method that can that tells useful information about state of list
        bool isEmpty();
};
#endif