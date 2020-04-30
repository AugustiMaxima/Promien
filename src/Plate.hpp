#pragma once

//the event handler to be dropped in to the event loop
//handles logic like rendering, event handling, physics simulation and so on

class GLFWwindow;

namespace Promien{
class Config;
}

namespace Phrame{
class Plate{
	protected:
	Promien::Config* settings;
	GLFWwindow* window;
	
	public:
	//initialization
	virtual void panoply(Promien::Config* settings, GLFWwindow* window);

	//for maximum flexiblilty, the window object is passed on
	virtual void draw();
	virtual void eventProcessing();
	virtual void eventCycle();

	virtual ~Plate();
};
}
