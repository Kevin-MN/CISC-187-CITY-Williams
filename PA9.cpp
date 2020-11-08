/*Date: 6/20/2020
*Name: Kevin Morales-Nguyen
*Assignment: Pointers, Chapter 9
*
*Fore-note: The general formula used to access elements in a 2d sense, with the use of a double for-loop.
*     
*   arr[i][j] = (ptr + (i * rows) + j)
*
*   Where ptr is the memory location of the first elemnt
*   and the row,  i = (i * rows)
*   and the column  j = j 
*
*   Because array elemnts are store adacently this formula is intuitive to understand and use to address 
*   elemnts in place of subscripting. The dereference operator is used to obtain the value that the 
*   pointer points to.
*/

#include <stdio.h>
#include <iostream>

using namespace std;

//declare constants for size,row, and column size to be used throughout program.
const int ROWS = 5;// the row and col size is important to know because we still
const int COLS = 5;// treat the 1d array like a 2d array

//function prototypes

//these three functions are the main drivers of the program that work with I/O.
void menu_driver(char *);// now uses char pointer
int display_menu();
void display_error();

//four primary array(pointer) processing functions,the functions have two extra parameters for row
//and colmn size of matrix so that the program can be more modular, pointer arg is integral.
void swap_columns(char *, int, int, int);   //all functions now accept char pointers
void count_vowels(char *, int, int);
void display_2d_array(char *, int, int);
void count_instances(char *, int, int);

//initialize the 1d array and spin up the menu.
int main()
{
    //initialize 1d array with char elements as assignment specifies, but still operate and 
    //access elemnents as if it were a 2d array.
    char words[ROWS * COLS] = {
        's','w','e','e','t',
        'h','e','a','r','t',
        'e','g','r','i','t',
        'c','l','o','n','e',
        'o','d','o','r','s'};
        
    char *wrdptr = words; // initialize char pointer variable to address(first element) of
                          // words in memory.
    
    menu_driver(wrdptr);  // program uses char pointer instead of array

    return 0;
}

//this method asks the used to input a option from the menu.
void menu_driver(char *address){
    int choice = 0;
    while(choice != 5){
        choice = display_menu();    // get menu choice form user
        switch(choice){ 
            case 1: //option 1: swap columns
            swap_columns(address,ROWS,0,3);    
            break;
            case 2: //option 2: count number of vowels
            count_vowels(address,ROWS,COLS);
            break;
            case 3: //option 3: display array
            display_2d_array(address,ROWS,COLS);
            break;
            case 4: //option 4: count instances of character
            count_instances(address,ROWS,COLS);
            break;
            case 5: //option 5: exit program
            cout << "\nSee you later. Kevin Morales-Nguyen PA 9\n";
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
    cout << "1. Switch columns 1 and 4\n" 
        << "2. Display the total number of vowels\n"
        << "3. Display the array\n"
        << "4. Count the number instances of a given character\n"
        << "5. Exit\n";
    cout << "\nEnter your choice: ";
    cin >> temp_choice;
    return temp_choice;    
}

//if the user did not enter 1-5 then an error is displayed, if they entered a character the fail bit is cleared.
void display_error(){
    cout << "\nPlease enter a valid option from the menu(1-5).\n\n";
    if(cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
    }
}

//this function swaps the columns of a array pointed too by the pointer arguement by the arguements, included column arguements for modularity.
void swap_columns(char *ptr, int rows, int column1, int column2){
    char temp = 0;
    for(int i = 0; i < rows; i++){
        temp = *(ptr + (i * rows) + column1); // use dereference operator to obtain value held by pointer
        *(ptr + (i * rows) + column1) =  *(ptr + (i * rows) + column2); // swap elements using pointer arithmetic
        *(ptr + (i * rows) + column2) = temp; // save temp 
    }
    cout << "\nColumns 1 and 4 have been swapped.\n\n";
}

//this function counts the total number of vowels in the char array, the array is still treated as a 
//2d array so the double for-loop is kept instead of a single for-loop that is size of 1d array.
void count_vowels(char *ptr, int rows, int cols){
    char temp = 0;
    int vowel_count = 0;
     for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            temp = tolower(*(ptr + (i * rows) + j));
            if(temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u'){ // relevent conditionals
                vowel_count++;
            }
        }
    }
    cout << "\nI counted " << vowel_count << " vowels in the 2d array.\n\n";
}

//this function displays the 1d array as a 2d array by using pointer arithmetic to access elemnts.
void display_2d_array(char *ptr, int rows, int cols){
    cout << "\nPrinted array:\n";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << *(ptr + (i * rows) + j) << " ";    
        }
        cout << "\n";
    }
    cout << "\n";
}

//this function counts the number of instances of a character in an array.
void count_instances(char *ptr, int rows, int cols){
    string instance = "k";
    char temp = 0;
    int instance_count = 0;
    cout << "\nEnter the character you are looking for: ";
    cin >> instance;
    if(instance.size() > 1){ // if the array is not length one then the user did not enter a single character
        cout << "\nPlease enter a single character.\n\n";
        return;
    }
     for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            temp = *(ptr + (i * rows) + j);
            if(temp == instance[0]){
                instance_count++;
            }
        }
    }
    cout << "\nI counted " << instance_count << " instance(s) of your character \'" 
        << instance << "\'.\n\n";
}







