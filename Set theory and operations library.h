#ifndef SETLIBRARY_H
#define SETLIBRARY_H

#include <iostream>
using namespace std;

class Set {
private:
    int* arr;
    int size;

public:
    // 1. Default Constructor
    Set() {
        size = 0;
        arr = nullptr;
    }

    // 2. Parameterized Constructor
    Set(int s, int values[]) {
        size = s;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = values[i];
        }
    }

    // 3. Copy Constructor
    Set(const Set& other) {
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    // Destructor
    ~Set() {
        delete[] arr;
    }

    // FUNCTION OVERLOADING (same name: addElement)

    // 1. Add single element
    void addElement(int value) {
        int* temp = new int[size + 1];

        for (int i = 0; i < size; i++)
            temp[i] = arr[i];

        temp[size] = value;
        size++;

        delete[] arr;
        arr = temp;
    }

    // 2. Add array of elements
    void addElement(int values[], int count) {
        int* temp = new int[size + count];

        for (int i = 0; i < size; i++)
            temp[i] = arr[i];

        for (int i = 0; i < count; i++)
            temp[size + i] = values[i];

        size += count;

        delete[] arr;
        arr = temp;
    }

    // 3. Add another Set
    void addElement(const Set& other) {
        int* temp = new int[size + other.size];

        for (int i = 0; i < size; i++)
            temp[i] = arr[i];

        for (int i = 0; i < other.size; i++)
            temp[size + i] = other.arr[i];

        size += other.size;

        delete[] arr;
        arr = temp;
    }

    // OPERATOR OVERLOADING

    // UNION (+)
    Set operator+(const Set& other) {
        Set result(*this);

        for (int i = 0; i < other.size; i++) {
            result.addElement(other.arr[i]);
        }
        return result;
    }

    // DIFFERENCE (-)
    Set operator-(const Set& other) {
        Set result;

        for (int i = 0; i < size; i++) {
            bool found = false;

            for (int j = 0; j < other.size; j++) {
                if (arr[i] == other.arr[j]) {
                    found = true;
                    break;
                }
            }

            if (!found)
                result.addElement(arr[i]);
        }

        return result;
    }

    // INTERSECTION (*)
    Set operator*(const Set& other) {
        Set result;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < other.size; j++) {
                if (arr[i] == other.arr[j]) {
                    result.addElement(arr[i]);
                }
            }
        }

        return result;
    }

    // COMPARISON (==)
    bool operator==(const Set& other) {
        if (size != other.size)
            return false;

        for (int i = 0; i < size; i++) {
            bool found = false;

            for (int j = 0; j < other.size; j++) {
                if (arr[i] == other.arr[j]) {
                    found = true;
                    break;
                }
            }

            if (!found)
                return false;
        }

        return true;
    }

    // OUTPUT (<<)
    friend ostream& operator<<(ostream& out, const Set& s) {
        out << "{ ";
        for (int i = 0; i < s.size; i++) {
            out << s.arr[i] << " ";
        }
        out << "}";
        return out;
    }
};

#endif#pragma once
