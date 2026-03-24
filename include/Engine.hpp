#pragma once

#include "deps.h"

class	Engine {

	public:
		Engine();

		~Engine();

	private:
		//whether to print debug messages in functions
		bool debugMode = true;

		std::string	applicationName = "RT";

		//glfw window parameters
		int width{ 640 };
		int height{ 480 };
		GLFWwindow* window{ nullptr };

		//vulkan instance
		vk::Instance instance{ nullptr };

		//glfw setup
		void buildGlfwWindow();
		void run();
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

		//instance setup
		void initVkInstance();
};