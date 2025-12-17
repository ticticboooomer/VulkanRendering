//
// Created by tic on 12/17/25.
//

#ifndef VULKANRENDER_GAMEAPPLICATION_H
#define VULKANRENDER_GAMEAPPLICATION_H

#include "GLFW/glfw3.h"
#include <vulkan/vulkan.h>
#include <array>
#include <vector>

const int WIDTH = 800;
const int HEIGHT = 600;

constexpr std::array validationLayers{
    "VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

class GameApplication {
public:
    void run();

private:
    void initializeVulkan();

    void mainLoop();

    void cleanup();

    void initializeWindow();

    void createVkInstance();

    void setupDebugMessenger();

    bool checkValidationLayerSupport();

    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

    std::vector<const char *> getRequiredExtensions();

    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
    GLFWwindow *window;
};


#endif //VULKANRENDER_GAMEAPPLICATION_H
