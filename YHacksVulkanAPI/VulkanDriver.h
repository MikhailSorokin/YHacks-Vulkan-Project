#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include "Window.h"
#include "VulkanInstanceCreation.h"
#include "VulkanDevicePicker.h"

#pragma once
class VulkanDriver
{
public:
	void run();
private:
	Window initVulkan();
	void chooseDevice(Window window);
	void runProgramOnWindow(Window window);
};

