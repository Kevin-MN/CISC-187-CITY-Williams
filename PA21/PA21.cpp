/**Date:7/27/2020
 * Name:Kevin Morales-Nguyen
 * Assignment: Binary Trees, Chapter 21
 * 
 * This file contains the main and various funcitons that are used to create a menu driven program 
 * that calls the members methods of the binary tree class.
 * */
#include "IntBinaryTree.h"
#include <iostream>
#include <string>
using namespace std;

//functions used in main that work with binary tree
void insert(IntBinaryTree &); // we also use reference variable because we do not want to work with a 
void displayTreeInOrder(IntBinaryTree &); // copy of the object, we pass reference of created binary tree
void leafCount(IntBinaryTree &);
void treeHeight(IntBinaryTree &);
void treeWidth(IntBinaryTree &);

//functions used to create "menu-driven" program
void menu_driver(IntBinaryTree);
int display_menu();
void display_error();

//functions for getting user input, validation is implemented for all integers
int getIntInput(string,string);

//functions for validating string on criteria
bool charCheck(string);

int main()
{
    IntBinaryTree binTree; // create binary tree
     menu_driver(binTree);
    return 0;
}

//this method asks the user to input a option from the menu.
void menu_driver(IntBinaryTree tree){
    int choice = 0;     //variables used for user input
    while(choice != 6){
        choice = display_menu();// get menu choice form user
        cin.ignore();
        switch(choice){ 
            case 1: //insert
                insert(tree);
            break;
            case 2: //display tree
                displayTreeInOrder(tree);
            break;
            case 3: //leaf count
                leafCount(tree);
            break;
            case 4: //tree height
                treeHeight(tree);
            break;
            case 5: //tree width
                treeWidth(tree);
            break;
            case 6: //exit
            cout << "\nSee you later. Kevin Morales-Nguyen PA 21 - Binary Trees\n";
            return;
            default: // default : option selection error
            display_error();
            break;
        }
    }
}

//this function is used to call the insert member method
void insert(IntBinaryTree &tree){
   tree.insertNode(getIntInput("Number:","Please enter a valid integer."));
   cout << "\nInsertion succesful.\n\n";
}

//this function is used to call the member method that displays the tree
void displayTreeInOrder(IntBinaryTree &tree){
    if(tree.treeHeight() == -1){
        cout << "\nTree is empty!\n\n";
    }
    else{
        cout << "\nTree in order: ";
        tree.displayInOrder();
        cout << "\n\n";
    }
}

//this function is used to call the membor method that counts the leaves on the binary tree
void leafCount(IntBinaryTree &tree){
    if(tree.treeHeight() == -1){
        cout << "\nTree is empty!\n\n";
    }
    else{
        cout <<"\nThere are " << tree.leafCount() << " leaves in the binary tree.\n\n";
    }
}

//this function is used to call member method that gives the height of the tree
void treeHeight(IntBinaryTree &tree){
    if(tree.treeHeight() == -1){
        cout << "\nTree is empty!\n\n";
    }
    else{
        cout <<"\nThe tree has a height of " << tree.treeHeight()<< ".\n\n";
    }
}

//this function is used to call the member method that gets the width of the tree
void treeWidth(IntBinaryTree &tree){
    if(tree.treeHeight() == -1){
        cout << "\nTree is empty!\n\n";
    }
    else{
        cout <<"\nThe tree has a width of " << tree.treeWidth()<< ".\n\n";
    }
}

//this method is used to display the menu options and get a choice from the user.
int display_menu(){
    int temp_choice;
    cout << "1. insert\n" 
        << "2. Display tree in order\n"
        << "3. Display leaf count\n"
        << "4. Display tree height\n"
        << "5. Display tree width\n"
        << "6. Exit\n";
    cout << "\nEnter your choice: ";
    
    cin >> temp_choice;
    return temp_choice;    
} 

//if the user did not enter 1-6 then an error is displayed, if they entered a character the fail bit is cleared.
void display_error(){
    cout << "\nPlease enter a valid option from the menu(1-6).\n\n";
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
    }
}

//this function is used to get an integer from the user, getline is used and then string in converted
int getIntInput(string prompt, string error){
    string input = "-1";
    bool valid;
    cout << prompt;
    getline(cin,input);
    valid = charCheck(input); // check if string contains a character, now implements negative integers
    while(!cin || !valid || input == ""){ // if input is bad ask user again, highlevel validation for all integers
        cout << error << endl;
        cin.clear();
        cout << prompt;
        getline(cin, input);
        valid = charCheck(input);  
    }
    // if the loop has been passed that means the input is valid
    int temp = stoi(input); //convert string to int
    return temp; 
}

//this function is used to check if the string contains a character, an integer should only be able to
//have a single negative sign that could possible be at the front of the string
bool charCheck(string temp){
    int negChar = 0; 
    for(char e:temp){
        if(e == '-'){
            negChar++;
            if(negChar > 1){
                return false;
            }
            if(temp[0] != '-'){ // false if '-' sign is not at the front of the string
                return false;
            }
        }
        else if(!isdigit(e)){
            return false;
        }
    }

    if(temp.size() == 1 && temp[0] == '-'){
        return false;
    }
    
    return true;
}