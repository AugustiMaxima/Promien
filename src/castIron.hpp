#pragma once

#include "Plate.hpp"
#include "Program.hpp"

class castIron: public Phrame::Plate{
	Core::Program program;
	public:
	virtual void panoply(Promien::Config* settings, GLFWwindow* window);
	virtual void draw();
	virtual void eventProcessing();
	virtual void eventCycle();
	virtual ~castIron();
};
