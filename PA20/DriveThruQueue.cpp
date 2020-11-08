/**Date:7/22/2020
 * Name:Kevin Morales-Nguyen
 * Assignment: Recursion and Queue's, Chapter 20
 * 
 * This file contains the implementation for all of the methods declared in the specification file, mainly to implement a 
 * dynamic queue with recursive methods. Low-level validation is also implemented in the methods.
 * */
#include "DriveThruQueue.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//this method appends a node to the end of the list, needs string and int arguments
void DriveThruQueue::append(string namep, int numOfKids){
      if(namep == "" || namep == " " || namep == "\n" || namep == "\r" || namep.size() >= 20 || namep.size() ==0){ // name arg low level validation
        cout << "Invalid input: " << " name is too long or blank." << endl;
        exit(EXIT_FAILURE);
    }
    else if(numOfKids < 0){ // number of kids low level validation
        cout << "Invalid input: " << " must be zero or more kids.\n";
        exit(EXIT_FAILURE);
    }
    
    ListNode *newNode;
    ListNode *ptrNode;
    
    newNode = new ListNode; // create new node
    newNode->name = namep;   //set data
    newNode->numKids = numOfKids;
    newNode->next = nullptr; // adding at end of list so next pointer points to nullptr
     
    if(!front){ //list is empty then set newNode to front
        front = newNode;
    }
    else{ // traverse until at end of list - 1
        ptrNode = front;
        while(ptrNode->next){
            ptrNode = ptrNode->next;
        }
        ptrNode->next = newNode; // set node at end
    }
 }
 
 //This method takes the first cutomer in the queue and removes them
void DriveThruQueue::placeOrder(){
     ListNode *ptrNode;
     
     if(!front){ // check if queue is empty
        cout << "\nQueue is empty!\n\n";
     }
     else{ // remove first node and re-assign front
         cout << "\nReady to take " << front->name << "'s order.\n\n";
         ptrNode = front->next;
         delete front; // delete node
         front = ptrNode;
     }
 }
 
//This is the driver method for counting cars, it simply calls the recursive helper method
//it returns the number of nodes in the list until it reaches end of list nullptr that is passed 
//recursively 
int DriveThruQueue::countCars() const{
    int count = recurNodeCount(front);
    return count;
}

int DriveThruQueue::recurNodeCount(ListNode *ptr) const {
    if(ptr == nullptr){ // base case is when the argument pointer points ot nullptr meaning the end of the list has been reached
        return 0;
    }
    else{
       return 1 + recurNodeCount(ptr->next); // return the recursive call that passes ptr that points to next node
    }
}

//This method is the driver methods for the recursive move kids funciton
 void DriveThruQueue::moveKids(){
     recurKidTraverse(front,nullptr,nullptr,nullptr,0); // call recursive helper method
 }
 
 //This is the recursive helper methods that recursively traverses the entire list, finds the node with the 
 //largest amount of kids, saves the max node through each call by passing the pointers as arguments, and then 
 //once the base case has been reached the list is properly reorganized and the max node is moved to the front
void DriveThruQueue::recurKidTraverse(ListNode *ptr, ListNode *prev, ListNode *mptr, ListNode *mprev, int max){
 
    if(!ptr && !prev){ // queue is empty, base case
        cout << "\nQueue is empty!\n\n";
    }
    else if(!ptr && prev){ // base case we are at end of queue no further recursive calls in this block
        if(max == 0){ // base case, no children
            cout << "\nNo cars with children.\n\n";
        }
        else if(mptr && !mprev){ // base case the max node is already at the front
            cout << "\nMost kids already at front!\n\n";
        }
        else if(max > 0){ // base case, there is a max node that is not at the front
            cout << "\n" << mptr->name <<" has been moved to the front for most kids.\n\n";
            mprev->next = mptr->next;
            mptr->next = front;
            front = mptr;
        }
    }
    else{ // traverse the entire list recursively
        //int tempm = max;
        if(ptr->numKids > max){ // check nodes while traversing to see if new max is set by member data
            mptr = ptr;
            mprev = prev;
            max = ptr->numKids;
        }
        
        prev = ptr;
        ptr = ptr->next;
        recurKidTraverse(ptr,prev,mptr,mprev,max); // recursive call
    }
 }
 
 //This method is a driver method for the recursive helper method, it saves the int returned by the 
 //helper method and displays an appropriate message, -1 means queue is empty, 0 means not found, 1 means
 // node was found and moved, 2 means already at front
 void DriveThruQueue::letInFriend(string namp){
     
     int status = recurFindFriend(front,nullptr,namp); // call recursive helper method
     
    if(status == -1){
        cout << "\nQueue is empty!\n\n";
    }
    else if(status == 0){
        cout << "\n" << namp << " was not found in line.\n\n";
    }
    else if(status == 1){
        cout << "\n" << namp << " was found and moved to front.\n\n";
    }
    else if(status == 2){
        cout << "\n" << namp << " is already at front!\n\n";
    }
 }
 
 //This method is the recursive helper method that is used to find a node based on a name and 
 //then move them to the front while also making sure the list is put together properly afterwards
 int DriveThruQueue::recurFindFriend(ListNode *ptr, ListNode *prev, string namp) {
     if(!ptr && !prev){ // base case list is empty
         return -1;
     }
     else if(!ptr && prev){ //base case, end of list has been reached before friend was found
         return 0;
     }
     else{ // traversing list if list is not emppty and we are not at end
        if(ptr->name == namp){ //base case, found matching name so no need for more recursive calls
            if(!prev){ // prev is nullpointer if node is at front
                return 2;
            }
            else{ // patch up the list and reassign front
                prev->next = ptr->next; 
                ptr->next = front;
                front = ptr;
                return 1;
            }
        }
        else{ // recursive call if still traversing and name does not match
            prev = ptr;
            ptr = ptr->next;
            return recurFindFriend(ptr,prev,namp); // recursive call
        }
     }
 }
 
 // this method simply traverses the whole list and prints the name and number of children
void DriveThruQueue::printQueue() const{
    int count = 1;
    ListNode * ptrNode;
    
    if(front == nullptr){// low-level validation, cannot print empty stack
        cout << "\nError: queue is empty.\n" << endl;
    }
    else{
        cout << "\n";
        ptrNode = front;
        cout << left << setw(24) << "     Name" << "Kids\n\n"; 
        while(ptrNode->next){
            
            cout << count << ". " << left << setw(22) << ptrNode -> name << ptrNode->numKids << endl; // print node data
            ptrNode = ptrNode -> next; // move to next node
            count++;
        }
        cout << count << ". " << left << setw(22) << ptrNode -> name << ptrNode->numKids << endl << endl;
    }
}
 
//This is a small method that returns whether the stack is empty or not
bool DriveThruQueue::isEmpty(){
    bool status;
    if(!front){
        status = true;
    }
    else{
        status = false;
    }
    return status;
 }
 
//This is the destrucotr for the list, it will go through every node and delete it, freeing up memory
DriveThruQueue::~DriveThruQueue(){
     ListNode *nodePtr = nullptr;
     ListNode *nextNode = nullptr;
     nodePtr = front;
     
     while(nodePtr != nullptr){
         nextNode = nodePtr -> next;
         delete nodePtr; //destroy node
         nodePtr = nextNode;
     }
 }