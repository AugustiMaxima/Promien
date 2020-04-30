#include <GLFW/glfw3.h>
#include "Plate.hpp"

namespace Promien{
class Config;
}

namespace Phrame{

	void Plate::panoply(Promien::Config* settings, GLFWwindow* window){
		this->settings = settings;
		this->window = window;
	}

	void Plate::draw(){
		;
	}

	void Plate::eventProcessing(){
		;
	}

	void Plate::eventCycle(){
		;
	}

	Plate::~Plate(){}

}
