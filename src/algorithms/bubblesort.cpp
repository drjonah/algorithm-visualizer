#include "bubblesort.h"
#include <thread>
#include <iostream>
#include <string>
using namespace std;

BubbleSort::BubbleSort(int size) : Algorithm(size) {
    cout << "BubbleSort initialized" << endl;
}

////////// PUBLIC METHODS //////////

void BubbleSort::sort()  {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);

                this_thread::sleep_for(chrono::milliseconds(1000 / size * 2));
            }
        }
    }
}

string BubbleSort::getName() {
    return "BubbleSort";
}
