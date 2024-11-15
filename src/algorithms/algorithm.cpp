#include "algorithm.h"

#include <iostream>
using namespace std;

////////// CONSTRUCTORS //////////

Algorithm::Algorithm(int numElements) {
    size = numElements;
    buildArray();
}

////////// PROTECTED METHODS //////////

void Algorithm::reset() {
    delete[] array;
    buildArray();
}

bool Algorithm::isSorted() {
    for (int i = 0; i < size - 1; ++i) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }

    return true;
}

////////// PRIVATE METHODS //////////

void Algorithm::buildArray() {
    // Seed the random number generator with the current time
    srand(time(0)); 

    array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100;
    }
}

void Algorithm::swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}