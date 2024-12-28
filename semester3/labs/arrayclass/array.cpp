#include "array.h"
#include <cstdarg>
#include <cstring>
#include <iostream>
#include <fstream>


int Array::count = 0;

Array::Array(int size) {

    max_size = size;
    arr = new int[max_size];

    curr_size = 0;
    curr_index = 0;

    count++;
}

Array::Array(const Array& other) {

    max_size = other.max_size;
    curr_size = other.curr_size;
    curr_index = other.curr_index;

    arr = new int[max_size];

    for (int i = 0; i < curr_size; i++) {
        arr[i] = other.arr[i];
    }

    count++;
}

Array::Array(int size, int count, ...) {

    if (count > size) {
        std::cout << "Not enough size!" << std::endl;
    }

    else {
        max_size = size;
        curr_size = count;
        curr_index = 0;
        arr = new int[max_size];

        va_list arg;
        va_start(arg, count);

        for (int i = 0; i < count; ++i) {
            arr[i] = va_arg(arg, int);
        }

        va_end(arg);
        this->count++;
    }
}

Array::~Array() {

    std::cout << "Array destructed." << std::endl;
    delete[] arr;
}

int Array::getMaxSize() const {

    return max_size;
}

void Array::add(int elem) {

    if (curr_size == max_size) {
        resize();
    }

    arr[curr_size] = elem;
    curr_size++;
}

void Array::set(int index, int new_elem) {

    if (index >= 0 && index < curr_size) {
        arr[index] = new_elem;
    }

    else {
        std::cout << "Index is out of range!" << std::endl;
    }
}

void Array::remove(int index) {

    if (index >= 0 && index < curr_size) {

        for (int i = index; i < curr_size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        curr_size--;
    }

    else {
        std::cout << "Index is out of range!" << std::endl;
    }
}

int Array::search(int elem) const {

    for (int i = 0; i < curr_size; i++) {

        if (arr[i] == elem) {
            return i;
        }
    }

    std::cout << "Element not found!" << std::endl;
    return -1;
}

int Array::get(int index) const {

    if ((index >= 0) && (index < curr_size)) {
        return arr[index];
    }

    else {

        std::cout << "Index is out of range!" << std::endl;
        return -1;
    }
}

char* Array::toString() {

    if (curr_size == 0) {

        char* emptyMessage = new char[16];
        strcpy(emptyMessage, "Array is empty!");
        return emptyMessage;
    }

    int charCount = 0;

    for (int i = 0; i < curr_size; i++) {
        charCount += snprintf(nullptr, 0, "%d ", arr[i]);
    }

    char* output = new char[charCount + 1];
    output[0] = '\0';

    for (int i = 0; i < curr_size; i++) {
        char buffer[12];
        snprintf(buffer, sizeof(buffer), "%d ", arr[i]);
        strcat(output, buffer);
    }

    return output;
}

int Array::getCurrentSize() const {

    return curr_size;
}

int Array::getCurrentElement() const {

    if (curr_size > 0) {
        return arr[curr_index];
    }

    else {
        std::cout << "Array is empty!" << std::endl;
        return -1;
    }
}

int Array::getCurrentIndex() const {

    if (curr_size > 0) {
        return curr_index;
    }

    else {
        std::cout << "Array is empty!" << std::endl;
        return -1;
    }
}

void Array::setCurrentIndex(int new_index) {

    if (curr_size == 0) {
        std::cout << "Array is empty!" << std::endl;
    }

    if ((new_index >= 0) && (new_index <= curr_size - 1)) {
        curr_index = new_index;
    }

    else {
        std::cout << "Index is out of range!" << std::endl;
    }
}

void Array::next() {

    if (curr_index > curr_size - 1) {
        std::cout << "The cursor has reached the end!" << std::endl;
    }

    else {
        curr_index++;
    }
}

void Array::prev() {

    if (curr_index == 0) {
        std::cout << "The cursor has reached the start!" << std::endl;
    }

    else {
        curr_index--;
    }
}

Array Array::operator-(const Array& other) {

    int new_size = std::max(curr_size, other.curr_size);
    Array result(new_size);

    for (int i = 0; i < std::min(curr_size, other.curr_size); ++i) {
        result.arr[i] = arr[i] - other.arr[i];
    }

    if (curr_size > other.curr_size) {

        for (int i = other.curr_size; i < curr_size; ++i) {
            result.arr[i] = arr[i];
        }
    }

    else {

        for (int i = curr_size; i < other.curr_size; ++i) {
            result.arr[i] = other.arr[i];
        }
    }

    result.curr_size = new_size;

    return result;
}

int& Array::operator[](int index) {

    if (index >= 0 && index < curr_size) {
        return arr[index];
    }

    else {
        throw std::out_of_range("Index is out of range!");
    }
}

Array& Array::operator--() {

    for (int i = 0; i < curr_size; ++i) {
        arr[i]--;
    }

    return *this;
}

Array& Array::operator-(int value) {

    int index = search(value);

    if (index != -1) {
        remove(index);
    }

    return *this;
}

Array& Array::operator=(const Array& other) {

    if (this == &other) {
        return *this;
    }

    delete[] arr;

    max_size = other.max_size;
    curr_size = other.curr_size;
    curr_index = other.curr_index;
    arr = new int[max_size];

    for (int i = 0; i < curr_size; ++i) {
        arr[i] = other.arr[i];
    }

    return *this;
}

void Array::resize() {

    int new_size = max_size * 2;
    int* new_arr = new int[new_size];

    for (int i = 0; i < curr_size; i++) {
        new_arr[i] = arr[i];
    }

    delete[] arr;

    arr = new_arr;
    max_size = new_size;
}

bool areEqual(const Array& arr1, const Array& arr2) {

    if (arr1.curr_size != arr2.curr_size) {
        return false;
    }

    for (int i = 0; i < arr1.curr_size; i++) {
        if (arr1.arr[i] != arr2.arr[i]) {
            return false;
        }
    }

    return true;
}

Array operator+(const Array& arr1, const Array& arr2) {

    int new_size = std::max(arr1.curr_size, arr2.curr_size);
    Array result(new_size);

    for (int i = 0; i < std::min(arr1.curr_size, arr2.curr_size); ++i) {
        result.arr[i] = arr1.arr[i] + arr2.arr[i];
    }

    if (arr1.curr_size > arr2.curr_size) {

        for (int i = arr2.curr_size; i < arr1.curr_size; ++i) {
            result.arr[i] = arr1.arr[i];
        }
    }

    else {

        for (int i = arr1.curr_size; i < arr2.curr_size; ++i) {
            result.arr[i] = arr2.arr[i];
        }
    }

    result.curr_size = new_size;

    return result;
}

std::ostream& operator<<(std::ostream& os, const Array& arr) {

    os << "[";

    for (int i = 0; i < arr.getCurrentSize(); ++i) {

        os << arr.get(i);

        if (i != arr.getCurrentSize() - 1) {
            os << " ";
        }
    }

    os << "]";

    return os;
}

std::istream& operator>>(std::istream& is, Array& arr) {

    char bracket;
    is >> bracket;

    if (bracket != '[') {
        throw std::runtime_error("Invalid format: expected '['");
    }

    arr = Array(arr.getMaxSize());
    int value;

    while (is >> value) {

        arr.add(value);
        is.get(bracket);

        if (bracket == ']') {
            break;
        }
    }

    if (bracket != ']') {
        throw std::runtime_error("Invalid format: expected ']'");
    }

    return is;
}

void Array::writeToBinaryFile(std::ofstream& out) const {

    if (!out.is_open()) {
        std::cerr << "Error: Output stream is not open!" << std::endl;
        return;
    }

    out.write(reinterpret_cast<const char*>(&curr_size), sizeof(curr_size));
    out.write(reinterpret_cast<const char*>(arr), curr_size * sizeof(int));
}

void Array::readFromBinaryFile(std::ifstream& in) {

    if (!in.is_open()) {
        std::cerr << "Error: Input stream is not open!" << std::endl;
        return;
    }

    in.read(reinterpret_cast<char*>(&curr_size), sizeof(curr_size));

    if (curr_size > max_size) {
        delete[] arr;
        max_size = curr_size;
        arr = new int[max_size];
    }

    in.read(reinterpret_cast<char*>(arr), curr_size * sizeof(int));
}