#include "quicksort.h"
#include <thread>
#include <iostream>
#include <string>
using namespace std;

QuickSort::QuickSort(int size) : Algorithm(size) {
    cout << "QuickSort initialized" << endl;
}

////////// PUBLIC METHODS //////////

void QuickSort::sort()  {
    sort(0, size - 1);
}

string QuickSort::getName() {
    return "QuickSort";
}

////////// PRIVATE METHODS //////////

void QuickSort::sort(int low, int high)  {
    
    if (low < high) {
        // pi is the partitioning index
        int pi = partition(low, high);

        // Sort the elements before and after the partition
        sort(low, pi - 1);
        sort(pi + 1, high);
    }
}

int QuickSort::partition(int low, int high) {
    // Choose the pivot element
    int pivot = array[high];

    // Index of the smaller element
    int i = low - 1;

    // Iterate through the array
    for (int j = low; j <= high - 1; ++j) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);

            this_thread::sleep_for(chrono::milliseconds(1000 / size * 2));
        }
    }

    // Swap the pivot element with the element at index i + 1
    swap(&array[i + 1], &array[high]);
    return i + 1;
}

