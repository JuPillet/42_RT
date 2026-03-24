#include "Engine.hpp"

Engine::Engine() {
	if (debugMode) {
		std::cout << "Making a graphics engine" << std::endl;
	}

	buildGlfwWindow();

	createVkInstanciation();
	run();
}

void Engine::buildGlfwWindow() {
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
			std::cout << "Successfully made glfw window called \"" << applicationName << "\", width :" << width << ", height : " << height << std::endl;
		}
		glfwSetKeyCallback(window, Engine::keyCallback);
	} else {
		throw std::runtime_error ("GLFW window creation failed");
	}
}

void Engine::run() {
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}
}

void Engine::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
	(void)scancode; (void)mods; //Evite les warnings

	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		std::cout << "Escape pressed" << std::endl;
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

void initVkInstance(bool debug, const char* applicationName) {
	instance = vkInit::createVkInstanciation(debugMode, applicationName.c_str);
	return nullptr
}

Engine::~Engine() {
	if (debugMode) std::cout << "End Of Engine" << std::endl;
	if (window) {
		std::cout << "Window destroyed" << std::endl;
		glfwDestroyWindow(window);
		window = nullptr;
	}
	glfwTerminate();
	std::cout << "RT Exited" << std::endl;
}