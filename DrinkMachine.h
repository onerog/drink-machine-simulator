#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype> 
#include <cmath>

#include "Queue.h"

struct Drink {
	// This structure holds information
	// about a single drink of drink machine.

	// This field holds drink name
	string name;

	// represents the cost of a single drink
	double cost;

	// represent the available number of drinks
	// in the machine,
	// 0 when all are sold out
	int numberAvailable;

};


// =============================================================
//                      Functions
void resetDrinks(Drink*& drinks, const int size);
void initializeDrinks(Drink*&, const int);
void displayDrinks(const Drink*, const int);
double processRequest(Drink*, const int);
// =============================================================


// =============================================================


// This variable holds the number of products
	// we have and so the size of the array after initialization
const int numberOfDrinks = 3;

// =============================================================


// The system has 3 types


// The following array defines the names of drinks
const string names[3] = { "Coke","Pepsi","Soda" };

// defines the cost of each drink type
const double costOfEachDrink[3] = { 0.25,0.35,0.45 };

// defines the number of pieces available for each type
const int pieces[3] = { 20,20,20 };

// =============================================================
