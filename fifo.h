#ifndef FIFO_H
#define FIFO_H

#include "fifo.h"
#include <string>

using std::string;

//Standard Data Struct
struct Data {
    int id;
    string data;
};

//Standard Node Struct
struct Node {
    Data data;
    Node *next;
};

//Queue Class Prototype
class Queue {

public:
    Queue();
    ~Queue();

    bool push(int, string*);
    bool pull(Data&);
    bool peek(Data&);
    bool isEmpty();

private:
    Node *head;
    Node *tail;
};

#endif //FIFO_H