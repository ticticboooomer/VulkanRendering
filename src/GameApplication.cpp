//
// Created by tic on 12/17/25.
//

#include "GameApplication.h"

#include <iostream>
#include <GLFW/glfw3.h>

void GameApplication::run() {
    initializeWindow();
    initializeVulkan();
    mainLoop();
    cleanup();
}

void GameApplication::initializeWindow() {
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

    // setup glfw window
}

void GameApplication::initializeVulkan() {}

void GameApplication::mainLoop() {}

void GameApplication::cleanup() {}