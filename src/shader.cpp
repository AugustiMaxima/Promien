#include <fstream>
#include "shader.hpp"

namespace core{

Shader::Shader(GLenum shaderType, const std::vector<std::string>& files):shaderType(shaderType), files(files){
	id = glCreateShader(shaderType);
}

Shader::Shader(GLenum shaderType, const std::vector<std::string>&& files): shaderType(shaderType), files(std::move(files)){
	id = glCreateShader(shaderType);
}

void attachShader(const std::string& filename){
	files.push_back(filename);
}

GLuint getShaderId() const {
	return id;
}

std::string compileShader(){
	GLsizei count = files.length();
	GLchar** strings = new GLchar*[count];
	GLint* lengths = new GLint[count];

	std::vector<std::string> rawShaders;

	//loading and collecting all the arguments
	for(int i=0; i<count; i++){
		std::ifstream shade(files[i]);
		std::stringstream rawShadeBuf;
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
	glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logSize);

	if(logSize){
		GLchar* rawMsg = new GLchar[logSize];
		glGetShaderInfoLog(id, logSize, &logSize, rawMsg);
		return String(rawMsg);
	}
	return "";
}

Shader::~Shader(){
	glDeleteShader(id);
}

}
