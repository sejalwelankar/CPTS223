//Function definitions of test functions

#include "testQueue.h"

void testsize(void)
{
    /*Test ID: Size Check -SC
     * Unit: queue::size()
     * Description: test to determine if queue::size () returns the correct size of queue
     * steps:
     * 1.Construct an empty queue object.
     * 2.Add or enqueue a certain number of elements
     * 3.Invoke queue :: size()
     * 3.Conditionally evaluate the valued returned by queue::size()
     * Test data: size = 5
     * Precondition: queue object has 5 elements
     * Postcondition: queue object has 5 elements
     * Expected result: 5 will be returned as the size
     * Actual result: 6 is returned
     * Status: failed*/

    queue obj;

    //Adding 5 elements
    obj.enqueue(1);
    obj.enqueue(2);
    obj.enqueue(3);
    obj.enqueue(4);
    obj.enqueue(5);
    int test_size = obj.size();
    if(test_size == 5)
    {
        cout << "\n TEST PASSED.\nqueue :: size() operates as expected.";
    }
    else
    {
        cout << "\nTEST FAILED.\nqueue::size() doesn't operate as expected.";
    }
    cout << "\n\n**********************************************************************************************\n";

}
void testisEmpty(void){
    /*Test ID: Empty queue check -EQC
       * Unit: queue::isEmpty ()
       * Description: test to determine if queue::isEmpty () returns true if a queue object is emptyTest
       * steps:1.Construct an empty queue object
       * 2.Invoke queue::isEmpty ()
       * 3.Conditionally evaluate the valued returned by queue::isEmpty ()
       * Test data: size = 0
       * Precondition: queue object is empty
       * Postcondition: queue object is still empty
       * Expected result: queue is empty;true is returned
       * Actual result: queue is not empty;false is returned
       * Status: failed*/
    queue obj;
    if(obj.isEmpty())
    {
        cout << "\nTEST PASSED. \nqueue :: isEmpty() operates as expected.";
    }
    else
    {
        cout << "\nTEST FAILED.\nqueue::isEmpty() doesn't operate as expected.";
    }
    cout << "\n\n**********************************************************************************************\n";

}
void testisFull(void)
{
/*Test ID: Full queue check -FQC
       * Unit: queue::isFull ()
       * Description: test to determine if queue::isFull() returns true if a queue object is full
       * Test steps:
       * 1.Construct an empty queue object. Its capacity will be set to 10
       * 2.Add 9 elements to the object
       * 3.Conditionally evaluate the valued returned by queue::isFull()
       * Test data: size = 9
       * Precondition: queue object is not full
       * Postcondition: queue object is not full
       * Expected result: queue is not full ;false is returned
       * Actual result: queue is not full;false is returned
       * Status: true*/
    queue obj;

    //Adding 9 elements
    obj.enqueue(1);
    obj.enqueue(2);
    obj.enqueue(3);
    obj.enqueue(4);
    obj.enqueue(5);
    obj.enqueue(6);
    obj.enqueue(7);
    obj.enqueue(8);
    obj.enqueue(9);
    if(obj.isFull())
    {
        cout << "\nTEST FAILED.\nqueue::isFull() doesn't operate as expected.";
    }
    else
    {
        cout << "\nTEST PASSED. \nqueue :: isFull() operates as expected.";
    }
    cout << "\n\n**********************************************************************************************\n";
}
void testdequeue(void) {
/*Test ID: Dequeue check 1  -DC1
       * Unit: queue::dequeue ()
       * Description: test to determine if queue::dequeue() has 100% branch coverage
       * Test steps:
       * 1.Construct an empty queue object. Its capacity will be set to 10
       * 2.Invoke queue::dequeue()
       * 3.Evaluate the value of front. If function executes correctly, front will stay as 0
       * Test data: size = 0
       * Precondition: queue object is empty
       * Postcondition: queue object is empty
       * Expected result: queue is empty ;front = 0
       * Actual result: queue is not empty;front = 1
       * Status: failed*/
    queue obj1;
    obj1.dequeue();
    if (obj1.return_front() == 0) {
        cout << "\nTEST 1 PASSED. \nqueue ::dequeue() operates as expected.";
    } else {
        cout << "\nTEST 1 FAILED.\nqueue::dequeue() doesn't operate as expected.";

    }


/*Test ID: Dequeue check 2  -DC1
       * Unit: queue::dequeue ()
       * Description: test to determine if queue::dequeue() has 100% branch coverage
       * Test steps:
       * 1.Construct an empty queue object. Its capacity will be set to 10
       * 2. Add a certain number of elements
       * 3.Invoke queue::dequeue()
       * 4.Evaluate the output given by queue::dequeue()
       * Test data: size = 2
       * Precondition: queue object has 2 elements
       * Postcondition: queue object has 1 elements
       * Expected result: queue is not empty ; front will be set to 1
       * Actual result: queue is not empty; front will be set to 1
       * Status: passed*/
    queue obj2;
    obj2.enqueue(1);
    obj2.enqueue(2);
    obj2.dequeue();
    if (obj2.return_front() == 1) {
        cout << "\nTEST 2 PASSED. \nqueue ::dequeue() operates as expected.";
    }
    else
    {
        cout << "\nTEST 2 FAILED.\nqueue::dequeue() doesn't operate as expected.";

    }
    cout << "\n\n**********************************************************************************************\n";
}
void testenqueue(void)
{
    /*Test ID: Enqueue check 1  -DC1
       * Unit: queue::enqueue ()
       * Description: test to determine if queue::enqueue() has 100% branch coverage and to check whether proper assignment takes place
       * Test steps:
       * 1.Construct an empty queue object. Its capacity will be set to 10
       * 2. Add 9 elements
       * 3.Invoke queue::enqueue(int )
       * 4.Evaluate the value of rear. If function executes correctly, rear will increase by 1 to 9
       * Test data: size = 9
       * Precondition: queue object has 9 elements
       * Postcondition: queue object has 10 elements
       * Expected result: queue is not full ;rear = 9
       * Actual result: queue is not full;rear = 9
       * Status: passed*/
    queue obj;

    //Adding 9 elements
    obj.enqueue(1);
    obj.enqueue(2);
    obj.enqueue(3);
    obj.enqueue(4);
    obj.enqueue(5);
    obj.enqueue(6);
    obj.enqueue(7);
    obj.enqueue(8);
    obj.enqueue(9);
    //Adding a tenth element using enqueue
    obj.enqueue(12);
    if(obj.return_rear() == 9 && obj.peek() == 12)
    {
        cout << "\nTEST 1 PASSED. \nqueue ::enqueue() operates as expected.";
    }
    else
    {
        cout << "\nTEST 1 FAILED. \nqueue ::enqueue()  doesn't operate as expected.";
    }

    /*Test ID: Enqueue check 2  -EC2
       * Unit: queue::enqueue ()
       * Description: test to determine if queue::enqueue() has 100% branch coverage and to check whether the correct element is being added
       * Test steps:
       * 1.Construct an empty queue object. Its capacity will be set to 10
       * 2. Add 10 elements
       * 3.Invoke queue::enqueue(int) i.e add 11th element
       * 4.Evaluate the value of rear. If function executes correctly, rear will not increase from 9 to 10
       * Test data: size = 10
       * Precondition: queue object has 10 elements
       * Postcondition: queue object has 10 elements
       * Expected result: queue is  full ;rear = 9
       * Actual result: queue is full;rear = 9
       * Status: passed*/
    queue obj2;
    //Adding 10 elements
    obj2.enqueue(1);
    obj2.enqueue(2);
    obj2.enqueue(3);
    obj2.enqueue(4);
    obj2.enqueue(5);
    obj2.enqueue(6);
    obj2.enqueue(7);
    obj2.enqueue(8);
    obj2.enqueue(9);
    obj2.enqueue(92);
    //Adding an 11th element using enqueue
    obj2.enqueue(11);
    if(obj2.return_rear() == 9 && obj2.peek() == 92)
    {
        cout << "\nTEST 2 PASSED. \nqueue ::enqueue() operates as expected.";
    }
    else
    {
        cout << "\nTEST 2 FAILED. \nqueue ::enqueue()  doesn't operate as expected.";
    }
    cout << "\n\n**********************************************************************************************\n";
}
void testpeek(void)
{
/*Test ID: Peek check 1  -DC1
       * Unit: queue::peek ()
       * Description: test to determine if queue::peek() has 100% branch coverage
       * Test steps:
       * 1.Construct an empty queue object. Its capacity will be set to 10
       * 2.Invoke queue::peek()
       * 3.Conditionally evaluate the value returned by queue :: peek()
       * Test data: size = 0
       * Precondition: queue object is empty
       * Postcondition: queue object is empty
       * Expected result: queue is empty ;min value of int will be returned
       * Actual result: queue is not empty;garbage value of int is returned
       * Status: failed*/
    queue obj1;
    if (obj1.peek() == numeric_limits<int> :: min()) {
        cout << "\nTEST 1 PASSED. \nqueue ::peek() operates as expected.";
    } else {
        cout << "\nTEST 1 FAILED.\nqueue::peek() doesn't operate as expected.";

    }

/*Test ID: Peek check 2  -DC2
       * Unit: queue::peek ()
       * Description: test to determine if queue::peek() has 100% branch coverage
       * Test steps:
       * 1.Construct an empty queue object. Its capacity will be set to 10
       * 2.Add elements to object
       * 3.Invoke queue::peek()
       * 4.Conditionally evaluate the value returned by queue :: peek()
       * Test data: size = 1
       * Precondition: queue object has 1 element
       * Postcondition: queue object has 1 element
       * Expected result: queue is not empty ;the first element will be returned
       * Actual result: queue is not empty;the first element will be returned
       * Status: passed*/
    queue obj2;
    obj2.enqueue(1);
    if (obj2.peek() == 1) {
        cout << "\nTEST 2 PASSED. \nqueue ::peek() operates as expected.";
    }
    else
    {
        cout << "\nTEST 2 FAILED.\nqueue::peek() doesn't operate as expected.";

    }
    cout << "\n\n**********************************************************************************************\n";
}


