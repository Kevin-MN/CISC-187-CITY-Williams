/**Date:7/9/2020
 * Name:Kevin Morales-Nguyen
 * Assignment: Linked Lists, Chapter 18
 * 
 * This file contains the implemtation of all the methods declared in the ColorList.h file.
 * The methods use pointers extensively to work with nodes and to travers the list. exit_failures
 * are in place to act as final resort to bad data for primary colors.  
 * 
 * */
#include "ColorList.h"
#include <iostream>
#include <string>
using namespace std;

//this method will append a node to the end of the list, it accepts a primary color that is validated in the main method
void ColorList::append(string colorp){
    
    if(colorp != "red" && colorp != "yellow" && colorp != "blue"){ // arguement is not a primary color then exit failure
        cout << "Invalid input: " << colorp << "  not a primary color." << endl;
        exit(EXIT_FAILURE);
    }
    
    ListNode * newNode; // declar new node 
    ListNode * nodePtr; // declare a pointer node
    
    newNode = new ListNode; // allocate memory for new node
    newNode -> color = colorp; // set the color member variable of new node
    newNode -> next = nullptr; // new node is placed at end so its next is nullpointer
    
    if(!head){ // no nodes
        head = newNode; // newNode = first node
        cout << "\nList has been appended with " << newNode -> color << "\n";
    }
    else{
        nodePtr = head; // node pointer = first node
        
        while(nodePtr->next){ // while next node is not nullpointer
            nodePtr = nodePtr->next; // traverse list by each node, set node pointer to the next node 
        }
        nodePtr->next = newNode; // nullpointer has been reached meaning end of list, node pointers node sets next to new node
        cout << "\nList has been appended with " << newNode -> color << "\n";
    }
    cout << "\n";
}

//this method inserts a primary color at a index position passed by arguements, it returns an integer to tell 
//calling function whether the insertion was succesful or not, the insertion will return -1 indicating a failure
// if the index is no valid, it will otherwise return 0 indicating success
int ColorList::insert(string colorp, int pos){
    int index = 0;
    
    if(colorp != "red" && colorp != "yellow" && colorp != "blue"){// arguement is not a primary color then exit failure
        cout << "Invalid input: " << colorp << "  not a primary color." << endl;
        exit(EXIT_FAILURE);
    }
    
    if(pos < 0 || pos > getListSize()){
        return -1; // return -1 if position does not exist
    }
    
    ListNode *newNode; // create new node
    ListNode *nodePtr; // create pointer node
    ListNode *prevNode = nullptr; // create previous node, we use two pointers because we will the previous node    
                                 // will link to the new node and the new node will link to the node pointers
                                 
                                 //  prevNode  ->  newNode  -> nodePtr
    
    newNode = new ListNode; // allocate memory for new node
    newNode -> color = colorp; // set color of new node
    
    if(!head){ // if no nodes
        head = newNode; // first node is newNode
        newNode -> next = nullptr; // newNode is also end of list so next is nullpointer
    }
    else{ // there is a first node
        nodePtr = head; // 
        prevNode = nullptr;
        
        //continue traversing until at end of list or index position has been reached
        while(nodePtr != nullptr  && !(index == pos)){
            prevNode = nodePtr; // move previous node up one
            nodePtr = nodePtr->next; // mode node pointer up one
            index++; // increment index to keep track 
        }
        // loop has been exited so we are either at the index, the begging of the list or the end
        if(prevNode == nullptr){ // if inserting at beginning of list then head is the newNode and set newNode next to node pointer
            head = newNode;
            newNode->next = nodePtr;
        }
        else{
            prevNode->next = newNode; // previous node next links to newNode
            newNode->next = nodePtr;// newNode next links to node pointer
        }
    }
    return 0; // return 0 for succesful linking
}

//this method is used to delete a node at a postion specified by the arguement, -1 is returned if position is invalid,
//0 is returned indicating succesful removal, the node is deleted from memory
int ColorList::deleteNode(int pos){
    
    int index = 0;
    ListNode *nodePtr;
    ListNode *prevNode;
    
    if(pos < 0 || pos > (getListSize() - 1)){
        return -1; // return -1 if position does not exist
    }
    
    if(!head){ // no nodes, nothing to delete
        return -1;
    }
    
    if(pos == 0){ // first node
        nodePtr = head->next; // use node pointer to store next node
        delete head; // delete the first node
        head = nodePtr; // new head is node pointer
    }
    else{
        nodePtr = head;
        // keep traversing until end of list is reached or we reach the index position
        while(nodePtr != nullptr && !(index == pos)){
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
            index++;
        }
        //we have exited while loop, so we are at end or we have reached desired index
        if(nodePtr){
            prevNode->next = nodePtr->next; // precious node and node pointer contain nodes, so we set the previous nodes
                                            // next node to node pointers next node, thus the middle node is disengaged
            delete nodePtr; // delete the node in node pointer
        }
    }
    return 0; // return 0, succesful deletion
}

// this method simply traverses the whole list and prints the color in each node
void ColorList::printList() const{
    int count = 1;
    ListNode * ptrNode;
    
    if(!head){
        cout << "\nList is empty!\n" << endl;
    }
    else{
        cout << "\n";
        ptrNode = head;
        while(ptrNode->next){
            cout << count << ". " << ptrNode -> color << " " << endl; // print node data
            ptrNode = ptrNode -> next; // move to next node
            count++;
        }
        cout << count << ". " << ptrNode -> color << " " << "\n\n";
    }
}

// this method is used to reverse the order of the linkd list, we will use three pointers to keep track of nodes and
//link them appropriately
void ColorList::reverse(){
    ListNode *curNode = head;
    ListNode *prevNode = nullptr;
    ListNode *nextNode = nullptr;
    
    if(!head){
        cout << "\nList is empty!\n" << endl;
    }
    else{
        while(curNode != nullptr){// while not at end of list
            nextNode = curNode->next; // the nextNode is set to current nodes next node
            curNode->next = prevNode; // link current nodes next node to previous node
            prevNode = curNode; // previous node moved up curernt node
            curNode = nextNode;// current node moved up to next node
        }
        head = prevNode; // end has been reached so prevNode points to last node, last node becomes head node
        cout << "\nList has been reversed.\n\n";
    }
}

//this method will seach the entire list and will return the index of the first occurance of the color passed
//in the arguments, -1 is returned if the list has been traversed and the method has not returned from within the 
//while loop
int ColorList::search(string colorp) const{
    
    if(colorp != "red" && colorp != "yellow" && colorp != "blue"){// arguement is not a primary color then exit failure
        cout << "Invalid input: " << colorp << "  not a primary color." << endl;
        exit(EXIT_FAILURE);
    }
    
    int index = 0;
    ListNode *nodePtr;
    
    string temp = colorp;
    for(char e:temp){
        e = tolower(e);
    }
    
    if(!head){
        return -1; // if list is empty return -1
    }
    else{
        nodePtr = head;
        while(nodePtr != nullptr){ // traverse list
            if(nodePtr->color == temp){ // if the value in the node is equal to color argument
                return index; //return the index position of the first occurance, calling funciton knows seach succesful
            }
            nodePtr = nodePtr->next;
            index++;
        }
    }
    return -1; // return if value not found in list
}

//this is a helpful function that can be used within or outside of the class, it simply returns the 
//size of the list, it is used in insert and deleteNode to validate that the index position exists
int ColorList::getListSize() const{
    int count = 0; // to hold size of list
    ListNode * ptrNode;
    
    if(!head){
        return count; // size is 0
    }
    else{ 
        ptrNode = head;
        count++;
        while(ptrNode->next){ // traverse list until at end
            ptrNode = ptrNode->next;
            count++; // increment counter
    }// while loop exit 
    return count; // return size
    }
}

//this is the destructor for ColorList object, because we work pointers and dynamic memory, we erase
// the linked list once it is out of scope to free up memory and prevent crashes and leaks
ColorList::~ColorList(){
    ListNode *ptrNode;
    ListNode *nextNode;
    
    ptrNode = head;
    while(ptrNode != nullptr){
       nextNode = ptrNode->next; // next node will hold current nodes next node
        
        delete ptrNode; // delete the current node
        
        ptrNode = nextNode; //current node is now next node
    }
}