#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>
#include <functional>
#include <stdexcept> //handle exceptions
#include <cstring>
#include "VDeleter.h"

#pragma once

class VulkanInstanceCreation
{
public:
	VulkanInstanceCreation();
	~VulkanInstanceCreation();
	void setupDebugCallback();
	VDeleter<VkInstance> instance{ vkDestroyInstance };
private:
	void createInstance();
	bool hasLayerValidationSupport();

	std::vector<const char *> getRequiredExtensions();
};

