#ifndef ARRAYCLASS_ARRAY_H
#define ARRAYCLASS_ARRAY_H

#include <iostream>


class Array {

    friend bool areEqual(const Array& arr1, const Array& arr2);
    friend Array operator+(const Array& arr1, const Array& arr2);

public:

    Array(int size);
    Array(const Array& other);
    Array(int size, int count, ...);
    ~Array();

    void add(int elem);
    void set(int index, int new_elem);
    void remove(int index);
    int search(int elem) const;
    int get(int index) const;
    char* toString();
    int getCurrentSize() const;
    int getCurrentElement() const;
    int getCurrentIndex() const;
    void setCurrentIndex(int new_index);
    void next();
    void prev();

    Array operator-(const Array& other);
    int& operator[](int index);
    Array& operator--();
    Array& operator-(int value);
    Array& operator=(const Array& other);

private:

    int* arr;
    int max_size;
    int curr_size;
    int curr_index;
    static int count;

    void resize();
};

bool areEqual(const Array& arr1, const Array& arr2);
Array operator+(const Array& arr1, const Array& arr2);


#endif //ARRAYCLASS_ARRAY_H