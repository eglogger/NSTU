#include <iostream>
#include "class.h"

using namespace std;


int main() {

    Array arr(5);

    arr.add(10);
    arr.add(20);
    arr.add(30);

    arr.print();

    cout << "Current Element: " << arr.getCurrentElement() << " Index: "
    << arr.getCurrentIndex() << endl;

    arr.next();
    cout << "Current Element: " << arr.getCurrentElement() << " Index: "
    << arr.getCurrentIndex() << endl;

    arr.prev();
    cout << "Current Element: " << arr.getCurrentElement() << " Index: "
    << arr.getCurrentIndex() << endl;

    arr.setCurrentIndex(2);
    cout << "Current Element: " << arr.getCurrentElement() << " Index: "
    << arr.getCurrentIndex() << endl;

    arr.setCurrentIndex(arr.search(10));
    cout << "Current Element: " << arr.getCurrentElement() << " Index: "
    << arr.getCurrentIndex() << endl;

    arr.replace(0, 5);
    arr.print();

    arr.remove(0);
    arr.print();

    cout << arr.getCurrentSize() << endl;

    return 0;
}