#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <iostream>
#include <string>
using namespace std;

class Algorithm {
public:
    // Constructor
    Algorithm(int numElements);
    virtual ~Algorithm() = default;

    // Pure virtual sort function
    virtual void sort() = 0;
    virtual string getName() = 0;

    // General functions
    int* getArray() { return array; };
    int getSize() { return size; };
    void reset();
    bool isSorted();

protected:
    int size;
    int* array;

    void buildArray();
    void swap(int* a, int* b);
};

#endif
