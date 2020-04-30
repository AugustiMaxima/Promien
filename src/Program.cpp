#include <GL/glew.h>
#include "Shader.hpp"
#include "Program.hpp"

namespace Core{
	Program::Program(){
		id = -1;
	}

	Program::Program(const std::vector<Shader>& shaders){
		id = glCreateProgram();
		for(auto& shader : shaders){
			attachShader(shader);
		}
	}

	void Program::initialize(){
		id = glCreateProgram();
	}

	void Program::attachShader(const Shader& shader){
		if(id == -1)
			initialize();
		GLuint sid = shader.getShaderId();
		glAttachShader(id, sid); 
		shaders.push_back(sid);
	}

	bool Program::linkProgram(){
		glLinkProgram(id);
		GLint result;
		glGetProgramiv(id, GL_LINK_STATUS, &result);
		for(auto& shader: shaders){
			glDetachShader(id, shader);
		}
		return result == GL_FALSE;
	}

	Program::~Program(){
		glDeleteProgram(id);
	}
}
