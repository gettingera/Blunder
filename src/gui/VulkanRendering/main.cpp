#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

//global constant window dimensions
const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class HelloTriangleApplication {
public:
	void run() {
		initWindow();
		initVulkan();
		mainLoop();
		cleanup();
	}

private:
	//reference to "window" called in "initWindow()" function
	GLFWwindow* window;

	//initialize glfw which is used to create windows
	void initWindow() {
		//initializes glfw library
		glfwInit();

		//tells glfw to not look for OpenGL context since we are using Vulkan not OpenGL
		//disables resizeble windows
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		//creates glfw window with const values "WIDTH" and "HEIGHT"
		window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
	}
	//initates vulkan, vulkan objects will be stored here as private class members and will have functions that call them
	void initVulkan() {

	}

	//begins to render frames after the "initVulkan()" function's initialization 
	void mainLoop() {
		//keeps appplication running until error occurs or window is closed
		while (!glfwWindowShouldClose(window)) {
			glfwPollEvents();
		}
	}

	//deallocates resources once the window is closed
	void cleanup() {
		glfwDestroyWindow(window);

		glfwTerminate();
	}
};


int main() {
	HelloTriangleApplication app;

	try {
		app.run();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}