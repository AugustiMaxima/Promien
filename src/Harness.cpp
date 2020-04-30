#include <GLFW/glfw3.h>
#include "Config.hpp"
#include "Plate.hpp"
#include "Harness.hpp"

#include <iostream>
using namespace std;

namespace Phrame{

int Harness::assemble(const char* cfg, const char* manifest, Plate* plate){
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

	plate->panoply(&settings, window);	

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

Harness::~Harness(){}

}
