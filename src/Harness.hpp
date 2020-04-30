#pragma once

#include "Config.hpp"

class GLFWwindow;

namespace Phrame{

class Plate;

class Harness{
	protected:
	Promien::Config settings;
	Plate* cuirass;
	public:	
	virtual int assemble(const char* cfg, const char* manifest , Plate* plate);
	virtual ~Harness();
};
}
