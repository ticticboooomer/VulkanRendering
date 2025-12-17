cmake_minimum_required(VERSION 4.1)
project(VulkanRender VERSION 0.1.0 LANGUAGES C CXX)

set(SOURCE_FILES
        src/main.cpp
        src/GameApplication.cpp
        src/GameApplication.h)

set(CMAKE_C_STANDARD 17)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(VulkanRender ${SOURCE_FILES})

target_include_directories(VulkanRender PUBLIC ${Vulkan_INCLUDE_DIRS})
target_link_libraries(VulkanRender Vulkan::Vulkan)

target_include_directories(VulkanRender PUBLIC ${Glfw3_INCLUDE_DIRS})
target_link_libraries(VulkanRender glfw)

