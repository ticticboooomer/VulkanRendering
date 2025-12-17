cmake_minimum_required(VERSION 4.1)
project(VulkanRender VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_C_STANDARD 17)

set(SOURCE_FILES
        src/main.cpp
        src/GameApplication.cpp
        src/GameApplication.h
        src/Macros.h)


add_subdirectory(thirdparty)

find_package(Vulkan REQUIRED)

add_executable(VulkanRender ${SOURCE_FILES})

target_include_directories(VulkanRender PUBLIC ${Vulkan_INCLUDE_DIRS})
target_link_libraries(VulkanRender Vulkan::Vulkan)

target_link_libraries(VulkanRender glfw)

