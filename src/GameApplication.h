//
// Created by tic on 12/17/25.
//

#ifndef VULKANRENDER_GAMEAPPLICATION_H
#define VULKANRENDER_GAMEAPPLICATION_H

#include "GLFW/glfw3.h"
#include <vulkan/vulkan.h>

const int WIDTH = 800;
const int HEIGHT = 600;

class GameApplication {
public:
     void run();

private:
     void initializeVulkan();

     void mainLoop();

     void cleanup();

     void initializeWindow();

     void createVkInstance();

     VkInstance instance;
     GLFWwindow *window;
};


#endif //VULKANRENDER_GAMEAPPLICATION_H