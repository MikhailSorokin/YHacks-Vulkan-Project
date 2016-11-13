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

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == 256) {
		exit(0);
	}
	else {
		std::cout << "PRESSING: " << key << std::endl;
	}
}

/*void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_E && action == GLFW_PRESS)
		activate_airship();
}*/


void Window::updateMainLoop() {
	while (!glfwWindowShouldClose(m_window)) {
		glfwPollEvents();
		
		int state = glfwGetKey(m_window, GLFW_KEY_E);
		//cout << state << " pressed.\n";
		if (state == GLFW_PRESS) {
			cout << state << " pressed.\n";
		}
		glfwSetKeyCallback(m_window, key_callback);

		//glfwSetInputMode(m_window, GLFW_STICKY_KEYS, 1);
		//double xpos, ypos;
		//glfwGetCursorPos(m_window, &xpos, &ypos);
		//cout << "Position: " << xpos << ypos;
	}
}