#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include "VDeleter.h"
#include "VulkanInstanceCreation.h"
#pragma once

class VulkanDevicePicker
{
public:
	VulkanDevicePicker(VulkanInstanceCreation * vic, GLFWwindow * window);
	~VulkanDevicePicker();
	void createSurface(GLFWwindow* window);
	void createImageViews();

	//Joe's stuff

	void createShaderModule(const std::vector<char>& code, VDeleter<VkShaderModule>& shaderModule);
	void createRenderPass();
	void createGraphicsPipeline();
	void createCommandPool();
	void createCommandBuffers();
	void createFramebuffers();

	struct QueueFamilyIndices {
		int graphicsFamily = -1;
		int presentFamily = -1;

		bool isComplete() {
			return graphicsFamily >= 0 && presentFamily >= 0;
		}
	};

	struct SwapChainSupportDetails {
		VkSurfaceCapabilitiesKHR capabilities;
		vector<VkSurfaceFormatKHR> formats;
		vector<VkPresentModeKHR> presentModes;
	};

	void pickPhysicalDevice(VulkanInstanceCreation * vic);
	void chooseLogicalDevice();

private:
	VulkanInstanceCreation* vic;

	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VDeleter<VkDevice> device{ vkDestroyDevice };
	VDeleter<VkSurfaceKHR> surface{};
	VkQueue graphicsQueue;
	VkQueue presentQueue;
	VDeleter<VkSwapchainKHR> swapChain{ device, vkDestroySwapchainKHR };
	vector<VkImage> swapChainImages;
	vector<VDeleter<VkImageView>> swapChainImageViews;
	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent;

	std::vector<VDeleter<VkFramebuffer>> swapChainFramebuffers;
	VDeleter<VkRenderPass> renderPass{};
	std::vector<VkCommandBuffer> commandBuffers;
	VDeleter<VkCommandPool> commandPool{};
	int rateDeviceSuitability(VkPhysicalDevice device);
	bool isDeviceSupported(VkPhysicalDevice device);
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
	bool checkDeviceExtensionSupport(VkPhysicalDevice device);

	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR chooseSwapPresentMode(const vector<VkPresentModeKHR> availablePresentModes);
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	void createSwapChain();
	std::vector<char> readFile(const std::string& filename);

	VkSubpassDescription subPass = {};
	VkAttachmentReference colorAttachmentRef = {};
	VkAttachmentDescription colorAttachment = {};

	VDeleter<VkPipelineLayout> pipelineLayout{ device, vkDestroyPipelineLayout };
	VDeleter<VkPipeline> graphicsPipeline{ device, vkDestroyPipeline };
};

