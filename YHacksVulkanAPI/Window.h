#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

class Window
{
public:
	GLFWwindow* m_window;
	uint32_t extensionCount;

	Window(int m_width, int m_height, char* name);
	~Window();
	void updateMainLoop();

private:
	int m_width;
	int m_height;
	char* m_title;
	bool canInitWindowComponents();

};

