#include "linkedlist.h"
#include <iostream>
#include <cstring>
#include <sstream>

Node::Node(Array* data) : data(data), next(nullptr), prev(nullptr) {}

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {

    if (!head) return;

    Node* current = head;

    do {
        Node* temp = current;
        current = current->next;
        delete temp->data;
        delete temp;
    } while (current != head);
}

void LinkedList::add(Array* array) {

    Node* newNode = new Node(array);

    if (!head) {
        head = newNode;
        head->next = head;
        head->prev = head;
    }

    else {
        Node* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
}

void LinkedList::insertAt(int index, Array* array) {

    if (!head) {

        if (index == 0) {
            add(array);
        }

        else {
            throw std::out_of_range("Index is out of range for empty list!");
        }
        return;
    }

    if (index < 0) {
        throw std::out_of_range("Index cannot be negative!");
    }

    Node* current = head;

    for (int i = 0; i < index; ++i) {

        current = current->next;

        if (current == head) {
            throw std::out_of_range("Index is out of range!");
        }
    }

    Node* newNode = new Node(array);
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;

    if (index == 0) {
        head = newNode;
    }
}

void LinkedList::removeAt(int index) {

    if (!head) throw std::out_of_range("List is empty!");

    Node* current = head;

    for (int i = 0; i < index; ++i) {

        current = current->next;

        if (current == head) {
            throw std::out_of_range("Index is out of range!");
        }
    }

    if (current->next == current) {
        delete current->data;
        delete current;
        head = nullptr;
    }

    else {

        current->prev->next = current->next;
        current->next->prev = current->prev;

        if (current == head) {
            head = current->next;
        }

        delete current->data;
        delete current;
    }
}

Node* LinkedList::search(int value) {

    if (!head) return nullptr;

    Node* current = head;

    do {
        if (current->data->search(value) != -1) {
            return current;
        }
        current = current->next;
    } while (current != head);

    return nullptr;
}

char* LinkedList::toString() {

    if (!head) {
        char* emptyMessage = new char[16];
        strcpy(emptyMessage, "List is empty!");
        return emptyMessage;
    }

    std::stringstream ss;
    Node* current = head;

    do {
        char* arrayStr = current->data->toString();
        ss << arrayStr << "-> ";
        delete[] arrayStr;
        current = current->next;
    } while (current != head);

    ss << "(back to head)";

    std::string temp = ss.str();
    char* result = new char[temp.size() + 1];
    strcpy(result, temp.c_str());

    return result;
}