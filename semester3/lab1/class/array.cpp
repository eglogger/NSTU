#include "array.h"
#include "tests.h"

using namespace std;


int main() {

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
    testOperatorAddSub();
    testOperatorDec();
    testOperatorDeduction();
    testOperatorIndexing();
    testAreEqual();

    return 0;
}