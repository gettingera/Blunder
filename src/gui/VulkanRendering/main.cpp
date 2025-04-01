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

	VkInstance instance;

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
		createInstance();

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
		vkDestroyInstance(instance, nullptr);

		glfwDestroyWindow(window);

		glfwTerminate();
	}

	//instance is connection between our application and the vulkan library
	void createInstance() {
		//information for driver to optimize our application
		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "Hello Triangle";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "No Engine";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;

		//tells Vulkan driver which global extensions and validation layers to use
		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;

		//glfw function returns required extensions to interface with the window system
		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions;
		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		//determine which global validation layers to enable
		createInfo.enabledExtensionCount = glfwExtensionCount;
		createInfo.ppEnabledExtensionNames = glfwExtensions;
		createInfo.enabledLayerCount = 0;

		//checks if instance was created successfully, if not created successfully throws error
		if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
			throw::std::runtime_error("failed to create instance");
		}
	}
};

//runs app
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