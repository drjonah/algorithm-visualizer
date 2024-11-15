#include "mergesort.h"
#include <thread>
#include <iostream>
#include <string>
using namespace std;

MergeSort::MergeSort(int size) : Algorithm(size) {
    cout << "QuickSort initialized" << endl;
}

////////// PUBLIC METHODS //////////

void MergeSort::sort()  {
    sort(0, size - 1);
}

string MergeSort::getName() {
    return "MergeSort";
}

////////// PRIVATE METHODS //////////

void MergeSort::sort(int left, int right)  {
    if (left < right) {
        int mid = left + (right - left) / 2;

        sort(left, mid);
        sort(mid + 1, right);

        merge(left, mid, right);
    }
}

void MergeSort::merge(int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = array[low + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = array[mid + 1 + j];
    }

    // Merge the temporary arrays back into array[low..high]
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = low; // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;

        this_thread::sleep_for(chrono::milliseconds(1000 / size * 2));
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}