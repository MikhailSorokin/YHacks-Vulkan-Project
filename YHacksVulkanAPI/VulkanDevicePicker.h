#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <map>
#include <set>
#include <algorithm>
#include "VDeleter.h"
#pragma once

class VulkanDevicePicker
{
public:
	VulkanDevicePicker();
	~VulkanDevicePicker();
	void createSurface(GLFWwindow* window);
	void createImageViews();

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

private:
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	VDeleter<VkInstance> instance{ vkDestroyInstance };
	VDeleter<VkDevice> device{ vkDestroyDevice };
	VDeleter<VkSurfaceKHR> surface{ instance,vkDestroySurfaceKHR };
	VkQueue graphicsQueue;
	VkQueue presentQueue;
	VDeleter<VkSwapchainKHR> swapChain{ device, vkDestroySwapchainKHR };
	vector<VkImage> swapChainImages;
	vector<VDeleter<VkImageView>> swapChainImageViews;
	VkFormat swapChainImageFormat;
	VkExtent2D swapChainExtent;

	void pickPhysicalDevice();
	void chooseLogicalDevice();
	int rateDeviceSuitability(VkPhysicalDevice device);
	bool isDeviceSupported(VkPhysicalDevice device);
	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
	bool checkDeviceExtensionSupport(VkPhysicalDevice device);

	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const vector<VkSurfaceFormatKHR>& availableFormats);
	VkPresentModeKHR chooseSwapPresentMode(const vector<VkPresentModeKHR> availablePresentModes);
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	void createSwapChain();
};

