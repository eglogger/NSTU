#include <iostream>

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

    ~Array() {

        delete[] arr;
    }

    void add(int elem) {

        if (curr_size < max_size) {
            arr[curr_size] = elem;
            curr_size++;

        }

        else {
            cout << "Array is full!" << endl;
        }
    }

    int search(int elem) {

        for (int i = 0; i < curr_size; i++) {

            if (arr[i] == elem) {
                return i;
            }
        }

        cout << "Element not found!" << endl;

        return -1;
    }

    void replace(int index, int new_elem) {

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

    void print() const {

        if (curr_size == 0) {
            cout << "Array is empty!" << endl;
        }

        else {

            for (int i = 0; i < curr_size; i++) {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
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

        if (curr_index < curr_size - 1) {
            curr_index++;
        }

        else {
            cout << "The cursor has reached the end!" << endl;
        }
    }

    void prev() {

        if (curr_index > 0) {
            curr_index--;
        }

        else {
            cout << "The cursor has reached the start!" << endl;
        }
    }

private:

    int* arr;
    int max_size;
    int curr_size;
    int curr_index;

};


#endif //CLASS_CLASS_H