#include "VulkanDriver.h"
#include "Window.h"

const std::vector<const char*> validationLayers = {
	"VK_LAYER_LUNARG_standard_validation"
};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif

///Used to clean up resources used throughout VulkanDriver class
template <typename T>
class VDeleter {
public:
	VDeleter() : VDeleter([](T, VkAllocationCallbacks*) {}) {}

	VDeleter(function<void(T, VkAllocationCallbacks*)> deletef) {
		this->deleter = [=](T obj) { deletef(obj, nullptr); };
	}

	VDeleter(const VDeleter<VkInstance>& instance, function<void(VkInstance, T, VkAllocationCallbacks*)> deletef) {
		this->deleter = [&instance, deletef](T obj) { deletef(instance, obj, nullptr); };
	}

	VDeleter(const VDeleter<VkDevice>& device, function<void(VkDevice, T, VkAllocationCallbacks*)> deletef) {
		this->deleter = [&device, deletef](T obj) { deletef(device, obj, nullptr); };
	}

	~VDeleter() {
		cleanup();
	}

	const T* operator &() const {
		return &object;
	}

	T* replace() {
		cleanup();
		return &object;
	}

	operator T() const {
		return object;
	}

	void operator=(T rhs) {
		if (rhs != object) {
			cleanup();
			object = rhs;
		}
	}

	template<typename V>
	bool operator==(V rhs) {
		return object == T(rhs);
	}

private:
	T object{ VK_NULL_HANDLE };
	function<void(T)> deleter;

	void cleanup() {
		if (object != VK_NULL_HANDLE) {
			deleter(object);
		}
		object = VK_NULL_HANDLE;
	}
};

class OurApplication {
public:
	void run() {
		initVulkan();
		createAndRunWindow();
	}

private:

	VDeleter<VkInstance> instance{ vkDestroyInstance };

	void createAndRunWindow() {
		Window window(800, 600, "YHacks Yoo");
		window.updateMainLoop();
	}

	void initVulkan() {
		if (enableValidationLayers && ifLayerValidationSupport()) {
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

		//How many extensions can we get from GLFW to communicate with Vulkan?
		unsigned int glfwExtensionCount = 0;
		const char** glfwExtensions;

		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		createInfo.enabledExtensionCount = glfwExtensionCount;
		createInfo.ppEnabledExtensionNames = glfwExtensions;
		createInfo.enabledLayerCount = 0;

		//Can finally create instance
		VkResult result = vkCreateInstance(&createInfo, nullptr, instance.replace());
		if (result != VK_SUCCESS) {
			//This will make it crash on non-vulkan supported computers!
			throw runtime_error("Failed to create a Vulkan instance!");
		}

		//Used to see how many extensions we have
		uint32_t extensionCount = 0;

		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
		vector<VkExtensionProperties> extensions(extensionCount);
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());


		for (const auto& extension : extensions) {
			cout << "This is a reccomended extension name: " << extension.extensionName << endl;
		}
	}

	bool ifLayerValidationSupport() {
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
};


int main() {

	OurApplication ap;

	try {
		ap.run();
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}