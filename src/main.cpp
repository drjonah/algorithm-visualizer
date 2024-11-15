#include "gui_manager.h"
#include "algorithms/algorithm.h"
#include "algorithms/bubblesort.h"
#include "algorithms/mergesort.h"
#include "algorithms/quicksort.h"
#include <GLFW/glfw3.h>
#include <thread>
#include <iostream>
#include <atomic>
#include <string>
using namespace std;

void runSortingAlgorithm(Algorithm* alg, atomic<bool>& running);

int main() {
    // Initialize the GUI manager
    GuiManager manager("Algorithm Visualizer");

    // Create an instance of the sorting algorithm
    // Algorithm* alg = new BubbleSort(500);
    // Algorithm* alg = new MergeSort(500);
    Algorithm* alg = new QuickSort(500);
    
    atomic<bool> running(true);

    // Run the sorting algorithm in a separate thread
    thread sortingThread(runSortingAlgorithm, alg, ref(running));

    // Main render loop
    while (!glfwWindowShouldClose(manager.getWindow())) {
        // Close if the user presses the ESC key
        if (glfwGetKey(manager.getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(manager.getWindow(), GLFW_TRUE);
        }

        // Render the current state of the array
        manager.render(alg->getArray(), alg->getSize());
        glfwSwapBuffers(manager.getWindow());
        glfwPollEvents();
    }

    // Stop the sorting algorithm
    running = false;

    // Ensure the sorting thread finishes
    if (sortingThread.joinable()) {
        sortingThread.join();
    }

    // Clean up
    delete alg;

    return 0;
}

void runSortingAlgorithm(Algorithm* alg, atomic<bool>& running) {
    while (running) {
        // Start the sorting process
        alg->sort();

        // Delay before resetting for visualization
        this_thread::sleep_for(chrono::milliseconds(500));
        alg->reset();
    }
}
