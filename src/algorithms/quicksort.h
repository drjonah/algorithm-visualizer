#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "algorithm.h"
#include <iostream>
#include <string>

class QuickSort : public Algorithm {
public:
    QuickSort(int size);
    ~QuickSort() = default;

    void sort() override;
    string getName() override;

private:
    void sort(int low, int high);
    int partition(int low, int high);
};

#endif