#pragma once

class GLFWwindow;

namespace Phrame{

class Harness;

class Plate{
	Harness& harness;
	public:	
	Plate(Harness& harness);
	int assemble(const char* cfg, const char* manifest);
};
}
