#include "tests.h"


int main() {

    /*/ Lab1 /*/
    testAdd();
    testGet();
    testSetGetCurr();
    testNextPrev();
    testSearch();
    testSet();
    testRemove();
    testGetCurrSize();
    testNewConstructor();
    testCopyConstructor();

    /*/ Lab2 /*/
    testOperatorAddSub();
    testOperatorDec();
    testOperatorDeduction();
    testOperatorIndexing();
    testAreEqual();

    /*/ Lab3 /*/
    testOperatorInputOutput();

    /*/ Lab4 /*/
    testSmartArrayBoundsChecking();
    testSmartArrayResize();
    testQueueArrayEnqueueDequeue();
    testQueueArrayUnderflow();
    testQueueArrayCircularBehavior();

    return 0;
}