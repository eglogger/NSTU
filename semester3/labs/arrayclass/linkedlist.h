#ifndef ARRAYCLASS_LINKEDLIST_H
#define ARRAYCLASS_LINKEDLIST_H

#include "array.h"


class Node {

public:

    Array* data;
    Node* next;
    Node* prev;

    Node(Array* data);
};

class LinkedList {

private:

    Node* head;

public:

    LinkedList();
    ~LinkedList();

    void add(Array* array);
    void insertAt(int index, Array* array);
    void removeAt(int index);
    Node* search(int value);
    char* toString();
};


#endif //ARRAYCLASS_LINKEDLIST_H