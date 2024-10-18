#include <iostream>
#include <cstring>
#include "array.h"
#include "tests.h"


void testAdd() {

    std::cout << "--- add test ---" << std::endl;
    Array arr(3);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    char check[50];
    snprintf(check, sizeof(check), "%s", arr.toString());

    if (strcmp(check, "10 20 30 40 ") == 0) {
        std::cout << "Test OK!" << std::endl;
    }

    else {
        std::cout << "Test failed!" << std::endl;
    }
}

void testGet() {

    std::cout << "--- get test ---" << std::endl;
    Array arr(4);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    if (arr.get(0) == 10) {
        std::cout << "Test OK!" << std::endl;
    }

    else {
        std::cout << "Test failed!" << std::endl;
    }
}

void testSetGetCurr() {

    std::cout << "--- setCurrentIndex/getCurrentElement test ---" << std::endl;
    Array arr(4);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    arr.setCurrentIndex(2);

    if ((arr.getCurrentElement() == 30) && (arr.getCurrentIndex() == 2)) {
        std::cout << "Test OK!" << std::endl;
    }

    else {
        std::cout << "Test failed!" << std::endl;
    }
}

void testNextPrev() {

    std::cout << "--- next/prev test ---" << std::endl;
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
        std::cout << "Test OK!" << std::endl;
    }

    else {
        std::cout << "Test failed!" << std::endl;
    }
}

void testSearch() {

    std::cout << "--- search test ---" << std::endl;
    Array arr(4);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    arr.setCurrentIndex(arr.search(10));

    char check[10];
    snprintf(check, sizeof(check), "%d", arr.getCurrentElement());

    if (strcmp(check, "10") == 0) {
        std::cout << "Test OK!" << std::endl;
    }

    else {
        std::cout << "Test failed!" << std::endl;
    }
}

void testSet() {

    std::cout << "--- set test ---" << std::endl;
    Array arr(4);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    arr.set(0, 5);

    char check[50];
    snprintf(check, sizeof(check), "%s", arr.toString());

    if (strcmp(check, "5 20 30 40 ") == 0) {
        std::cout << "Test OK!" << std::endl;
    }

    else {
        std::cout << "Test failed!" << std::endl;
    }
}

void testRemove() {

    std::cout << "--- remove test ---" << std::endl;
    Array arr(4);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    arr.remove(0);

    char check[50];
    snprintf(check, sizeof(check), "%s", arr.toString());

    if (strcmp(check, "20 30 40 ") == 0) {
        std::cout << "Test OK!" << std::endl;
    }

    else {
        std::cout << "Test failed!" << std::endl;
    }
}

void testGetCurrSize() {

    std::cout << "--- getCurrentSize test ---" << std::endl;
    Array arr(3);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    char check[10];
    snprintf(check, sizeof(check), "%d", arr.getCurrentSize());

    if (strcmp(check, "4") == 0) {
        std::cout << "Test OK!" << std::endl;
    }

    else {
        std::cout << "Test failed!" << std::endl;
    }
}

void testNewConstructor() {

    std::cout << "--- New Constructor test ---" << std::endl;

    Array arr1(5, 5, 50, 40, 30, 20, 10);

    char check[50];
    snprintf(check, sizeof(check), "%s", arr1.toString());

    if (strcmp(check, "50 40 30 20 10 ") == 0) {
        std::cout << "Test OK!" << std::endl;
    }

    else {
        std::cout << "Test failed!" << std::endl;
    }
}

void testCopyConstructor() {

    std::cout << "--- Copy Constructor test ---" << std::endl;

    Array arr1(5, 5, 50, 40, 30, 20, 10);
    Array arr(arr1);

    char check1[50];
    char check2[50];

    snprintf(check1, sizeof(check1), "%s", arr.toString());
    snprintf(check2, sizeof(check2), "%s", arr1.toString());

    if (strcmp(check1, check2) == 0) {
        std::cout << "Test OK!" << std::endl;
    }

    else {
        std::cout << "Test failed!" << std::endl;
    }
}

void testOperatorAddSub() {

    std::cout << "--- Addition/subtraction operations test ---" << std::endl;

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
        std::cout << "Test OK!" << std::endl;
    }

    else {
        std::cout << "Test failed!" << std::endl;
    }

    arr = arr - arr1;
    snprintf(check, sizeof(check), "%s", arr.toString());

    if (strcmp(check, "10 20 30 40 ") == 0) {
        std::cout << "Test OK!" << std::endl;
    }

    else {
        std::cout << "Test failed!" << std::endl;
    }
}

void testOperatorDec() {

    std::cout << "--- Decrement operation test ---" << std::endl;

    Array arr(4);
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    --arr;

    char check[50];
    snprintf(check, sizeof(check), "%s", arr.toString());

    if (strcmp(check, "9 19 29 39 ") == 0) {
        std::cout << "Test OK!" << std::endl;
    }

    else {
        std::cout << "Test failed!" << std::endl;
    }
}

void testOperatorDeduction() {

    std::cout << "--- Deduction operation test ---" << std::endl;

    Array arr(4);
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    arr-(30);

    char check[50];
    snprintf(check, sizeof(check), "%s", arr.toString());

    if (strcmp(check, "10 20 40 ") == 0) {
        std::cout << "Test OK!" << std::endl;
    }

    else {
        std::cout << "Test failed!" << std::endl;
    }
}

void testOperatorIndexing() {

    std::cout << "--- Indexing operation test ---" << std::endl;

    Array arr(4);
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    char check[10];
    snprintf(check, sizeof(check), "%d", arr[0]);

    if (strcmp(check, "10") == 0) {
        std::cout << "Test OK!" << std::endl;
    }

    else {
        std::cout << "Test failed!" << std::endl;
    }
}

void testAreEqual() {

    std::cout << "--- areEqual test ---" << std::endl;

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
        std::cout << "Test OK!" << std::endl;
    }

    else {
        std::cout << "Test failed!" << std::endl;
    }
}