//
// Created by tic on 12/17/25.
//

#ifndef VULKANRENDER_MACROS_H
#define VULKANRENDER_MACROS_H

#include <iostream>


#define VK_CHECK(x)                                                     \
    do                                                                  \
    {                                                                   \
        VkResult err = x;                                               \
        if (err)                                                        \
        {                                                               \
            std::cout << "Detected Vulkan error: " << err << std::endl; \
            abort();                                                    \
        }                                                               \
    } while (0)

#define LOGLN(x) std::cout << x << std::endl

#endif //VULKANRENDER_MACROS_H


