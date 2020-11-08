/**Date:7/14/2020
 * Name:Kevin Morales-Nguyen
 * Assignment: Stacks, Chapter 19
 * 
 * This file contains the implementation for all of the methods declared in the specification file, mainly to implement a dynamic stack.
 * low-level validation is also implemented in the methods.
 * */
#include "WordStack.h"
#include <iostream>
#include <string>
using namespace std;

//This method is used to push a value onto the stack, this method is very similar to the append method of a linked list except we set top to new node
void WordStack::push(string worda){
     if(worda.size() == 0 || worda == "" || worda == " " || worda == "\n" || worda == "\r" || worda.size() > 10){ // low-level validation
         cout << "Error: the word entered was invalid, longer than 10 characters or nothing entered." << endl;
        exit(EXIT_FAILURE);
     }
     
     ListNode *newNode = nullptr;
     newNode = new ListNode;
     newNode->word = worda;
     
     if(isEmpty()){
         top = newNode; // set top as new node
         newNode->next = nullptr;
         cout << "\n\"" << worda << "\" succesfully pushed to stack.\n\n";
     }
     else{
         newNode->next = top;
         top = newNode; // set top as new node
         cout << "\n\"" << worda << "\" succesfully pushed to stack.\n\n";
     }
 }
 
 //this method pops the top value of the stack and saves it to the reference variables passed as an argument
void WordStack::pop(string &worda){
     ListNode *temp;
     
     if(isEmpty()){ // low-level validation, cannot pop empty stack
        cout << "Error: stack is empty." << endl;
     }
     else{
         worda = top->word; // save word to reference variable
         temp = top->next;
         delete top; // delete node 
         top = temp;
          cout << "\nSucessfully popped \""<<worda<<"\" from stack\n\n";
     }
 }
 
//this methods is the overloaded pop() mehtod, it destroys the top node and return the value stored in it
string WordStack::pop(){
    string tempa;
     ListNode *temp;
     
     if(isEmpty()){ // low-level validation for pop cannot pop empty stack 
        cout << "Error: stack is empty." << endl;
     }
     else{
         tempa = top->word; // save word 
         temp = top->next;
         delete top; // delete node
         top = temp;
         return tempa; //return word
     }
 }
 
 //This is a small method that returns whether the stack is empty or not
bool WordStack::isEmpty(){
     bool status;
     if(!top){
         status = true;
     }
     else{
         status = false;
     }
     return status;
 }
 
//This method is used to add an 's' to the end of the top word on the stack
void WordStack::addS(){
     if(!top){ // low-level validation, cannot append to empty stack
        cout << "Error: stack is empty."; 
     }
     else{
         string temp = top->word; // save node value to temp
         if(temp.size() == 10){ // edge case in case word is 10 characters long
             temp = temp.substr(0,9);
             temp += 's';
         }
         else{ //word is 9 or less si,ply concatenate 's' char
             temp += 's';
         }
         top->word = temp; // save concatenated string to node
         cout << "\nSuccesfully added an 's' to the top word in the stack.\n\n";
     }
 }
  //This method is used to concatenate the top two words in a stack, the result is then stored in the two nodes
 void WordStack::concatenate(){
     string temp = "";
     ListNode *word1; // top of stack
     ListNode *word2;// top of stack - 1
    if(getStackSize() < 2){ // low-level validation, cannot concatenate unless there are 2 words in stack
        cout << "Error: Need minimum two words on noun stack.";
    }
    else{
        word1 = top; //top of stack
        word2 = top->next; // top of stack - 1
        temp = (word1->word) + (word2->word); // concatenate the two words
        if(temp.size() > 10){ // if the concatenation results in string more than 10 chars, truncate
            temp = temp.substr(0,10); // truncate
        }
        word1->word = temp; // save concatenated word to top of stack
        word2->word = temp;// save concatenated word to top of stack - 1
        cout << "\nConcatenation successful.\n\n";
    }
 }
 
// this method simply traverses the whole list and prints the color in each node
void WordStack::printStack() const{
    int count = 1;
    ListNode * ptrNode;
    
    if(top == nullptr){// low-level validation, cannot print empty stack
        cout << "\nError: stack is empty.\n" << endl;
    }
    else{
        cout << "\n";
        ptrNode = top;
        while(ptrNode->next){
            cout << count << ". " << ptrNode -> word << " " << endl; // print node data
            ptrNode = ptrNode -> next; // move to next node
            count++;
        }
        cout << count << ". " << ptrNode -> word << " " << "\n\n";
    }
}

//this is a helpful function that can be used within or outside of the class, it simply returns the 
//size of the list, it is used in insert and deleteNode to validate that the index position exists
int WordStack::getStackSize() const{
    int count = 0; // to hold size of list
    ListNode * ptrNode;
    
    if(!top){
        return count; // size is 0
    }
    else{ 
        ptrNode = top;
        count++;
        while(ptrNode->next){ // traverse list until at end
            ptrNode = ptrNode->next;
            count++; // increment counter
    }// while loop exit 
    return count; // return size
    }
}

//This is the destrucotr for the Stack, it will go through every node and delete it, freeing up memory
WordStack::~WordStack(){
     ListNode *nodePtr = nullptr;
     ListNode *nextNode = nullptr;
     nodePtr = top;
     
     while(nodePtr != nullptr){
         nextNode = nodePtr -> next;
         delete nodePtr; //destroy node
         nodePtr = nextNode;
     }
 }