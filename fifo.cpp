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

Queue::~Queue() {
    Node* current = tail;
    while(current) {
        Node* tmpNode = current->next;
        delete current;
        current = tmpNode;
    }
    head = NULL;
    tail = NULL;
}

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
            head->prev = tail;
            pushed = true;
        } else {
            newNode->next = tail;
            tail = newNode;
            tail->next->prev = tail;
            pushed = true;
        }
    }
    return pushed;
}

bool Queue::pull(Data &tmpData) {
    bool pulled = false;

    if(head) {
        tmpData.id = head->data.id;
        tmpData.data = head->data.data;

        Node* tmpNode = head;
        head = head->prev;
        head->next = NULL;
        delete tmpNode;
    }

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
    cout << "PRINTING QUEUE: \n";
    while(current) {
        if(current == head) {
            cout << current->data.id << "\t(HEAD)\n";
        } else if (current == tail) {
            cout << current->data.id << "\t(TAIL)\n";
        } else {
            cout << current->data.id << "\n";
        }
        current = current->next;
    }
}

Node* Queue::createNode(int newId, string* newData) {
    Node *newNode = new Node{{newId, *newData}, NULL, NULL};
    return newNode;
}