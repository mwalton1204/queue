/*********************
Name: Michael Walton
COSC-2436-004
Purpose:
 - Design FIFO Queue ADT
**********************/

#include "main.h"

int main() {
    Queue queue;
    Data tmpData;

    string tmpString = "./aserg";

    queue.printQueue();
    cout << "\n";

    if(queue.isEmpty()) {
        cout << "empty\n";
    } else {
        cout << "not empty\n";
    }

    cout << "PEEKING...\n";
    if(queue.peek(tmpData)) {
        cout << "ID: " << tmpData.id << "\n";
        cout << "DATA: " << tmpData.data << "\n";
    } else {
        cout << "UNABLE TO PEEK\n\n";
    }

    cout << "adding new head: 1...\n";
    if(queue.push(1, &tmpString)) {
        cout << "added\n";
    }

    queue.printQueue();

    cout << "PEEKING...\n";
    if(queue.peek(tmpData)) {
        cout << "ID: " << tmpData.id << "\n";
        cout << "DATA: " << tmpData.data << "\n";
    } else {
        cout << "UNABLE TO PEEK";
    }

    cout << "\n";
    cout << "adding new node: 2...\n";
    if(queue.push(2, &tmpString)) {
        cout << "added\n";
    }

    queue.printQueue();

    cout << "PEEKING...\n";
    if(queue.peek(tmpData)) {
        cout << "ID: " << tmpData.id << "\n";
        cout << "DATA: " << tmpData.data << "\n";
    } else {
        cout << "UNABLE TO PEEK";
    }

    cout << "\n";
    cout << "adding new node: 3...\n";
    if(queue.push(3, &tmpString)) {
        cout << "added\n";
    }

    queue.printQueue();

    cout << "PEEKING...\n";
    if(queue.peek(tmpData)) {
        cout << "ID: " << tmpData.id << "\n";
        cout << "DATA: " << tmpData.data << "\n";
    } else {
        cout << "UNABLE TO PEEK";
    }

    cout << "\n";
    cout << "adding new node: 4...\n";
    if(queue.push(4, &tmpString)) {
        cout << "added\n";
    }

    queue.printQueue();

    cout << "PEEKING...\n";
    if(queue.peek(tmpData)) {
        cout << "ID: " << tmpData.id << "\n";
        cout << "DATA: " << tmpData.data << "\n";
    } else {
        cout << "UNABLE TO PEEK";
    }

    cout << "\n";
    cout << "adding new node: 5...\n";
    if(queue.push(5, &tmpString)) {
        cout << "added\n";
    }

    queue.printQueue();

    cout << "PEEKING...\n";
    if(queue.peek(tmpData)) {
        cout << "ID: " << tmpData.id << "\n";
        cout << "DATA: " << tmpData.data << "\n";
    } else {
        cout << "UNABLE TO PEEK";
    }

    cout << "\n";

    if(queue.isEmpty()) {
        cout << "empty\n";
    } else {
        cout << "not empty\n";
    }

    cout << "\n\n\nTESTING PULL\n\n";

    queue.printQueue();
    cout << "\n";

    queue.pull(tmpData);

    queue.printQueue();
    cout << "\n";

    queue.pull(tmpData);

    queue.printQueue();
    cout << "\n";

    return 0;
}