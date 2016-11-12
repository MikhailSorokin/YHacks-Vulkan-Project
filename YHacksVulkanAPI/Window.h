#pragma once
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

class Window
{
public:
	int m_width;
	int m_height;
	char* m_title;
	uint32_t extensionCount;

	Window(int m_width, int m_height, char* name);
	~Window();
	void updateMainLoop();

private:
	bool canInitWindowComponents();
	GLFWwindow* m_window;

};

