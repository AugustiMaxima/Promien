#pragma once

#include <GL/gl.h>
#include <vector>

namespace Core{

class Shader;

//Note: Do not use copy and assignment operations
class Program{
	GLuint id;
	std::vector<GLuint> shaders;
	Program();
	Program(const std::vector<Shader>& shaders);
	void attachShader(const Shader& shader);
	bool linkProgram();
	~Program();
};

}
