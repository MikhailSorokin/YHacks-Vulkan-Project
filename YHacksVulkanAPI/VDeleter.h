#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>
#include <functional>
#include <vector>

using namespace std;

#pragma once

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
