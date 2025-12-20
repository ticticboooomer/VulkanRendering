//
// Created by tic on 12/17/25.
//

#ifndef VULKANRENDER_MACROS_H
#define VULKANRENDER_MACROS_H

#include <iostream>

#define VK_FAIL(x)                                                  \
       std::cout << "Detected Vulkan error: " << x << std::endl;    \
    throw std::runtime_error("failed to create Vulkan context!");


#define VK_CHECK(x)                                                     \
    do                                                                  \
    {                                                                   \
        VkResult err = x;                                               \
        if (err)                                                        \
        {                                                               \
           VK_FAIL(x)                                                   \
        }                                                               \
    } while (0)


#define LOGLN(x) std::cout << x << std::endl

#endif //VULKANRENDER_MACROS_H
