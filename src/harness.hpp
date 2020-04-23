#pragma once

//the event handler to be dropped in to the event loop
//handles logic like rendering, event handling, physics simulation and so on

class GLFWwindow;

namespace phrame{
class Harness{
	GLFWwindow* window;
	public:
	
	void setWindow(GLFWwindow* window);

	//for maximum flexiblilty, the window object is passed on
	virtual void draw();
	virtual void eventProcessing();
	virtual void eventCycle();

	virtual ~Harness();
};
}
