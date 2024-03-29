#ifndef QUEUE_H
#define QUEUE_H

#include <string>
#include <iostream>

using std::string;
using std::cout;

//Standard Data Struct
struct Data {
    int id;
    string data;
};

//Standard Node Struct
struct Node {
    Data data;
    Node *next;
    Node *prev;
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
    void printQueue();

private:
    Node* createNode(int, string*);

    Node *head;
    Node *tail;
};

#endif //QUEUE_H
