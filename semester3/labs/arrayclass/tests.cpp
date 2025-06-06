#include <iostream>
#include <cstring>
#include <fstream>
#include "tests.h"
#include "array.h"
#include "smartarray.h"
#include "queuearray.h"
#include "linkedlist.h"
#include "linkedlist_template.h"


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

void testOperatorInputOutput() {

    std::cout << "--- Test for overloaded input/output operators ---" << std::endl;

    Array arr(5);
    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);
    arr.add(50);

    const char* filename = "test_array.txt";

    {
        std::ofstream outFile(filename);
        if (!outFile) {
            std::cout << "Error: Cannot open file for writing!" << std::endl;
            return;
        }
        outFile << arr;
    }

    Array arrFromFile(5);

    {
        std::ifstream inFile(filename);
        if (!inFile) {
            std::cout << "Error: Cannot open file for reading!" << std::endl;
            return;
        }
        inFile >> arrFromFile;
    }

    std::cout << "Original Array: " << arr << std::endl;
    std::cout << "Array loaded from text file: " << arrFromFile << std::endl;

    if (areEqual(arr, arrFromFile)) {
        std::cout << "Text file test OK!" << std::endl;
    }

    else {
        std::cout << "Text file test failed!" << std::endl;
    }

    const char* binaryFilename = "test_array.dat";
    std::ofstream binaryOutFile(binaryFilename, std::ios::binary);

    if (!binaryOutFile) {
        std::cout << "Error: Cannot open binary file for writing!" << std::endl;
        return;
    }

    arr.writeToBinaryFile(binaryOutFile);
    binaryOutFile.close();

    std::ifstream binaryInFile(binaryFilename, std::ios::binary);

    if (!binaryInFile) {
        std::cout << "Error: Cannot open binary file for reading!" << std::endl;
        return;
    }

    Array arrFromBinaryFile(5);
    arrFromBinaryFile.readFromBinaryFile(binaryInFile);
    binaryInFile.close();

    std::cout << "Array loaded from binary file: " << arrFromBinaryFile << std::endl;

    if (arr.getCurrentSize() == arrFromBinaryFile.getCurrentSize()) {

        bool isEqual = true;

        for (int i = 0; i < arr.getCurrentSize(); ++i) {

            if (arr.get(i) != arrFromBinaryFile.get(i)) {
                isEqual = false;
                break;
            }
        }
        std::cout << (isEqual ? "Binary file test OK!" : "Binary file test failed!") << std::endl;
    }

    else {
        std::cout << "Binary file test failed!" << std::endl;
    }
}


void testSmartArrayBoundsChecking() {

    std::cout << "--- SmartArray bounds checking test ---" << std::endl;
    SmartArray sa(3);

    sa.add(10);
    sa.add(20);
    sa.add(30);

    if (sa.get(2) == 30) {
        std::cout << "Test OK!" << std::endl;
    }

    else {
        std::cout << "Test failed!" << std::endl;
    }

    try {
        sa.get(5);
        std::cout << "Test failed!" << std::endl;
    }

    catch (const std::out_of_range& e) {
        std::cout << "Test OK!" << std::endl;
    }
}

void testSmartArrayResize() {

    std::cout << "--- SmartArray resize test ---" << std::endl;
    SmartArray sa(2);

    sa.add(1);
    sa.add(2);

    try {
        sa.add(3);
        std::cout << "Test failed!" << std::endl;
    }

    catch (const std::overflow_error& e) {
        std::cout << "Test OK!" << std::endl;
    }
}

void testQueueArrayEnqueueDequeue() {

    std::cout << "--- QueueArray enqueue/dequeue test ---" << std::endl;
    QueueArray qa(3);

    qa.enqueue(10);
    qa.enqueue(20);
    qa.enqueue(30);

    if (qa.dequeue() == 10 && qa.dequeue() == 20 && qa.dequeue() == 30) {
        std::cout << "Test OK!" << std::endl;
    }

    else {
        std::cout << "Test failed!" << std::endl;
    }
}

void testQueueArrayUnderflow() {

    std::cout << "--- QueueArray underflow test ---" << std::endl;
    QueueArray qa(3);

    try {
        qa.dequeue();
        std::cout << "Test failed!" << std::endl;
    }

    catch (const std::underflow_error& e) {
        std::cout << "Test OK!" << std::endl;
    }
}

void testQueueArrayCircularBehavior() {

    std::cout << "--- QueueArray circular behavior test ---" << std::endl;
    QueueArray qa(3);

    qa.enqueue(1);
    qa.enqueue(2);
    qa.enqueue(3);
    qa.dequeue();
    qa.enqueue(4);

    char check[50];
    snprintf(check, sizeof(check), "%s", qa.toString());

    if (strcmp(check, "2 3 4 ") == 0) {
        std::cout << "Test OK!" << std::endl;
    }

    else {
        std::cout << "Test failed!" << std::endl;
    }
}

void testLinkedListAdd() {

    std::cout << "--- LinkedList add test ---\n";
    LinkedList list;

    Array* smartArray = new SmartArray(5);
    smartArray->add(10);
    smartArray->add(20);

    list.add(smartArray);

    char* listStr = list.toString();

    if (strcmp(listStr, "10 20 -> (back to head)") == 0) {
        std::cout << "Test OK!\n";
    }

    else {
        std::cout << "Test failed!\n";
    }

    delete[] listStr;
}

void testLinkedListInsertAt() {

    std::cout << "--- LinkedList insertAt test ---\n";
    LinkedList list;

    Array* smartArray1 = new SmartArray(5);
    smartArray1->add(10);
    list.add(smartArray1);

    Array* smartArray2 = new SmartArray(5);
    smartArray2->add(20);
    list.insertAt(0, smartArray2);

    char* listStr = list.toString();

    if (strcmp(listStr, "20 -> 10 -> (back to head)") == 0) {
        std::cout << "Test OK!\n";
    }

    else {
        std::cout << "Test failed!\n";
    }

    delete[] listStr;
}

void testLinkedListRemoveAt() {

    std::cout << "--- LinkedList removeAt test ---\n";
    LinkedList list;

    Array* smartArray1 = new SmartArray(5);
    smartArray1->add(10);
    list.add(smartArray1);

    Array* smartArray2 = new SmartArray(5);
    smartArray2->add(20);
    list.add(smartArray2);

    list.removeAt(0);

    char* listStr = list.toString();

    if (strcmp(listStr, "20 -> (back to head)") == 0) {
        std::cout << "Test OK!\n";
    }

    else {
        std::cout << "Test failed!\n";
    }

    delete[] listStr;
}

void testLinkedListSearch() {

    std::cout << "--- LinkedList search test ---\n";
    LinkedList list;

    Array* smartArray1 = new SmartArray(5);
    smartArray1->add(10);
    list.add(smartArray1);

    Array* smartArray2 = new SmartArray(5);
    smartArray2->add(20);
    list.add(smartArray2);

    Node* found = list.search(10);

    if (found != nullptr && found->data->get(0) == 10) {
        std::cout << "Test 1 OK!\n";
    }

    else {
        std::cout << "Test 1 failed!\n";
    }

    found = list.search(30);

    if (found == nullptr) {
        std::cout << "Test 2 OK!\n";
    }

    else {
        std::cout << "Test 2 failed!\n";
    }
}

void testLinkedListToString() {

    std::cout << "--- LinkedList toString test ---\n";
    LinkedList list;

    Array* smartArray1 = new SmartArray(5);
    smartArray1->add(10);
    smartArray1->add(20);
    list.add(smartArray1);

    char* listStr = list.toString();

    if (strcmp(listStr, "10 20 -> (back to head)") == 0) {
        std::cout << "Test OK!\n";
    }

    else {
        std::cout << "Test failed!\n";
    }

    delete[] listStr;
}

void testLinkedListPolymorphism() {

    std::cout << "--- LinkedList polymorphism test ---\n";
    LinkedList list;

    Array* smartArray = new SmartArray(5);
    smartArray->add(1);
    smartArray->add(2);
    list.add(smartArray);

    QueueArray* queueArray = new QueueArray(5);
    queueArray->enqueue(10);
    queueArray->enqueue(20);
    list.add(queueArray);

    char* listStr = list.toString();

    if (strcmp(listStr, "1 2 -> 10 20 -> (back to head)") == 0) {
        std::cout << "Test OK!\n";
    }

    else {
        std::cout << "Test failed!\n";
    }

    delete[] listStr;
}

void testTemplate() {

    std::cout << "--- LinkedListTemplate test ---\n";

    LinkedListTemplate<int> intList;
    intList.add(10);
    intList.add(20);
    intList.add(30);
    intList.insertAt(1, 15);
    intList.removeAt(2);

    char* intListStr = intList.toString();

    if (strcmp(intListStr, "10 -> 15 -> 30 -> (back to head)") == 0) {
        std::cout << "Test 1 OK!\n";
    }

    else {
        std::cout << "Test 1 failed!\n";
    }

    delete[] intListStr;

    LinkedListTemplate<float> floatList;
    floatList.add(10.5f);
    floatList.add(20.75f);
    floatList.add(30.25f);
    floatList.insertAt(0, 5.0f);
    floatList.removeAt(1);

    char* floatListStr = floatList.toString();

    if (strcmp(floatListStr, "5 -> 20.75 -> 30.25 -> (back to head)") == 0) {
        std::cout << "Test 2 OK!\n";
    }

    else {
        std::cout << "Test 2 failed!\n";
    }

    delete[] floatListStr;

    LinkedListTemplate<Array> arrayList;
    Array arr1(3);
    arr1.add(1);
    arr1.add(2);
    arr1.add(3);
    arrayList.add(arr1);

    Array arr2(2);
    arr2.add(4);
    arr2.add(5);
    arrayList.add(arr2);

    Array arr3(1);
    arr3.add(9);
    arrayList.insertAt(1, arr3);
    arrayList.removeAt(0);

    char* arrayListStr = arrayList.toString();

    if (strcmp(arrayListStr, "[9] -> [4 5] -> (back to head)") == 0) {
        std::cout << "Test 3 OK!\n";
    }

    else {
        std::cout << "Test 3 failed!\n";
    }

    delete[] arrayListStr;
}