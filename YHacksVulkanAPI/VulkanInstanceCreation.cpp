#include "VulkanInstanceCreation.h"
using namespace std;

const vector<const char*> validationLayers = {
	"VK_LAYER_LUNARG_standard_validation"
};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

VulkanInstanceCreation::VulkanInstanceCreation()
{
	createInstance();
}

VulkanInstanceCreation::~VulkanInstanceCreation()
{
	//vkDestroyInstance(instance, nullptr);
}

void DestroyDebugReportCallbackEXT(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* pAllocator) {
	auto func = (PFN_vkDestroyDebugReportCallbackEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugReportCallbackEXT");
	if (func != nullptr) {
		func(instance, callback, pAllocator);
	}
}


VkResult CreateDebugReportCallbackEXT(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugReportCallbackEXT* pCallback) {
	auto func = (PFN_vkCreateDebugReportCallbackEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugReportCallbackEXT");
	if (func != nullptr) {
		return func(instance, pCreateInfo, pAllocator, pCallback);
	}
	else {
		return VK_ERROR_EXTENSION_NOT_PRESENT;
	}
}


void VulkanInstanceCreation::createInstance() {
	if (enableValidationLayers && hasLayerValidationSupport()) {
		throw runtime_error("validation layers requested, but not available!");
	}

	//May optimize our specific application
	VkApplicationInfo appInfo = {};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Triangle Plox Load";
	appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.pEngineName = "No Engine";
	appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	//Not optional. Used to tell driver which global extensions and validation layers to use.
	VkInstanceCreateInfo createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;
	if (enableValidationLayers) {
		createInfo.enabledLayerCount = validationLayers.size();
		createInfo.ppEnabledLayerNames = validationLayers.data();
	}
	else {
		createInfo.enabledLayerCount = 0;
	}

	vector<const char *> extensions = getRequiredExtensions();
	createInfo.enabledExtensionCount = extensions.size();
	createInfo.ppEnabledExtensionNames = extensions.data();

	//Can finally create instance
	VkResult result = vkCreateInstance(&createInfo, nullptr, instance.replace());
	if (result != VK_SUCCESS) {
		//This will make it crash on non-vulkan supported computers!
		throw runtime_error("Failed to create a Vulkan instance!");
	}
}

bool VulkanInstanceCreation::hasLayerValidationSupport() {
	uint32_t layerCount;
	vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

	vector<VkLayerProperties> availableLayerProperties;
	vkEnumerateInstanceLayerProperties(&layerCount, availableLayerProperties.data());

	for (const char* layerName : validationLayers) {
		bool layerFound = false;

		for (const auto& layerProperties : availableLayerProperties) {
			if (strcmp(layerName, layerProperties.layerName) == 0) {
				layerFound = true;
				break;
			}
		}

		if (!layerFound) {
			return false;
		}
	}

	return true;
}

vector<const char *> VulkanInstanceCreation::getRequiredExtensions() {
	vector<const char *> allValidExtensions;

	//How many extensions can we get from GLFW to communicate with Vulkan?
	unsigned int glfwExtensionCount = 0;
	const char** glfwExtensions;
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
	
	for (unsigned int i = 0; i < glfwExtensionCount; i++)
	{
		allValidExtensions.push_back(glfwExtensions[i]);
	}

	//To receive messages we have to set up a callback, which requires the VK_EXT_debug_report extension.
	if (enableValidationLayers) {
		allValidExtensions.push_back(VK_EXT_DEBUG_REPORT_EXTENSION_NAME);
	}

	return allValidExtensions;

}

//CallBack
static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugReportFlagsEXT flags, VkDebugReportObjectTypeEXT objType, uint64_t obj, size_t location, int32_t code, const char* layerPrefix, const char* msg, void* userData) {
	std::cerr << "validation layer: " << msg << std::endl;

	return VK_FALSE;
}

void VulkanInstanceCreation::setupDebugCallback() {
	VDeleter<VkDebugReportCallbackEXT> callback{ instance, DestroyDebugReportCallbackEXT };
	//A callback for setting up the layer properties.
	if (!enableValidationLayers) return;

	VkDebugReportCallbackCreateInfoEXT createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
	createInfo.flags = VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT;
	createInfo.pfnCallback = debugCallback;

	if (CreateDebugReportCallbackEXT(instance, &createInfo, nullptr, callback.replace()) != VK_SUCCESS) {
		throw runtime_error("failed to set up debug callback!");
	}
}