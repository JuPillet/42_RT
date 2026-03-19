#include <iostream>
#include <GLFW/glfw3.h>

class Engine {

	public:
		Engine();

		~Engine();

	private:
		//whether to print debug messages in functions
		bool debugMode = true;

		//glfw window parameters
		int width{ 640 };
		int height{ 480 };
		GLFWwindow* window{ nullptr };

		//glfw setup
		void buildGlfwWindow();
		void run();
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};