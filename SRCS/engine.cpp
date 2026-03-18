#include "engine.hpp"

Engine::Engine() {
	if (debugMode) {
		std::cout << "Making a graphics engine" << std::endl;
	}

	build_glfw_window();
}

void Engine::build_glfw_window() {
	std::string title = "RT";

	//initialize glfw
	glfwInit();

	//no default rendering client, we'll hook vulkan up
	//to the window later
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	//resizeing breaks the swapchain, we'll disable it for now
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	//GLFWwindow* glfwCreateWindow (int width, int height, const chr *title, GLFWmonitor, GLFWwindow *share)
	if ((window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr))) {
		if (debugMode) {
			std::cout << "Successfully made glfw window called \"" << title << "\", width :" << width << ", height : " << height << std::endl;
		}
	} else {
		if (debugMode) {
			std::cout << "GLFW window creation failed" << std::endl;
		}
	}
}

Engine::~Engine() {
	if (debugMode) {
		std::cout << "End Of Engine" << std::endl;

		glfwTerminate ();
	}
}