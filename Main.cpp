#include <iostream>
#include <iomanip>
#include <string>
#include <cctype> 
#include <cmath>

#include "DrinkMachine.h"

using namespace std;



int main() {

	// define a pointer which  points to the array of
	// of drinks, representing the drinks information in
	// our drink machine after initialization
	Drink* drinks = nullptr;





	// this variable holds the total amount of money
	// the machine earned through its operation.
	double earned = 0;


	// used to get user choice of the menu
	char choice;

	// ---------------------------------------------------------
	// Initialize the drinks array, and load its size
	initializeDrinks(drinks, numberOfDrinks);


	displayDrinks(drinks, numberOfDrinks);
	cout << "Make your choice : Coke(c),Pepsi(p),Soda(s),Quit(q),Reset(r)? \n";


	// =========================================================
	// loop showing the menu and selling,
	do {


		cin.get(choice);

		if (choice == 'c') {
			earned += processRequest(drinks, 0);

			displayDrinks(drinks, numberOfDrinks);
			cout << "Make your choice : Coke(c),Pepsi(p),Soda(s),Quit(q),Reset(r)? \n";
			cout << "============================================ \n";
		}
		else if (choice == 'p') {
			// He picked a drink, process his request
			earned += processRequest(drinks, 1);

			displayDrinks(drinks, numberOfDrinks);
			cout << "Make your choice : Coke(c),Pepsi(p),Soda(s),Quit(q),Reset(r)? \n";
			cout << "============================================ \n";
		}
		else if (choice == 's') {
			earned += processRequest(drinks, 2);

			displayDrinks(drinks, numberOfDrinks);
			cout << "Make your choice : Coke(c),Pepsi(p),Soda(s),Quit(q),Reset(r)? \n";
			cout << "============================================ \n";

		}
		else if (choice == 'r')
		{

			resetDrinks(drinks, numberOfDrinks);
		}
		else if (choice != 'q') {
			cout << "Wrong movee, try again \n";

			displayDrinks(drinks, numberOfDrinks);
			cout << "Make your choice : Coke(c),Pepsi(p),Soda(s),Quit(q),Reset(r)? \n";
			cout << "============================================ \n";
		}


	} while (choice != 'q');
	// =========================================================
	// the program closes, shows the money earned


	cout << "The earned money in this session was : $"
		<< setprecision(3) << earned << "\n";
	cout << "-------------------------------------------- \n";



	cout << "============================================ \n";

	// release the resources
	delete[] drinks;
	drinks = nullptr; //to prevent memory leak
	return 0;
}
