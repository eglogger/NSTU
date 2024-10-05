#include <iostream>
#include "array.h"

#ifndef CLASS_TESTS_H
#define CLASS_TESTS_H

using namespace std;

void testAdd() {

    cout << "--- add test ---" << endl;

    Array arr(3);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    arr.print();
}

void testGet() {

    cout << "--- get test ---" << endl;

    Array arr(4);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    cout << arr.get(0) << endl;
}

void testSetGetCurr() {

    cout << "--- setCurrentIndex/getCurrentElement test ---" << endl;

    Array arr(4);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    arr.setCurrentIndex(2);
    cout << "Current Element: " << arr.getCurrentElement() << " Index: "
         << arr.getCurrentIndex() << endl;
}

void testNextPrev() {

    cout << "--- next/prev test ---" << endl;

    Array arr(4);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    cout << "Current Element: " << arr.getCurrentElement() << " Index: "
         << arr.getCurrentIndex() << endl;

    arr.next();
    cout << "Current Element: " << arr.getCurrentElement() << " Index: "
         << arr.getCurrentIndex() << endl;

    arr.prev();
    cout << "Current Element: " << arr.getCurrentElement() << " Index: "
         << arr.getCurrentIndex() << endl;
}

void testSearch() {

    cout << "--- search test ---" << endl;

    Array arr(4);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    arr.setCurrentIndex(arr.search(10));
    cout << "Current Element: " << arr.getCurrentElement() << " Index: "
         << arr.getCurrentIndex() << endl;
}

void testSet() {

    cout << "--- set test ---" << endl;

    Array arr(4);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);
    arr.print();

    arr.set(0, 5);
    arr.print();
}

void testRemove() {

    cout << "--- remove test ---" << endl;

    Array arr(4);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);
    arr.print();

    arr.remove(0);
    arr.print();
}

void testGetCurrSize() {

    cout << "--- getCurrentSize test ---" << endl;

    Array arr(4);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);
    arr.print();

    cout << arr.getCurrentSize() << endl;
}

void testNewConstructor() {

    cout << "--- New Constructor test ---" << endl;

    Array arr1(5, 5, 50, 40, 30, 20, 10);
    arr1.print();
}

void testCopyConstructor() {

    cout << "--- Copy Constructor test ---" << endl;

    Array arr1(5, 5, 50, 40, 30, 20, 10);
    Array arr(arr1);

    arr1.print();
    arr.print();
}

void testOperatorAddSub() {

    cout << "--- Addition/subtraction operations test ---" << endl;

    Array arr(4);
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    Array arr1(3, 3, 30, 20, 10);

    arr.print();
    arr1.print();

    arr = arr + arr1;
    arr.print();

    arr = arr - arr1;
    arr.print();
}

void testOperatorDec() {

    cout << "--- Decrement operation test ---" << endl;

    Array arr(4);
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);
    arr.print();

    --arr;
    arr.print();
}

void testOperatorDeduction() {

    cout << "--- Deduction operation test ---" << endl;

    Array arr(4);
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);
    arr.print();

    arr-(30);
    arr.print();
}

void testOperatorIndexing() {

    cout << "--- Indexing operation test ---" << endl;

    Array arr(4);
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);
    arr.print();

    cout << arr[1] << endl;
}


#endif //CLASS_TESTS_H