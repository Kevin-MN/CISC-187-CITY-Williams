/**Date: 6/30/2020
 * Name: Kevin Morales-Nguyen
 * Assignment: Classes, Chapter 13
 * 
 * This file contains the main method, where the array of inventory items are 
 * instantiated and then the private members of each object are set via
 * user input. This file also contains other functions used for getting valid 
 * input and checking of a string could be considered a float or int. They 
 * may not be perfect but they stamp out a lot of errors with user input 
 * that could arrise had they not been implemented.
 *
 * !!!!!READ THIS. I lost 9 points on this assignment because I did not correctly implement the input validation. 
 * Check my later assignments to see how I implemented it correctly so you  can get full points. !!!!!!!!!
 * */
#include <iostream>
#include <string>   //going to need because we are working with strings
#include <iomanip>  // used for nice output
#include "inventory.h" // the file that contains the class definitions

using namespace std;

const int SIZE = 5; // Size of the Inventory array specified in instructions

// function that initialize Invetory objects with user input
void initializeInventory(Inventory[SIZE], int);
//function that prints out the private members of the Inventory object
void printInventory (Inventory[SIZE], int);
//function that returns a unique int if the user entered a repeating check-in number
int repeatCheck(Inventory [SIZE], int, int);
//funtion used by repeatCheck to see if the check-in number has already neem entered
bool repeatCheck2(Inventory[SIZE], int, int);
//functions used for validating input
int getIntInput(string,string);
float getFloatInput(string,string);
string getStringInput(string,string);
//functions for validating string on criteria
bool charCheck(string);
bool alphaCheck(string);
bool floatCheck(string);

int main ()
{
    cout << "Mr.Ding Surf Shop and Board Repair!\n\n";
    // create Inventory array to contain 5 objects
    Inventory inventory[SIZE];
    // set the member variables of each object in array 
    initializeInventory(inventory, SIZE);
    // print out the member variables of each object in array and display total
    printInventory (inventory, SIZE);
    https://www.onlinegdb.com/edit/rJSYV3IA8#tab-stderr
    cout << "\n\nPA Chapter 13, Kevin Morales-Nguyen" << endl;

  return 0;
}

//this function will use the input validation functions and the Inventory class mutators to set the 
// private data members of each Invetory object in the array passed as an arguement
void initializeInventory(Inventory arr[SIZE], int size){
    /**
     * So I created temporary varialbes and then passed them to the class mutators but I could of cut the 
     * code in half by using the following form, 
     * 
     *  arr[i].setCheckInNumber(getIntInput("Check-in number: ", "Invalid check-in number, please try again."));
     * 
     * I did not use it because I figured it would be safer? to just use temp variables and then pass them as arguements.
     * Let me know if I should of done it as seen above, honestly I can not find a reason not to but idk.
     * */
    
    //temp varialbes to hold data
    int tempChkNum;
    string  tempDamageDesc;
    string tempCustomerLast;
    string tempCustPhone;
    float tempPriceQuoted;
    float tempHoursWorked;
    //for each object in the Inventory array, call the input function to gather user input and then 
    //use the appropriate class mutator to set the private data member.
    for(int i = 0; i < size; i++){
        tempChkNum = getIntInput("Check-in number: ", "Invalid check-in number, please try again.");  
        tempChkNum = repeatCheck(arr, size, tempChkNum); // check to see if user entered unique check-in number
        arr[i].setCheckInNumber(tempChkNum);
        tempDamageDesc = getStringInput("Damage: ", "Invalid description length, please try again.");
        arr[i].setDamageDesc(tempDamageDesc);
        tempCustomerLast = getStringInput("Customer last name: ", "Invalid name length, please try again.");
        arr[i].setCustomerLast(tempCustomerLast);
        tempCustPhone = getStringInput("Customer phone: ", "Invalid number length, please try again.");
        arr[i].setCustPhone(tempCustPhone);
        tempPriceQuoted = getFloatInput("Quote: ", "Invalid quote amount, please try again.");
        arr[i].setPriceQuoted(tempPriceQuoted);
        tempHoursWorked = getFloatInput("Hours: ", "Invalid amount of time, please try again.");
        arr[i].setHoursWorked(tempHoursWorked);
        cout << endl << endl;
    }
}

//This function prints out the private data members of each object in the Inventory array, and also 
//displays the total of all the quotes.
void printInventory (Inventory arr[SIZE], int size)
{
    //variable for total of quotes
    float total = 0;
    
    // for each object print out the private data members using class accessors, add total from each object
  for (int i = 0; i < size; i++)
    {
        cout << left << setw(20) << "Check-In Number: " << arr[i].getCheckInNumber() << endl;
        cout << left <<setw(20) << "Damage: " <<  arr[i].getDamageDesc() << endl;
        cout << left <<setw(20) << "Customer: " << arr[i].getCustomerLast() << endl;
        cout << left <<setw(20) << "Phone: "  <<  arr[i].getCustPhone() << endl;
        cout << left <<setw(20) << "Quote: " << "$" <<  arr[i].getPriceQuoted() << endl;
        cout << left <<setw(20) << "Hours: "  <<  arr[i].getHoursWorked() << endl << endl;
        total += arr[i].getPriceQuoted(); // add total
    }
    cout << "---------------------------" << endl;
    cout << "Total of all quotes: $" <<fixed << setprecision(2) <<  total;
}

//this funciton is used to make sure that the user does not enter a check-in 
//number that is already associated with an object in the array
int repeatCheck(Inventory arr[SIZE], int size, int num){
    int temp;
    bool repeat;
    for(int i = 0; i < size; i++){
        if(arr[i].getCheckInNumber() == num){ // if the user initially enters a repeated check-in number, enter
            do{ // keep prompting user for a unique check-in number
            cout << "\nCheck-in number already used please enter valid check-in number.\n\n";
            temp = getIntInput("Check-in number: ", "Check-in number already used please enter valid check-in number.");
            repeat = repeatCheck2(arr,size,temp); // check if re-entered value has been entered already
            }
            while(temp == num || repeat);
            return temp; // return unique check-in number
        }
    }
    return num;
}

//this function returns true if the check-in number already exists inside the array of Inventory objects
bool repeatCheck2(Inventory arr[SIZE], int size, int num){
    for(int i = 0 ; i < size;i++){
        if(arr[i].getCheckInNumber() == num){
            return true;
        }
    }
    return false;
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

//this function is used to get an float from a user, floatCheck() is used to validate string
float getFloatInput(string prompt, string error){
    string input = "-1";
    bool valid;
    
    cout << prompt;
    getline(cin,input);
    
    valid = floatCheck(input); 
    
    while(!cin || !valid || input == ""){
        cout << error << endl;
        cin.clear();
        cout << prompt;
        getline(cin, input);
        valid = floatCheck(input);
    }
    
    //convert to float, negatives allowed
    float temp = stof(input);
    return temp;
}

// this function is used to get a string from the user, pretty simple we just use getline(cin,<var>)
string getStringInput(string prompt, string error){
    string input = "-1";
   
    cout << prompt;
    getline(cin,input);
    
    while(!cin){
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

//this function is used to check if a string has a letter, number inputs chould not have letters
bool alphaCheck(string temp){
    for(char e: temp){
        if(isalpha(e)){
            return false;
        }
    }
    return true;
}

//this function checks if the string is a valid float
bool floatCheck(string temp){
    int negChar = 0; 
    int decChar = 0;
    for(char e: temp){
        if(isalpha(e)){ // false if there is a letter
           return false; 
        }
        else if(e == '-'){ // false if more than one '-' sign
            negChar++;
            if(negChar > 1){
                return false;
            }
            if(temp[0] != '-'){ // false if '-' sign is not at the front of the string
                return false;
            }
            continue;
        }
        else if(e == '.'){ // false if there is more than one decimal point
            decChar++;
            if(decChar > 1){
                return false;
            }
            continue;
        }
        else if(!isdigit(e)){ // false if there is any other special char that is not '-' sign or '.' decimal point
            return false;
        }
    }
    return true;
}