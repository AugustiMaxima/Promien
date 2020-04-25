#include "program.hpp"

namespace core{
	Program::Program(){
		id = glCreateProgram();
	}

	Program::Program(const std::vector<Shader>& shaders){
		id = glCreateProgram();
		for(auto& shader : shaders){
			attachShader(shader);
		}
	}

	void Program::attachShader(const Shader& shader){
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
