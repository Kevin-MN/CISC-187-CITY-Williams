/**Date: 6/30/2020
 * Name: Kevin Morales-Nguyen
 * Assignment: Classes, Chapter 13
 * 
 * This file contains the specifications of the Inventory class. Contains declared private data variables 
 * and prototypes for the constructors and methods of the class.
 * */
#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <string>

using namespace std;

class Inventory 
{
private:			
    // private member variables
    int checkInNumber;
    string damageDesc;
    string customerLast;
    string custPhone;
    float priceQuoted;
    float hoursWorked;
public:
    //constructors
    Inventory ();		// default constructor
    Inventory (int); // constructor with only check-in number arg
    Inventory (int, string, string, string, float, float);	// parameterized constructor

    //accessors
    int getCheckInNumber () const; // use constant values because we are not chaning anything
    string getDamageDesc () const;
    string getCustomerLast () const;
    string getCustPhone () const;
    float getPriceQuoted () const;
    float getHoursWorked () const;

    //mutators
    void setCheckInNumber (int);
    void setDamageDesc (string);
    void setCustomerLast (string);
    void setCustPhone (string);
    void setPriceQuoted (float);
    void setHoursWorked (float);

    //destructor
    ~Inventory ();
};
#endif
