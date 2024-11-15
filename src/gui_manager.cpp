#include "gui_manager.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex arrayMutex2;
using namespace std;

GuiManager::GuiManager(const string& name) : window_name(name) {
    cout << "GuiManager initialized" << endl;

    if (!glfwInit()) {
        cerr << "Failed to initialize GLFW." << endl;
        return;
    }

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    window = glfwCreateWindow(screenSize, screenSize, window_name.c_str(), NULL, NULL);
    if (!window) {
        cerr << "Failed to create GLFW window." << endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
}

GuiManager::~GuiManager() {
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
    cout << "GuiManager destroyed." << endl;
}

GLFWwindow* GuiManager::getWindow() {
    return window;
}

void GuiManager::render(int* array, int num_elements) {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (int i = 0; i < num_elements; ++i) {
        int width = screenSize / num_elements;
        int height = array[i] * 5; // 5 because the max value is 100 and the screen size is 500

        draw_line(i * width, width, height);
    }
}

void GuiManager::draw_line(int x, int width, int height) {
    glPointSize(10);  
    glLineWidth(2);  

    // Generate a random color for the rectangle
    srand(height);
    float red = static_cast<float>(rand() % 256) / 255.0f;
    float green = static_cast<float>(rand() % 256) / 255.0f;
    float blue = static_cast<float>(rand() % 256) / 255.0f;
    glColor3f(red, green, blue);
    

    // Normalize coordinates based on the window dimensions
    double xx = (x / 500.0) * 2.0 - 1.0;  // Normalize x position to the range [-1, 1]
    double rect_width = (width / 500.0) * 2.0;  // Normalize width to be within [-1, 1]
    double rect_height = (height / 500.0) * 2.0;  // Normalize height to be within [-1, 1]

    // Draw the rectangle using normalized coordinates
    glBegin(GL_QUADS);
        glVertex3f(xx, -1.0, 0.0);  // Bottom Left (BL)
        glVertex3f(xx + rect_width, -1.0, 0.0);  // Bottom Right (BR)
        glVertex3f(xx + rect_width, -1.0 + rect_height, 0.0);  // Top Right (TR)
        glVertex3f(xx, -1.0 + rect_height, 0.0);  // Top Left (TL)
    glEnd();
}