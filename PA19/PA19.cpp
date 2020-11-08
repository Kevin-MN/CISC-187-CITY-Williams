/**Date:7/14/2020
 * Name:Kevin Morales-Nguyen
 * Assignment: Stacks, Chapter 19
 * 
 * This file contains the main method, where the two dynamic stacks are built and then managed by the menu option so that a story can be built.
 * There are various functions that are used to further compartmentalize the menu_driver so that it can be cleaned up and so that the validation can be 
 * do in respective methods.
 * */
#include "WordStack.h"
#include <iostream>
#include <string>
using namespace std;

//functions used in main that work with both lists in main to build story, they are also used to implement high-level validation
void makeStory(WordStack &,WordStack &); // we also use reference variable because we do not want to work with a copy of the object, we pass reference of created stacks
void printStacks(WordStack &,WordStack &);
void pushWord(WordStack &,bool);
void popWord(WordStack &, bool);
void concatenateNouns(WordStack &);
void addSNoun(WordStack &);

//functions used to create "menu-driven" program
void menu_driver(WordStack,WordStack);
int display_menu();
void display_error();

//functions for getting user input, validation is implemented for primary colors
string getStringInput(string,string);

int main()
{
    WordStack nouns; // create noun stack
    WordStack verbs; // create verb stack
    menu_driver(nouns,verbs);
    return 0;
}

//this method asks the used to input a option from the menu.
void menu_driver(WordStack nounstack, WordStack verbstack){
    int choice = 0;     //variables used for user input
    string catchVal = "";
    int tempPos = 0;
    int result = -100; // this variable is used to hold the value returned 
                        //by methods with index checking, -1 is returned if invalid index/dne
    while(choice != 9){
        choice = display_menu();    // get menu choice form user
        switch(choice){ 
            case 1: //push noun
                pushWord(nounstack,true);
                //pushWord(nounstack,true);
            break;
            case 2: //pop noun
                popWord(nounstack,true);
            break;
            case 3: //push verb
                pushWord(verbstack,false);
            break;
            case 4: //pop verb
                popWord(verbstack,false);
            break;
            case 5: //concatenate
                concatenateNouns(nounstack);
            break;
            case 6: //add 's'
                addSNoun(nounstack);
            break;
            case 7: //display both stacks
                printStacks(nounstack,verbstack);
            break;
            case 8: // make story
                makeStory(nounstack,verbstack);
            break;
            case 9: //exit
            cout << "\nSee you later. Kevin Morales-Nguyen PA 19 - Stacks\n";
            return;
            default: // default : option selection error
            display_error();
            break;
        }
    }
}

//This funciton is used to print out both stacks, uses reference variables
void printStacks(WordStack &nounstack, WordStack &verbstack){
    cout << "\nNoun Stack:\n";
    if(nounstack.isEmpty()){ // high-level validation for verbstack
        cout << "\nNoun stack is empty!\n\n";
    }
    else{
        nounstack.printStack();
    }
    cout <<"Verb Stack:\n";
    if(verbstack.isEmpty()){ // High level validation for verbstack
         cout << "\nVerb stack is empty!\n\n";
    }
    else{
    verbstack.printStack();
    }
}
//This function is used to pushWords to a stack specified in the arguement,  true for noun, false for verb
void pushWord(WordStack &stack,bool type){
    string temp = "";
    if(type == true){ //High-Level validation is implemented in getStringInput().
        temp = getStringInput("Enter a noun: ", "Invalid input, nothing was entered or word had more than 10 characters.");//get valid user input
    }
    else{
        temp = getStringInput("Enter a verb: ", "Invalid input, nothing was entered or word had more than 10 characters.");//get valid user input
    }
    stack.push(temp); // call push on stack object
}

//This function is used to pop words from a stack, the boolean is used to determine whether we are working with the noun or verb stack so I/O is cleaner
void popWord(WordStack &stack, bool type){
    string typew;
    string temp = "";
    if(type){
        typew = "Noun";
    }
    else{
        typew = "Verb";
    }
    
    if(stack.getStackSize() == 0){ // high-level validation for popping a word
        cout << "\n" << typew << " stack is empty!\n\n";
    }
    else{ // there are nodes
        stack.pop(temp); // call pop on stack 
    }
}

//this funciton is used to concatenate the top two words on the noun stack after making sure it is a valid operation
void concatenateNouns(WordStack &stack){
    if(stack.getStackSize() < 2){ // High-level validation for concatenation
        cout << "\nNeed minimum two words on noun stack!\n\n";
    }
    else{
        stack.concatenate();
    }
}
//This funciton is used to call the addS method after verifyign the operation is valid
void addSNoun(WordStack &stack){
    if(stack.isEmpty()){// high-level validation for adding 's' to top word of noun stack
        cout << "\nNoun stack is empty!\n\n"<<endl;
    }
    else{
        stack.addS(); // call addS on stack
    }
}

//This function is used to make a story after it has been verified that each stack has 4 words, we use the overloaded pop() method so that it is easier to print the story.
void makeStory(WordStack &nouns, WordStack &verbs){
    string capture = "";
    if(nouns.getStackSize() >= 4 && verbs.getStackSize() >= 4){ // validation for making a story, both stacks must have 4 or more words
        cout << "\nToday I _" << verbs.pop()<<"_ to a _" << nouns.pop() << "_.\nI saw a(n) _" << verbs.pop() << "_ _" 
             << nouns.pop() << "_ jumping up and down in its tree.\nIt _" << verbs.pop()
             << "_ quickly through the large tunnel that led to its _"
             << nouns.pop() <<"_.\nI was so confused I _" << verbs.pop() << "_ to _" << nouns.pop() << "_.\n\n";
    }
    else{
        cout << "\nNeed 4 nouns and 4 verbs to build story.\n\n";
    }
}

//this method is used to display the menu options and get a choice from the user.
int display_menu(){
    int temp_choice;
    cout << "1. push noun\n" 
        << "2. pop noun\n"
        << "3. push verb\n"
        << "4. pop verb\n"
        << "5. concatenate top two nouns \n"
        << "6. add 's' to top noun\n"
        << "7. display both stacks\n"
        << "8. make story\n"
        << "9. Exit.\n";
    cout << "\nEnter your choice: ";
    cin >> temp_choice;
    return temp_choice;    
} 

//if the user did not enter 1-9 then an error is displayed, if they entered a character the fail bit is cleared.
void display_error(){
    cout << "\nPlease enter a valid option from the menu(1-9).\n\n";
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
    getline(cin,input);                         // high-level input validation for noun/verb
    while(!cin || input == "" || input == " " || input == "\n" || input == "\r" || input.size() > 10 || input.size() ==0){ 
        cout << error << endl;
        cin.clear();
        cout << prompt;
        getline(cin, input);
    }
    return input;
}