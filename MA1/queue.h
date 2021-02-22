//
// Created by seal on 2/21/21.
//

#ifndef MAIN_CPP_QUEUE_H
#define MAIN_CPP_QUEUE_H
// This code was taken from https://www.techiedelight.com/queue-implementation-cpp/
// The code has been modified from the original to provide opportunities to learn

#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

// define default capacity of the queue
#define SIZE 10

// Class for queue
class queue
{
    int* arr;		// array to store queue elements
    int capacity;	// maximum capacity of the queue
    int front;		// front points to front element in the queue (if any)
    int rear;		// rear points to last element in the queue
    int count;		// current size of the queue

public:
    queue(int size = SIZE); 	// constructor
    ~queue();   				// destructor

    void dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
    int return_front(){
        return front;
    }
    int return_rear(){return rear;}
};

// Constructor to initialize queue
inline queue::queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Destructor to free memory allocated to the queue
inline queue::~queue() {
    delete arr; // you are not required to test this function;
    // however, are there issues with it?
}

// Utility function to remove front element from the queue
inline void queue::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        return;
    }

    cout << "Removing " << arr[front] << '\n';

    front = (front + 1) % capacity;
    count--;
}

// Utility function to add an item to the queue
inline void queue::enqueue(int item)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "OverFlow\nProgram Terminated\n";
        return;
    }

    cout << "Inserting " << item << '\n';

    rear = (rear + 1) % capacity;
    arr[rear] = item ;
    count++;
}

// Utility function to return front element in the queue
inline int queue::peek()
{
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        return  numeric_limits<int> ::min();
    }
    return arr[rear];
}

// Utility function to return the size of the queue
inline int queue::size()
{
    return count ;
}

// Utility function to check if the queue is empty or not
inline bool queue::isEmpty()
{
    return (size() == 0);
}

// Utility function to check if the queue is full or not
inline bool queue::isFull()
{
    return (size() == capacity);
}

#endif //MAIN_CPP_QUEUE_H
