#ifndef MERGESORT_H
#define MERGESORT_H

#include "algorithm.h"
#include <iostream>
#include <string>

class MergeSort : public Algorithm {
public:
    MergeSort(int size);
    ~MergeSort() = default;

    void sort() override;
    string getName() override;

private:
    void sort(int left, int right);
    void merge(int low, int mid, int high);
};

#endif