#ifndef GUI_MANAGER_H
#define GUI_MANAGER_H
#define GL_SILENCE_DEPRECATION

#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

class GuiManager {
public:
    GuiManager(const std::string& name);
    ~GuiManager();

    GLFWwindow* getWindow();
    void render(int* array, int num_elements); 

private:
    std::string window_name;
    GLFWwindow* window;

    int screenSize = 500;

    void draw_line(int x, int width, int height);        
};

#endif