
#include "config.hpp"
#include "harness.hpp"
#include <GLFW/glfw3.h>
#include "plate.hpp"

namespace phrame{

Plate::Plate(Harness& harness):harness(harness){}

int Plate::assemble(const char* cfg, const char* manifest){
	Promien::Config settings;
	settings.parseSettings(cfg, manifest);

	int xres = settings.getSetting("xres");
	int yres = settings.getSetting("yres");

	const char* appName = settings.getConfig("AppName").c_str();

	GLFWwindow* window;

	if(!glfwInit())
		return -1;

	window = glfwCreateWindow(xres, yres, appName, NULL, NULL);

	if(!window){
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);


	while(!glfwWindowShouldClose(window)){
		//game logic and simulation


		//render


		//present
		glfwSwapBuffers(window);


		glfwPollEvents();
		//event loop
				
	}

	glfwTerminate();
	return 0;



}

}
