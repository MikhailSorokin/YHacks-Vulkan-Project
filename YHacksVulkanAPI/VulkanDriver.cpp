#include "VulkanDriver.h"

void VulkanDriver::run() {
	Window windowWithVulkan = initVulkan();
	chooseDevice(windowWithVulkan);
	runProgramOnWindow(windowWithVulkan);
}

Window VulkanDriver::initVulkan() {
	VulkanInstanceCreation* vic = new VulkanInstanceCreation();
	vic->setupDebugCallback();
	Window window(800, 600, "YHacks Yoo");
	return window;
}

void VulkanDriver::chooseDevice(Window window) {
	VulkanDevicePicker* vdp = new VulkanDevicePicker(); //calls createInstance automatically
	vdp->createSurface(window.m_window);
	vdp->createImageViews();
}

void VulkanDriver::runProgramOnWindow(Window window) {
	window.updateMainLoop();
}


int main() {
	VulkanDriver vd;

	try {
		vd.run();
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}