#pragma once

//the event handler to be dropped in to the event loop
//handles logic like rendering, event handling, physics simulation and so on

class GLFWwindow;

namespace Phrame{
class Harness{
	protected:
	GLFWwindow* window;
	
	public:
	//initialization
	void setWindow(GLFWwindow* window);

	//for maximum flexiblilty, the window object is passed on
	virtual void draw();
	virtual void eventProcessing();
	virtual void eventCycle();

	virtual ~Harness();
};
}
