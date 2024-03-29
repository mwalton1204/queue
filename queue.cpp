/*********************
Name: Michael Walton
COSC-2436-004
Purpose:
 - Design FIFO Queue ADT
**********************/

#include "queue.h"

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

        if(head == tail) {
            Node *tmpNode = head;
            head = NULL;
            tail = NULL;
            delete tmpNode;
        } else {
            Node *tmpNode = head;
            head = head->prev;
            head->next = NULL;
            delete tmpNode;
        }

        pulled = true;
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
    cout << "\nPRINTING QUEUE: \n";
    while(current) {
        if(current == head) {
            cout << current->data.id << "\t(HEAD)\n\n";
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
