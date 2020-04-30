#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <sstream>
#include "Shader.hpp"

namespace Core{

Shader::Shader(GLenum shaderType):shaderType(shaderType){
	id = glCreateShader(shaderType);
}

Shader::Shader(GLenum shaderType, const std::string& file):shaderType(shaderType){
	id = glCreateShader(shaderType);
	files.push_back(file);
}

Shader::Shader(GLenum shaderType, const std::vector<std::string>& files):shaderType(shaderType), files(files){
	id = glCreateShader(shaderType);
}

Shader::Shader(GLenum shaderType, const std::vector<std::string>&& files): shaderType(shaderType), files(std::move(files)){
	id = glCreateShader(shaderType);
}

void Shader::attachShader(const std::string& filename){
	files.push_back(filename);
}

GLuint Shader::getShaderId() const {
	return id;
}

std::string Shader::compileShader(){
	GLsizei count = files.size();
	const GLchar** strings = new const GLchar*[count];
	GLint* lengths = new GLint[count];

	std::vector<std::string> rawShaders;

	//loading and collecting all the arguments
	for(int i=0; i<count; i++){
		std::ifstream shade(files[i]);
		std::ostringstream rawShadeBuf;
		rawShadeBuf << shade.rdbuf();
		rawShaders[i] = rawShadeBuf.str();
		strings[i] = rawShaders[i].c_str();
		lengths[i] = rawShaders[i].length();
	}

	glShaderSource(id, count, strings, lengths);

	delete []strings;
	delete []lengths;

	glCompileShader(id);

	//error collecting
	GLint logSize = 0;
	glGetShaderiv(id, GL_INFO_LOG_LENGTH, &logSize);

	if(logSize){
		GLchar* rawMsg = new GLchar[logSize];
		glGetShaderInfoLog(id, logSize, &logSize, rawMsg);
		return std::string(rawMsg);
	}
	return "";
}

Shader::~Shader(){
	glDeleteShader(id);
}

}
