/*********************
Name: Michael Walton
COSC-2436-004
Purpose:
 - Design FIFO Queue ADT
**********************/

#include "main.h"

int main() {
    srand(time(NULL));

    Queue queue;
    Data tmpData;

    cout << "-------------------\tTESTING INITIALIZED QUEUE\t-------------------\n\n";
    queue.printQueue();
    cout << "\n";
    if(queue.isEmpty()) {
        cout << "QUEUE STATUS: EMPTY\n\n";
    } else {
        cout << "QUEUE STATUS: NOT EMPTY\n\n";
    }

    cout << "-------------------\tTESTING PUSHING DATA TO QUEUE\t-------------------\n\n";

    for(int i = 0; i < 10; i++) {
        int newId = (rand() % 50) + 1;
        string newData = "data";

        cout << "PUSHING [ID: " << newId << " DATA: " << newData << "] TO BACK OF QUEUE ... ";
        if(queue.push(newId, &newData)) {
            cout << "PUSHED\n";
        } else {
            cout << "NOT PUSHED\n";
        }

        queue.printQueue();
    }

    cout << "-------------------\tTESTING PEEKING AND PULLING DATA FROM QUEUE\t-------------------\n\n";

    for(int i = 0; i < 5; i++) {
        cout << "PEEKING HEAD ... ";
        if(queue.peek(tmpData)) {
            cout << "PEEKED [ID: " << tmpData.id << " DATA: " << tmpData.data << "]\n";
        } else {
            cout << "UNDERFLOW ERROR\n";
        }

        cout << "PULLING HEAD ... ";
        if(queue.pull(tmpData)) {
            cout << "PULLED [ID: " << tmpData.id << " DATA: " << tmpData.data << "]\n";
        } else {
            cout << "UNDERFLOW ERROR\n";
        }

        queue.printQueue();
    }

    cout << "-------------------\tEMPTYING QUEUE\t-------------------\n\n";

    while(!queue.isEmpty()) {
        queue.pull(tmpData);
    }

    queue.printQueue();
    cout << "\n";
    if(queue.isEmpty()) {
        cout << "QUEUE STATUS: EMPTY\n\n";
    } else {
        cout << "QUEUE STATUS: NOT EMPTY\n\n";
    }

    cout << "-------------------\tREFILLING QUEUE\t-------------------\n\n";

    for(int i = 0; i < 10; i++) {
        int newId = (rand() % 50) + 1;
        string newData = "data";

        cout << "PUSHING [ID: " << newId << " DATA: " << newData << "] TO BACK OF QUEUE ... ";
        if(queue.push(newId, &newData)) {
            cout << "PUSHED\n";
        } else {
            cout << "NOT PUSHED\n";
        }

        queue.printQueue();
    }

    int testQty = (rand() % MAXTESTQTY) + 1;
    cout << "-------------------\tPERFORMING " << testQty << " RANDOMIZED OPERATIONS ON QUEUE\t-------------------\n\n";

    for(int i = 0; i < testQty; i++) {
        int operation = (rand() % 3) + 1;

        switch(operation) {
            case 1: { //push
                int newId = (rand() % 50) + 1;
                string newData = "data";

                cout << "PUSHING [ID: " << newId << " DATA: " << newData << "] TO BACK OF QUEUE ... ";
                if (queue.push(newId, &newData)) {
                    cout << "PUSHED\n";
                } else {
                    cout << "NOT PUSHED\n";
                }

                break;
            }
            case 2: //peek
                cout << "PEEKING HEAD ... ";
                if(queue.peek(tmpData)) {
                    cout << "PEEKED [ID: " << tmpData.id << " DATA: " << tmpData.data << "]\n";
                } else {
                    cout << "UNDERFLOW ERROR\n";
                }

                break;
            case 3: //pull
                cout << "PULLING HEAD ... ";
                if(queue.pull(tmpData)) {
                    cout << "PULLED [ID: " << tmpData.id << " DATA: " << tmpData.data << "]\n";
                } else {
                    cout << "UNDERFLOW ERROR\n";
                }

                break;
        }

        queue.printQueue();
        cout << "\n";
        if(queue.isEmpty()) {
            cout << "QUEUE STATUS: EMPTY\n\n";
        } else {
            cout << "QUEUE STATUS: NOT EMPTY\n\n";
        }

    }



    return 0;
}