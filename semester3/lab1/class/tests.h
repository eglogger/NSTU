#include <iostream>
#include "array.h"

#ifndef CLASS_TESTS_H
#define CLASS_TESTS_H

using namespace std;

void testAdd() {

    cout << "--- Test add. ---" << endl;

    Array arr(3);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    arr.print();
}

void testGet() {

    cout << "--- Test get. ---" << endl;

    Array arr(3);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    arr.print();
}

void testSetGetCurr() {

    cout << "--- Test setCurrentIndex/getCurrentElement. ---" << endl;

    Array arr(3);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    arr.setCurrentIndex(2);
    cout << "Current Element: " << arr.getCurrentElement() << " Index: "
         << arr.getCurrentIndex() << endl;
}

void testNextPrev() {

    cout << "--- Test Next and Prev. ---" << endl;

    Array arr(3);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    arr.next();
    cout << "Current Element: " << arr.getCurrentElement() << " Index: "
         << arr.getCurrentIndex() << endl;

    arr.prev();
    cout << "Current Element: " << arr.getCurrentElement() << " Index: "
         << arr.getCurrentIndex() << endl;
}

void testSearch() {

    cout << "--- Test search. ---" << endl;

    Array arr(3);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    arr.setCurrentIndex(arr.search(10));
    cout << "Current Element: " << arr.getCurrentElement() << " Index: "
         << arr.getCurrentIndex() << endl;
}

void testSet() {

    cout << "--- Test set. ---" << endl;

    Array arr(3);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);
    arr.print();

    arr.set(0, 5);
    arr.print();
}

void testRemove() {

    cout << "--- Test remove. ---" << endl;

    Array arr(3);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);
    arr.print();

    arr.remove(0);
    arr.print();
}

void testGetCurrSize() {

    cout << "--- Test remove. ---" << endl;

    Array arr(3);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);
    arr.print();

    cout << arr.getCurrentSize() << endl;
}

void


#endif //CLASS_TESTS_H