#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;


#ifndef QUEUE1_H
#define QUEUE1_H



class Queue1
{
private:


	// Structure for the queue nodes
	struct QueueNode
	{
		double value; // Value in a node
		QueueNode* necoint; // Pointer to the necoint node
	};

	QueueNode* head; // The front of the queue
	QueueNode* tail; // The tail of the queue
	int numItems; // Number of items in the queue
public:
	// Constructor
	Queue1();

	// Destructor
	~Queue1();

	// Queue operations
	void enqueue(double);
	void dequeue(double&);
	bool isEmpty() const;
	void clear();

};
#endif
