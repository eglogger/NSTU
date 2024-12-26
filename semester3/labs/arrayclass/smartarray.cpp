#include "smartarray.h"


SmartArray::SmartArray(int size) : Array(size) {}

SmartArray::SmartArray(const SmartArray& other) : Array(other) {}

void SmartArray::add(int elem) {

    if (getCurrentSize() >= getMaxSize()) {
        throw std::overflow_error("Cannot add element: Array is full.");
    }

    Array::add(elem);
}

int SmartArray::get(int index) const {

    if (index < 0 || index >= getCurrentSize()) {
        throw std::out_of_range("Index out of range!");
    }

    return Array::get(index);
}

void SmartArray::set(int index, int new_elem) {

    if (index < 0 || index >= getCurrentSize()) {
        throw std::out_of_range("Index out of range!");
    }

    Array::set(index, new_elem);
}
