/**Date:7/22/2020
 * Name:Kevin Morales-Nguyen
 * Assignment: Recursion and Queue's, Chapter 20
 * 
 * This file contains the main method and various functions to implement the desired menu features while also containing high level validation 
 * */
#include "DriveThruQueue.h"
#include <iostream>
#include <string>
using namespace std;

//functions used in main that work with both lists in main to build story, they are also used to implement high-level validation
void append(DriveThruQueue &); // we also use reference variable because we do not want to work with a copy of the object, we pass reference of created stacks
void placeOrder(DriveThruQueue &);
void countCars(DriveThruQueue &);
void moveKids(DriveThruQueue &);
void letFriend(DriveThruQueue &);
void displayQueue(DriveThruQueue &);

//functions used to create "menu-driven" program
void menu_driver(DriveThruQueue);
int display_menu();
void display_error();

//functions for getting user input, validation is implemented for primary colors
string getStringInput(string,string);
int getIntInput(string,string);

//functions for validating string on criteria
bool charCheck(string);

int main()
{
    DriveThruQueue inNout; // create drive thru queue
    menu_driver(inNout);
    return 0;
}

//this method asks the user to input a option from the menu.
void menu_driver(DriveThruQueue queue){
    int choice = 0;     //variables used for user input
    while(choice != 7){
        choice = display_menu();    // get menu choice form user
        switch(choice){ 
            case 1: //append
                append(queue);
            break;
            case 2: //place order
                placeOrder(queue);
            break;
            case 3: //count cars
                countCars(queue);
            break;
            case 4: //move kids
                moveKids(queue);
            break;
            case 5: //let in friend
                letFriend(queue);
            break;
            case 6:// display queue
                displayQueue(queue);
            break;
            case 7: //exit
            cout << "\nSee you later. Kevin Morales-Nguyen PA 20 - Recursion and Queue's\n";
            return;
            default: // default : option selection error
            display_error();
            break;
        }
    }
}

//This function is used to call the append member method on the queue passed by reference, getStringInput() already 
//implements the 20 char check for high level validation and getIntInput() only excepts 0 and positive integers
void append(DriveThruQueue &queue){
    string tempname = getStringInput("Name of customer: ","Invalid name: make sure name is less than 20 characters and not empty.");
    int kids = getIntInput("Number of kids: ","Invalid input: number of kids must be zero or more.");
    queue.append(tempname,kids);
    cout <<"\n" << tempname << " has been added to the queue\n\n";
}

//This function calls the placeOrder() member method which removes the node at the front of the queue and 
//displays a message
void placeOrder(DriveThruQueue &queue){
    if(queue.isEmpty()){ // high level vaalidatio for empty queue
       cout << "\nQueue is empty!\n\n"; 
    }
    else{
        queue.placeOrder();
    }
}

//This function calls the countCars() member method
void countCars(DriveThruQueue &queue){
    int count = queue.countCars();
    cout << "\nThere are " << count << " cars in the queue.\n\n";
}

//this funciton calls the moveKids() member method
void moveKids(DriveThruQueue &queue){
    if(queue.isEmpty()){
        cout << "\nQueue is empty!\n\n"; 
    }
    else{
        queue.moveKids();
    }
}

//This funciton calls the letInFriend() member method
void letFriend(DriveThruQueue &queue){
    if(queue.isEmpty()){ // high level validation for empty queue
        cout << "\nQueue is empty!\n\n"; 
    }
    else{
        string tempname = getStringInput("Name of friend: ","Invalid name: make sure name is less than 20 characters and not empty.");
        queue.letInFriend(tempname);
    }
}

//This function calls the printQueue() member method
void displayQueue(DriveThruQueue & queue){
    if(queue.isEmpty()){// high level validation for empty queue
        cout << "\nQueue is empty!\n\n"; 
    }
    else{
        queue.printQueue();
    }
}

//this method is used to display the menu options and get a choice from the user.
int display_menu(){
    int temp_choice;
    cout << "1. Append name to end of queue\n" 
        << "2. Let front of line order and exit queue\n"
        << "3. Count cars\n"
        << "4. Move car with most kids to front of queue\n"
        << "5. Move friend to front of queue\n"
        << "6. Display queue\n"
        << "7. Exit\n";
    cout << "\nEnter your choice: ";
    cin >> temp_choice;
    return temp_choice;    
} 

//if the user did not enter 1-9 then an error is displayed, if they entered a character the fail bit is cleared.
void display_error(){
    cout << "\nPlease enter a valid option from the menu(1-7).\n\n";
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
    }
}

// this function is used to get a string from the user, pretty simple we just use getline(cin,<var>)
string getStringInput(string prompt, string error){
    string input = "-1";
    cout << prompt;
    cin.ignore();
    getline(cin,input);         // high-level input validation for name that is not empty and less than 20 chars
    while(!cin || input == "" || input == " " || input == "\n" || input == "\r" || input.size() >= 20 || input.size() == 0){ 
        cout << error << endl;
        cin.clear();
        cout << prompt;
        getline(cin, input);
    }
    return input;
}

//this function is used to get an integer from the user, getline is used and then string in converted
int getIntInput(string prompt, string error){
    string input = "-1";
    bool valid;
    cout << prompt;
    getline(cin,input);
    valid = charCheck(input); // check if string contains a character, even a negative would not work
                              // so technically only zero and positive integers are allowed
    while(!cin || !valid || input == ""){ // if input is bad ask user again, highlevel validation for zero or positive integers
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