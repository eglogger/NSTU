#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdarg>

#ifndef CLASS_CLASS_H
#define CLASS_CLASS_H

using namespace std;


class Array {

public:

    Array(int size) {

        max_size = size;

        arr = new int[max_size];

        curr_size = 0;
        curr_index = 0;
    }

    Array(const Array& other) {

        max_size = other.max_size;
        curr_size = other.curr_size;
        curr_index = other.curr_index;

        arr = new int[max_size];

        for (int i = 0; i < curr_size; i++) {

            arr[i] = other.arr[i];
        }
    }

    Array(int size, int count, ...) {

        if (count > size) {
            cout << "Not enough size!" << endl;
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
        }
    }

    ~Array() {

        cout << "Array destructed." << endl;
        delete[] arr;
    }

    void add(int elem) {

        if (curr_size == max_size) {
            resize();
        }
        arr[curr_size] = elem;
        curr_size++;
    }

    void set(int index, int new_elem) {

        if (index >= 0 && index < curr_size) {
            arr[index] = new_elem;
        }

        else {
            cout << "Index is out of range!" << endl;
        }
    }

    void remove(int index) {

        if (index >= 0 && index < curr_size) {

            for (int i = index; i < curr_size - 1; i++) {
                arr[i] = arr[i + 1];
            }

            curr_size--;
        }

        else {
            cout << "Index is out of range!" << endl;
        }
    }

    int search(int elem) const {

        for (int i = 0; i < curr_size; i++) {

            if (arr[i] == elem) {
                return i;
            }
        }

        cout << "Element not found!" << endl;

        return -1;
    }

    int get(int index) const {

        if ((index >= 0) && (index <= curr_size)) {
            return arr[index];
        }

        else {
            cout << "Index is out of range!" << endl;
            return -1;
        }
    }

    string print() {

        ostringstream output;

        if (curr_size == 0) {
            output << "Array is empty!";
        }

        else {
            for (int i = 0; i < curr_size; i++) {
                output << arr[i] << " ";
            }
        }

        cout << output.str() << endl;

        return output.str();
    }

    int getCurrentSize() const {

        return curr_size;
    }

    int getCurrentElement() const {

        if (curr_size > 0) {
            return arr[curr_index];
        }

        else {
            cout << "Array is empty!" << endl;
            return -1;
        }
    }

    int getCurrentIndex() const {

        if (curr_size > 0) {
            return curr_index;
        }

        else {
            cout << "Array is empty!" << endl;
            return -1;
        }
    }

    void setCurrentIndex(int new_index) {

        if (curr_size == 0) {
            cout << "Array is empty!" << endl;
        }

        if ((new_index >= 0) && (new_index <= curr_size - 1)) {
            curr_index = new_index;
        }

        else {
            cout << "Index is out of range!" << endl;
        }
    }

    void next() {

        if (curr_index > curr_size - 1) {
            cout << "The cursor has reached the end!" << endl;
        }

        else {
            curr_index++;
        }
    }

    void prev() {

        if (curr_index == 0) {
            cout << "The cursor has reached the start!" << endl;
        }

        else {
            curr_index--;
        }
    }

    Array operator+(const Array& other) {

        int new_size = max(curr_size, other.curr_size);
        Array result(new_size);

        for (int i = 0; i < min(curr_size, other.curr_size); ++i) {
            result.arr[i] = arr[i] + other.arr[i];
        }

        if (curr_size > other.curr_size) {
            for (int i = other.curr_size; i < curr_size; ++i) {
                result.arr[i] = arr[i];
            }
        }

        else {
            for (int i = curr_size; i < other.curr_size; ++i) {
                result.arr[i] = other.arr[i];  // Остаток из второго массива
            }
        }

        result.curr_size = new_size;
        return result;
    }

    Array operator-(const Array& other) {

        int new_size = max(curr_size, other.curr_size);
        Array result(new_size);

        for (int i = 0; i < min(curr_size, other.curr_size); ++i) {
            result.arr[i] = arr[i] - other.arr[i];
        }

        if (curr_size > other.curr_size) {
            for (int i = other.curr_size; i < curr_size; ++i) {
                result.arr[i] = arr[i];
            }
        }

        else {
            for (int i = curr_size; i < other.curr_size; ++i) {
                result.arr[i] = -other.arr[i];
            }
        }

        result.curr_size = new_size;

        return result;
    }

    int& operator[](int index) {

        if (index >= 0 && index < curr_size) {
            return arr[index];
        }

        else {
            throw out_of_range("Index is out of range!");
        }
    }

    Array& operator--() {

        for (int i = 0; i < curr_size; ++i) {
            arr[i]--;
        }

        return *this;
    }

    Array& operator-(int value) {

        int index = search(value);

        if (index != -1) {
            remove(index);
        }

        return *this;
    }

    Array& operator=(const Array& other) {

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

private:

    int* arr;
    int max_size;
    int curr_size;
    int curr_index;

    void resize() {

        int new_size = max_size * 2;
        int* new_arr = new int[new_size];

        for (int i = 0; i < curr_size; i++) {
            new_arr[i] = arr[i];
        }

        delete[] arr;
        arr = new_arr;
        max_size = new_size;
    }
};


#endif //CLASS_CLASS_H