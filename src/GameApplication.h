//
// Created by tic on 12/17/25.
//

#ifndef VULKANRENDER_GAMEAPPLICATION_H
#define VULKANRENDER_GAMEAPPLICATION_H


class GameApplication {
public:
     void run();

private:
     void initializeVulkan();

     void mainLoop();

     void cleanup();

     void initializeWindow();
};


#endif //VULKANRENDER_GAMEAPPLICATION_H