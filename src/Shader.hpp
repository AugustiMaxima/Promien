#pragma once

#include <GL/gl.h>
#include <vector>

namespace Core{
struct Shader{
	std::vector<std::string> files;
	GLuint id;
	GLenum shaderType;
	Shader(GLenum shaderType, const std::vector<std::string>& files);
	Shader(GLenum shaderType, const std::vecotr<std::string>&& files);
	void attachShader(const std::string& filename);
	GLuint getShaderId() const;
	std::string compileShader();
	~Shader();
};
}
