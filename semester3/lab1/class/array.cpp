#include <iostream>
#include "array.h"

using namespace std;


int main() {

    Array arr(3);

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    arr.print();

    cout << arr.get(2) << endl;

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

    arr.set(0, 5);
    arr.print();

    arr.remove(0);
    arr.print();

    cout << arr.getCurrentSize() << endl;

    Array arr1(5, 5, 50, 40, 30, 20, 10);
    arr1.print();

    arr1.print();
    arr.print();

    arr = arr1 + arr;
    arr.print();

    arr = arr - arr1;
    arr.print();

    --arr;
    arr.print();

    arr-(39);
    arr.print();

    arr[1] = 40;
    arr.print();

    cout << arr1.getCurrentSize() << endl;

    return 0;
}