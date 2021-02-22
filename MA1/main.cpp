/*Name - Sejal Welankar
 * Class - CPTS 223
 * Assignment - MA 1
 * Attributes
 * 1. Destructor function -> The entire array is not being deleted. Only the pointer to the rray is being destroyed.
 * 2. File Structure -> Placing function definitions in header file for queue is bad design. To safely include queue.h in multiple files I had to define the functions as inline
 * 3. The queue being implemented as a queue leads to restrictions on size.
 * 4. Size function is unnecessary as it returns count variable which can directly be accessed by memeber functions.
 * 5. Peek function returns the last element. Queue is a first in first out data structure. So it would be relevant for peek to return the first element rather than the last one
 */
#include "testQueue.h"
// main function
int main()
{
    // call your test functions here!
    testsize();
    testisEmpty();
    testisFull();
    testdequeue();
    testenqueue();
    testpeek();
    return 0;
}

