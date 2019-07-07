#include "Queue.h"

using namespace std;



//********************************************
 // The constructor creates an empty queue. *
 //********************************************

Queue1::Queue1()
{
	head = nullptr;
	tail = nullptr;
	numItems = 0;
}

//********************************************
// Destructor *
//********************************************
Queue1::~Queue1() {
	clear();
}

//*********************************************
// Function enqueue inserts the value in num *
// at the tail of the queue. *
//*********************************************

void Queue1::enqueue(double num)
{
	QueueNode* newNode = nullptr;

	// Create a new node and store num there.
	newNode = new QueueNode;
	newNode->value = num;
	newNode->necoint = nullptr;

	// Adjust front and tail as necessary.
	if (isEmpty())
	{
		head = newNode;
		tail = newNode;
	}

	else
	{
		tail->necoint = newNode;
		tail = newNode;
	}

	// Update numItems.
	numItems++;

}

//**********************************************
// Function dequeue removes the value at the *
// front of the queue, and copies it into num. *
//**********************************************

void Queue1::dequeue(double& num)
{
	QueueNode* temp = nullptr;

	if (isEmpty())
	{
		cout << "The queue is empty.\n";
	}
	else
	{
		// Save the front node value in num.
		num = head->value;

		// Remove the front node and delete it.
		temp = head;
		head = head->necoint;
		delete temp;

		// Update numItems.
		numItems--;
	}
}

//*********************************************
// Function isEmpty returns true if the queue *
// is empty, and false otherwise. *
//*********************************************

bool Queue1::isEmpty() const
{
	bool status;

	if (numItems > 0)
		status = false;
	else
		status = true;
	return status;
}

//********************************************
 // Function clear dequeues all the elements *
	// in the queue. *
	//********************************************

void Queue1::clear()
{
	double value; // Dummy variable for dequeue

	while (!isEmpty())
		dequeue(value);
}

//-------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------


