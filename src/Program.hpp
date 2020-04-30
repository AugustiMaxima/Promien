#pragma once

#include <GL/gl.h>
#include <vector>

namespace Core{

struct Shader;
//Note: Do not use copy and assignment operations
struct Program{
	GLuint id;
	std::vector<GLuint> shaders;
	Program();
	Program(const std::vector<Shader>& shaders);
	void initialize();
	void attachShader(const Shader& shader);
	bool linkProgram();
	~Program();
};

}
