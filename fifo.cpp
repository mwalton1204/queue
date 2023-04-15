/*********************
Name: Michael Walton
COSC-2436-004
Purpose:
 - Design FIFO Queue ADT
**********************/

#include "fifo.h"

Queue::Queue() {
    head = NULL;
    tail = NULL;
}

Queue::~Queue() {}

bool Queue::push(int id, string* data) {
    bool pushed = false;

    if(id > 0 && !data->empty()) {
        Node* newNode = createNode(id, data);
        if(!head) {
            head = newNode;
            tail = newNode;
            pushed = true;
        } else if (head == tail) {
            newNode->next = head;
            tail = newNode;
            pushed = true;
        } else {
            newNode->next = tail;
            tail = newNode;
            pushed = true;
        }
    }
    return pushed;
}

bool Queue::pull(Data &tmpData) {
    bool pulled = false;

    return pulled;
}

bool Queue::peek(Data &tmpData) {
    bool peeked = false;

    if(head) {
        tmpData.id = head->data.id;
        tmpData.data = head->data.data;
        peeked = true;
    }

    return peeked;
}

bool Queue::isEmpty() {
    return head == NULL;
}

void Queue::printQueue() {
    Node* current = tail;
    cout << "printing queue: \n";
    while(current) {
        if(current == head) {
            cout << "HEAD: " << current->data.id << "\n";
        } else if (current == tail) {
            cout << "TAIL: " << current->data.id << "\n";
        } else {
            cout << current->data.id << "\n";
        }
        current = current->next;
    }
}

Node* Queue::createNode(int newId, string* newData) {
    Node *newNode = new Node{{newId, *newData}, NULL};
    return newNode;
}