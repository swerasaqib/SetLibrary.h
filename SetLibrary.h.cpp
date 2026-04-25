#include <iostream>
#include "SetLibrary.h"
using namespace std;

int main() {

    int arr1[] = { 1, 2, 3 };
    int arr2[] = { 3, 4, 5 };

    Set A(3, arr1);
    Set B(3, arr2);

    // Function Overloading Demonstration
    A.addElement(10); // single value

    int newVals[] = { 20, 30 };
    A.addElement(newVals, 2); // array

    A.addElement(B); // another set

    cout << "Set A: " << A << endl;
    cout << "Set B: " << B << endl;

    // Operator Overloading

    Set unionSet = A + B;
    cout << "Union (A + B): " << unionSet << endl;

    Set diffSet = A - B;
    cout << "Difference (A - B): " << diffSet << endl;

    Set interSet = A * B;
    cout << "Intersection (A * B): " << interSet << endl;

    if (A == B)
        cout << "Sets are equal" << endl;
    else
        cout << "Sets are NOT equal" << endl;

    return 0;
}