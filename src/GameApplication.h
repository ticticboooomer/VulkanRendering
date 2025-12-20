//
// Created by tic on 12/17/25.
//

#ifndef VULKANRENDER_GAMEAPPLICATION_H
#define VULKANRENDER_GAMEAPPLICATION_H

#include <vulkan/vulkan.h>
#include <array>
#include <optional>
#include <vector>

#include <GLFW/glfw3.h>

const int WIDTH = 800;
const int HEIGHT = 600;

constexpr std::array validationLayers{
    "VK_LAYER_KHRONOS_validation"
};

const std::vector deviceExtensions = {
    VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() const {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

struct SwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};


class GameApplication {
public:
    void run();

private:

    void initializeVulkan();

    void mainLoop();

    void cleanup();

    void initializeWindow();

    void createVkInstance();

    void createSurface();

    void pickPhysicalDevice();

    void createLogicalDevice();

    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);

    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);

    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

    void createSwapChain();

    void createImageViews();

    void createGraphicsPipeline();

    void createRenderPass();

    void createFrameBuffers();

    void createCommandPool();

    void createCommandBuffer();

    void createSyncObjects();

    void drawFrame();

    void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

    VkShaderModule createShaderModule(const std::vector<char>& code);

    bool isDeviceSuitable(VkPhysicalDevice device);

    bool checkDeviceExtensionSupport(VkPhysicalDevice device);

    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

    void setupDebugMessenger();

    bool checkValidationLayerSupport();

    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

    std::vector<const char *> getRequiredExtensions();

    std::vector<VkImage> swapChainImages;

    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
    VkQueue graphicsQueue;
    VkQueue presentQueue;
    VkSurfaceKHR surface;
    VkSwapchainKHR swapChain;
    VkFormat swapChainImageFormat;
    std::vector<VkImageView> swapChainImageViews;
    VkExtent2D swapChainExtent;
    VkRenderPass renderPass;
    VkPipelineLayout pipelineLayout;
    VkPipeline graphicsPipeline;
    std::vector<VkFramebuffer> swapChainFrameBuffers;
    VkCommandPool commandPool;
    VkCommandBuffer commandBuffer;
    VkSemaphore imageAvailableSemaphore;
    VkSemaphore renderFinishedSemaphore;
    VkFence inFlightFence;
    VkDevice device;
    GLFWwindow *window;
};


#endif //VULKANRENDER_GAMEAPPLICATION_H
