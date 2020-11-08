/*Date: 6/9/2020
*Name: Kevin Morales-Nguyen
*Assignment: Functions and Arrays, Chapters 6&7
*/

#include <stdio.h>
#include <iostream>

using namespace std;

//declare constants for row and column size to be used throughout program.
const int ROWS = 5;
const int COLS = 5;

//function prototypes

//these three functions are the main drivers of the program that work with I/O.
void menu_driver(char [][COLS]);
int display_menu();
void display_error();

//four primary array processing functions,the functions have two extra parameters for row
//and colmn size of matrix so that the program can be more modular, array arg is integral.
void swap_columns(char [][COLS], int, int, int);
void count_vowels(char [][COLS], int, int);
void display_2d_array(char [][COLS], int, int);
void count_instances(char [][COLS], int, int);

//initialize the 2d array and spin up the menu.
int main()
{
    //initialize 2d array with char elements as assignment specifies.
    char words[ROWS][COLS] = {
        {'s','w','e','e','t'},
        {'h','e','a','r','t'},
        {'e','g','r','i','t'},
        {'c','l','o','n','e'},
        {'o','d','o','r','s'}};
        
    menu_driver(words);

    return 0;
}

//this method asks the used to input a option from the menu.
void menu_driver(char my_array[][COLS]){
    int choice = 0;
    while(choice != 5){
        choice = display_menu();    // get menu choice form user
        switch(choice){ 
            case 1: //option 1: swap columns
            swap_columns(my_array,ROWS,0,3);    
            break;
            case 2: //option 2: count number of vowels
             count_vowels(my_array,ROWS,COLS);
            break;
            case 3: //option 3: display array
            display_2d_array(my_array,ROWS,COLS);
            break;
            case 4: //option 4: count instances of character
            count_instances(my_array,ROWS,COLS);
            break;
            case 5: //option 5: exit program
            cout << "\nSee you later. Kevin Morales-Nguyen PA 6&7\n";
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

//this function swaps the columns of a array specified by the arguements, included column arguements for modularity.
void swap_columns(char arr[][COLS], int rows, int column1, int column2){
    char temp = 0;
    for(int i = 0; i < rows; i++){
        temp = arr[i][column1]; // save element 1 into temp
        arr[i][column1] = arr[i][column2];  // replace elemnt 1 with element 2
        arr[i][column2] = temp; // save temp into element 2 
    }
    cout << "\nColumns 1 and 4 have been swapped.\n\n";
}

//this function counts the total number of vowels in the char array.
void count_vowels(char arr[][COLS], int rows, int cols){
    char temp = 0;
    int vowel_count = 0;
     for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            temp = tolower(arr[i][j]);
            if(temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u'){ // relevent conditionals
                vowel_count++;
            }
        }
    }
    cout << "\nI counted " << vowel_count << " vowels in the 2d array.\n\n";
}

//this function displays the 2d array.
void display_2d_array(char arr[][COLS], int rows, int cols){
    cout << "\nPrinted array:\n";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << arr[i][j] << " ";    
        }
        cout << "\n";
    }
    cout << "\n";
}

//this function counts the number of instances of a character in an array.
void count_instances(char arr[][COLS], int rows, int cols){
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
            temp = arr[i][j];
            if(temp == instance[0]){
                instance_count++;
            }
        }
    }
    cout << "\nI counted " << instance_count << " instance(s) of your character \'" 
        << instance << "\'.\n\n";
}



