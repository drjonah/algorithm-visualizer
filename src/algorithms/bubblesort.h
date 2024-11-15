#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "algorithm.h"
#include <iostream>
#include <string>

class BubbleSort : public Algorithm {
public:
    BubbleSort(int size);
    ~BubbleSort() = default;

    void sort() override;
    string getName() override;
};

#endif