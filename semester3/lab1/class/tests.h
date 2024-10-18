#include <iostream>
#include <cstring>
#include <cassert>
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

    char check[50];
    snprintf(check, sizeof(check), "%s", arr.toString());

    if (strcmp(check, "10 20 30 40 ") == 0) {
        cout << "Test OK!" << endl;
    } else {
        cout << "Test failed!" << endl;
    }
}

void testGet() {

    cout << "--- get test ---" << endl;
    Array arr(4);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    if (arr.get(0) == 10) {
        cout << "Test OK!" << endl;
    } else {
        cout << "Test failed!" << endl;
    }
}

void testSetGetCurr() {

    cout << "--- setCurrentIndex/getCurrentElement test ---" << endl;
    Array arr(4);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    arr.setCurrentIndex(2);

    if ((arr.getCurrentElement() == 30) && (arr.getCurrentIndex() == 2)) {
        cout << "Test OK!" << endl;
    }

    else {
        cout << "Test failed!" << endl;
    }
}

void testNextPrev() {

    cout << "--- next/prev test ---" << endl;
    Array arr(4);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    arr.next();
    arr.prev();

    char check[10];
    snprintf(check, sizeof(check), "%d", arr.getCurrentElement());

    if (strcmp(check, "10") == 0) {
        cout << "Test OK!" << endl;
    } else {
        cout << "Test failed!" << endl;
    }
}

void testSearch() {

    cout << "--- search test ---" << endl;
    Array arr(4);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    arr.setCurrentIndex(arr.search(10));

    char check[10];
    snprintf(check, sizeof(check), "%d", arr.getCurrentElement());

    if (strcmp(check, "10") == 0) {
        cout << "Test OK!" << endl;
    }

    else {
        cout << "Test failed!" << endl;
    }
}

void testSet() {

    cout << "--- set test ---" << endl;
    Array arr(4);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    arr.set(0, 5);

    char check[50];
    snprintf(check, sizeof(check), "%s", arr.toString());

    if (strcmp(check, "5 20 30 40 ") == 0) {
        cout << "Test OK!" << endl;
    }

    else {
        cout << "Test failed!" << endl;
    }
}

void testRemove() {

    cout << "--- remove test ---" << endl;
    Array arr(4);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    arr.remove(0);

    char check[50];
    snprintf(check, sizeof(check), "%s", arr.toString());

    if (strcmp(check, "20 30 40 ") == 0) {
        cout << "Test OK!" << endl;
    }

    else {
        cout << "Test failed!" << endl;
    }
}

void testGetCurrSize() {

    cout << "--- getCurrentSize test ---" << endl;
    Array arr(3);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    char check[10];
    snprintf(check, sizeof(check), "%d", arr.getCurrentSize());

    if (strcmp(check, "4") == 0) {
        cout << "Test OK!" << endl;
    }

    else {
        cout << "Test failed!" << endl;
    }
}

void testNewConstructor() {

    cout << "--- New Constructor test ---" << endl;

    Array arr1(5, 5, 50, 40, 30, 20, 10);

    char check[50];
    snprintf(check, sizeof(check), "%s", arr1.toString());

    if (strcmp(check, "50 40 30 20 10 ") == 0) {
        cout << "Test OK!" << endl;
    }

    else {
        cout << "Test failed!" << endl;
    }
}

void testCopyConstructor() {

    cout << "--- Copy Constructor test ---" << endl;

    Array arr1(5, 5, 50, 40, 30, 20, 10);
    Array arr(arr1);

    char check1[50];
    char check2[50];

    snprintf(check1, sizeof(check1), "%s", arr.toString());
    snprintf(check2, sizeof(check2), "%s", arr1.toString());

    if (strcmp(check1, check2) == 0) {
        cout << "Test OK!" << endl;
    }

    else {
        cout << "Test failed!" << endl;
    }
}

void testOperatorAddSub() {

    cout << "--- Addition/subtraction operations test ---" << endl;

    Array arr(4);
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    Array arr1(3, 3, 30, 20, 10);

    arr = arr + arr1;

    char check[50];
    snprintf(check, sizeof(check), "%s", arr.toString());

    if (strcmp(check, "40 40 40 40 ") == 0) {
        cout << "Test OK!" << endl;
    }

    else {
        cout << "Test failed!" << endl;
    }

    arr = arr - arr1;
    snprintf(check, sizeof(check), "%s", arr.toString());

    if (strcmp(check, "10 20 30 40 ") == 0) {
        cout << "Test OK!" << endl;
    }

    else {
        cout << "Test failed!" << endl;
    }
}

void testOperatorDec() {

    cout << "--- Decrement operation test ---" << endl;

    Array arr(4);
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    --arr;

    char check[50];
    snprintf(check, sizeof(check), "%s", arr.toString());

    if (strcmp(check, "9 19 29 39 ") == 0) {
        cout << "Test OK!" << endl;
    } else {
        cout << "Test failed!" << endl;
    }
}

void testOperatorDeduction() {

    cout << "--- Deduction operation test ---" << endl;

    Array arr(4);
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    arr-(30);

    char check[50];
    snprintf(check, sizeof(check), "%s", arr.toString());

    if (strcmp(check, "10 20 40 ") == 0) {
        cout << "Test OK!" << endl;
    }

    else {
        cout << "Test failed!" << endl;
    }
}

void testOperatorIndexing() {

    cout << "--- Indexing operation test ---" << endl;

    Array arr(4);
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    char check[10];
    snprintf(check, sizeof(check), "%d", arr[0]);

    if (strcmp(check, "10") == 0) {
        cout << "Test OK!" << endl;
    }

    else {
        cout << "Test failed!" << endl;
    }
}

void testAreEqual() {

    cout << "--- areEqual test ---" << endl;

    Array arr(4);
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    Array arr1(4);
    arr1.add(10);
    arr1.add(30);
    arr1.add(30);
    arr1.add(40);

    if (!areEqual(arr, arr1)) {
        cout << "Test OK!" << endl;
    }

    else {
        cout << "Test failed!" << endl;
    }
}

#endif //CLASS_TESTS_H
