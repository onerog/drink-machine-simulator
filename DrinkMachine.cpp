#include "DrinkMachine.h"

using namespace std;

//This function allows the supplier to “reset” and refill each
//product to 20 cans after the reset.
void resetDrinks(Drink*& drinks, const int size)
{
	int pieces[3] = { 20,20,20 };

	// This loop assigns each value to the corresponding
	// structure in the structure array
	for (int i = 0; i < size; i++) {
		cout << "============================================ \n";
		cout << "refill amount for :" << drinks[i].name << "=" << pieces[i] - drinks[i].numberAvailable << endl;
		drinks[i].numberAvailable = pieces[i];

	}

}



// =============================================================
void initializeDrinks(Drink*& drinks, const int size) {


	// dynamically allocating the array of structures
	drinks = new Drink[size];


	// This loop  assigns each value to the corresponding structure in the structure array
	for (int i = 0; i < size; i++) {
		drinks[i].name = names[i];
		drinks[i].cost = costOfEachDrink[i];
		drinks[i].numberAvailable = pieces[i];
	}

}
// =============================================================
void displayDrinks(const Drink* DRINKS, const int SIZE) {
	// This function displays all the available drinks

	cout << setw(5) << left << "#" << setw(15) << left << "Drink Name"
		<< "Cost";
	// right align again
	cout << setw(20) << right << "Number in Machine" << endl;
	cout << "-------------------------------------------- \n";
	// =========================================================
	// Now loop over all the products and show them,
	for (int i = 0; i < SIZE; i++) {
		cout << setw(5) << left << (i + 1) << setw(15) << left << DRINKS[i].name << setw(4) << left << setprecision(2) << setfill('0') << DRINKS[i].cost;
		cout << setfill(' ');
		cout << setw(20) << right << DRINKS[i].numberAvailable << endl;
	}
	cout << "============================================ \n";


}
// =============================================================
double processRequest(Drink* drinks, const int INDEcoin) {
	// This function processes a user's request
	// in the array "drinks".
	// and returns the earned money from the request
	cout << "============================================ \n";
	// if there were not any drinks of the type he wants
	// show an informative message,
	if (drinks[INDEcoin].numberAvailable <= 0) {
		// show an error message and return 0
		// as no money would be earned

		cout << drinks[INDEcoin].name << "  were all sold out.\n";
		cout << "[ Remaining pieces : \"0\" ]\n";
		return 0;
	}





	// holds the amount of money the user enters into the drink machine in the queue
	double totalmoney = 0.0;

	// holds the amount of money the user enters to check if money is enough to buy the selected product
	double total = 0.0;

	// assigns money names to a double value
	double a = 0.0;

	// Create a Queue1 object.
	Queue1 iQueue;

	//holds entered coin names
	string coin;

	cout << " Please enter nickel, dime or quarter \n";
	getline(cin, coin);

	// this function asks user to enter nickel, dime, quarter or end when money adding is ended 
	// and converts money into integer and calculates the total amount of money entered by th user
	// this function also  adds each money inserted into queue 

	do
	{

		getline(cin, coin);

		if (coin == "nickel") {
			a = 0.05;


			iQueue.enqueue(a); // adds the coin to the queue
			total += a;
			cout << "Total money inserted: $" << total << endl;
			cout << " Please enter nickel, dime or quarter --or type 'dispense' to end payment \n";

		}
		else if (coin == "dime") {
			a = 0.10;


			iQueue.enqueue(a);  // adds the coin to the queue
			total += a;
			cout << "Total money inserted: $" << total << endl;
			cout << " Please enter nickel, dime or quarter --or type 'dispense' to end payment \n";

		}

		else if (coin == "quarter") {
			a = 0.25;


			iQueue.enqueue(a);  // adds the coin to the queue
			total += a;
			cout << "Total money inserted: $" << total << endl;
			cout << " Please enter nickel, dime or quarter --or type 'dispense' to end payment \n";

		}




		else if (coin != "dispense") {

			cout << "Invalid entry. Please enter nickel, dime or quarter, type 'dispense' to end payment \n";


		}

	} while (coin != "dispense");  // ends coin entering and proceeds to next step



		//this function checks if inserted money is enough to buy the selected product.

	if (total == 0 || (total < drinks[INDEcoin].cost))
	{
		cout << "--------------------------------------------\n";
		cout << "This is not a valid amount of money,\n";
		cout << "We do not accept money less than the cost of\n";
		cout << "your product which is $" << drinks[INDEcoin].cost << endl;
		cout << "\nYour money : $" << total << endl;
		while (!iQueue.isEmpty())
		{
			double value = 0.0;

			// this function dequeues and retrieves all values in the queue
			//if entered money amount is not enough, money is dispended back
			iQueue.dequeue(value);

			if (value == 0.05)
				cout << "refund nickel\n" << endl;
			else if (value == 0.10)
				cout << "refund dime\n" << endl;
			else if (value == 0.25)
				cout << "refund quarter\n" << endl;

		}
		iQueue.clear();        // clears the queue
		return 0;      // ends this function here
	}

	else
	{
		while (!iQueue.isEmpty())
		{
			double value = 0.0;

			// this function dequeues and retrieves all values in the queue
			iQueue.dequeue(value);
			cout << "The values in the queue were:\n";
			if (value == 0.05)
				cout << " nickel\n" << endl;
			else if (value == 0.10)
				cout << "dime\n" << endl;
			else if (value == 0.25)
				cout << "quarter\n" << endl;
			totalmoney += value;   // calculated the total amount of money inserted.
			cout << value << endl;

		}
		cout << "Total money inserted: $" << totalmoney << endl;

		cout << "--------------------------------------------\n";

		double drinkAmount = 0.0;

		//calculates number of drinks by dividing totalmoney to cost

		drinkAmount = totalmoney / drinks[INDEcoin].cost;

		int realDrinkAmount = 0;

		// truncates number of drinks from double to int

		realDrinkAmount = static_cast<int>(drinkAmount);

		double change = 0.0;

		//calculates change amount by subtracting number of drinks times cost of each drink from total amount of money

		change = (totalmoney - drinks[INDEcoin].cost * realDrinkAmount);





		//shows change amount
		cout << "Your change is : $" << setprecision(3)
			<< change << "\n";
		cout << "Have a nice day.\n";

		// now subtract 1 from the number of pieces
		drinks[INDEcoin].numberAvailable -= realDrinkAmount;
		iQueue.clear();      // clears the queue
		return drinks[INDEcoin].cost * realDrinkAmount;   // returns earned money amount
	}


}