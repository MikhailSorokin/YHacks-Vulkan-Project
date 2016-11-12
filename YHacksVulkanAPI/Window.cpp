#include "Window.h"

Window::Window(int m_width, int m_height, char* m_name)
{
	this->m_width = m_width;
	this->m_height = m_height;
	this->m_title = m_name;

	if (!canInitWindowComponents()) {
		glfwTerminate();
	}
}


Window::~Window()
{
	glfwTerminate();
}

bool Window::canInitWindowComponents() {
	if (!glfwInit()) {
		cout << "Fuck outta here with your non-GLFW looking ass." << endl;
		return false;
	}

	m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	return true;
}

void Window::updateMainLoop() {
	while (!glfwWindowShouldClose(m_window)) {
		glfwPollEvents();
	}
}