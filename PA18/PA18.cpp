/**Date:7/9/2020
 * Name:Kevin Morales-Nguyen
 * Assignment: Linked Lists, Chapter 18
 * 
 * This file contains the main method, where a ColorList object is created and used 
 * by the menu_driver function to use the methods of the ColorList class. There are methods
 * for gathering user input, and high-level validation is implemented which requires the user to enter 
 * a valid primary color. 
 * 
 * */

#include "ColorList.h"
#include <iostream>
using namespace std;

//functions used to create "menu-driven" program
void menu_driver(ColorList);
int display_menu();
void display_error();

//functions for getting user input, validation is implemented for primary colors
int getIntInput(string,string);
string getStringInput(string,string);

//functions for validating string on criteria
bool charCheck(string);

int main()
{
   ColorList list; // create custom dynamic linked list
   menu_driver(list); // call menu_driver to invoke various methods on ColorList object
    return 0;
}

//this method asks the used to input a option from the menu.
void menu_driver(ColorList list){
    int choice = 0;     //variables used for user input
    string tempInput = "";
    int tempPos = 0;
    int result = -100; // this variable is used to hold the value returned 
                        //by methods with index checking, -1 is returned if invalid index/dne
    while(choice != 8){
        choice = display_menu();    // get menu choice form user
        switch(choice){ 
            case 1: // append list
            tempInput = getStringInput("Enter a primary color: ","Invalid input, enter a valid primary color: "); // get valid primary color
                 list.append(tempInput); // append primary color to list
            break;
            case 2: // insert node
                tempInput = getStringInput("Enter a primary color: ","Invalid input, enter a valid primary color: "); // get valid primary color
                tempPos = getIntInput("Index of insertion: ", "Invalid index, enter valid index: "); // get a index position from user
                result = list.insert(tempInput,tempPos); // insert primary color at position, method returns success state
                if(result ==  0){ // result == 0 means functions inserted succesfully
                    cout << "\nInsertion succesful, " << tempInput << " was inserted at index "<<  tempPos << ".\n\n";
                }
                else{ // if the function returns -1 then else block is executed and insertion failed due to invalid index
                    cout << "\nInsertion failed, index does not exist.\n\n";
                }
            break;
            case 3: // delete node
                cin.ignore();
                tempPos = getIntInput("Position of deletion: ", "Invalid index, enter valid index: "); // get index position from user
                result = list.deleteNode(tempPos); // delete at position, return success state
                if(result ==  0){ // if 0 is returned from method then deletion was sucesful 
                    cout << "\nDeletion succesful, node at index " << tempPos << " was deleted.\n\n";
                }
                else{ // if the method returns -1 then the index was invalid 
                    cout << "\nDeletion failed, index does not exist.\n\n";
                }
            break;
            case 4: // print list
                list.printList(); 
            break;
            case 5: // reverse list
                list.reverse();
            break;
            case 6: // search list
                tempInput = getStringInput("Enter a primary color to search for: ","Invalid input, enter a valid primary color: "); //get primary color from user
                result = list.search(tempInput); // search the list and capture success state in result
                if(result != -1){ // result in this case will hold the index position of the first occurance of color
                    cout << "\nFound first instance of \"" << tempInput << "\" at index "<< result << "\n\n";
                }
                else{ // -1 is returned if there is no instance of color
                    cout << "\nNo instance of \"" << tempInput << "\" in the list.\n\n";
                }
            break;
            case 7: 
            cout << "\nSee you later. Kevin Morales-Nguyen PA 18\n";
            return;
            default: // default : option selection error
            display_error();
            break;
        }
    }
}

//this method is used to display the menu options and get a choice from the user.
int display_menu(){
    int temp_choice;
    cout << "1. append list\n" 
        << "2. insert node\n"
        << "3. delete node\n"
        << "4. print list\n"
        << "5. reverse list\n"
        << "6. search list\n"
        << "7. Exit.\n";
    cout << "\nEnter your choice: ";
    cin >> temp_choice;
    return temp_choice;    
} 

//if the user did not enter 1-8 then an error is displayed, if they entered a character the fail bit is cleared.
void display_error(){
    cout << "\nPlease enter a valid option from the menu(1-7).\n\n";
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
    valid = charCheck(input); // check if string contains a character, even a negative would not work
                              // so technically only positive integers are allowed
    while(!cin || !valid || input == ""){ // if input is bad ask user again
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

// this function is used to get a string from the user, pretty simple we just use getline(cin,<var>)
string getStringInput(string prompt, string error){
    string input = "-1";
    cout << prompt;
    cin.ignore();
    getline(cin,input);
    while(!cin || (input != "red" && input != "blue" && input != "yellow")){ // high-level input validation for primary color
        cout << error << endl;
        cin.clear();
        cout << prompt;
        getline(cin, input);
    }
    return input;
}

//this function is used to check if the string contains a character, an integer should have no chars, 
//except possible '-' sign which is not implemented
bool charCheck(string temp){
    for(char e:temp){
        if(!isdigit(e)){
            return false;
        }
    }
    return true;
}