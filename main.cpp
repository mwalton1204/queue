/*********************
Name: Michael Walton
COSC-2436-004
Purpose:
 - Design FIFO Queue ADT
**********************/

#include "main.h"

int main() {
    Queue queue;

    string tmpString = "hello";

    queue.push(1, &tmpString);
    queue.push(2, &tmpString);
    queue.push(3, &tmpString);
    queue.push(4, &tmpString);
    queue.push(5, &tmpString);

    queue.printQueue();

    return 0;
}