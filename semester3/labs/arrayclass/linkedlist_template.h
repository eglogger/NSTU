#ifndef ARRAYCLASS_LINKEDLIST_TEMPLATE_H
#define ARRAYCLASS_LINKEDLIST_TEMPLATE_H

#include <iostream>
#include <stdexcept>
#include <sstream>


template <typename T>
class NodeTemplate {

public:

    T data;
    NodeTemplate<T>* next;
    NodeTemplate<T>* prev;

    NodeTemplate(const T& data) : data(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class LinkedListTemplate {

private:

    NodeTemplate<T>* head;

public:

    LinkedListTemplate() : head(nullptr) {}
    ~LinkedListTemplate();

    void add(const T& data);
    void insertAt(int index, const T& data);
    void removeAt(int index);
    NodeTemplate<T>* search(const T& value);
    char* toString() const;
};

template <typename T>
LinkedListTemplate<T>::~LinkedListTemplate() {

    if (!head) return;

    NodeTemplate<T>* current = head;

    do {
        NodeTemplate<T>* temp = current;
        current = current->next;
        delete temp;
    } while (current != head);
}

template <typename T>
void LinkedListTemplate<T>::add(const T& data) {

    NodeTemplate<T>* newNode = new NodeTemplate<T>(data);

    if (!head) {
        head = newNode;
        head->next = head;
        head->prev = head;
    }

    else {
        NodeTemplate<T>* tail = head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
}

template <typename T>
void LinkedListTemplate<T>::insertAt(int index, const T& data) {

    if (index < 0) throw std::out_of_range("Index cannot be negative");

    if (!head && index == 0) {
        add(data);
        return;
    }

    NodeTemplate<T>* current = head;

    for (int i = 0; i < index; ++i) {
        current = current->next;
        if (current == head) throw std::out_of_range("Index is out of range!");
    }

    NodeTemplate<T>* newNode = new NodeTemplate<T>(data);
    newNode->next = current;
    newNode->prev = current->prev;
    current->prev->next = newNode;
    current->prev = newNode;

    if (index == 0) head = newNode;
}

template <typename T>
void LinkedListTemplate<T>::removeAt(int index) {

    if (!head) throw std::out_of_range("List is empty");

    NodeTemplate<T>* current = head;

    for (int i = 0; i < index; ++i) {
        current = current->next;
        if (current == head) throw std::out_of_range("Index is out of range!");
    }

    if (current->next == current) {
        delete current;
        head = nullptr;
    }

    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        if (current == head) head = current->next;
        delete current;
    }
}

template <typename T>
NodeTemplate<T>* LinkedListTemplate<T>::search(const T& value) {

    if (!head) return nullptr;

    NodeTemplate<T>* current = head;

    do {
        if (current->data == value) return current;
        current = current->next;
    } while (current != head);

    return nullptr;
}

template <typename T>
char* LinkedListTemplate<T>::toString() const {

    if (!head) {
        char* emptyMessage = new char[16];
        std::strcpy(emptyMessage, "List is empty!");
        return emptyMessage;
    }

    std::ostringstream oss;
    NodeTemplate<T>* current = head;

    do {
        oss << current->data << " -> ";
        current = current->next;
    } while (current != head);

    oss << "(back to head)";
    std::string result = oss.str();

    char* output = new char[result.size() + 1];
    std::strcpy(output, result.c_str());
    return output;
}


#endif //ARRAYCLASS_LINKEDLIST_TEMPLATE_H