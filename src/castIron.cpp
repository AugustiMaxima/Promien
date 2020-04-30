#include <GL/gl.h>
#include "Shader.hpp"
#include <iostream>
#include "castIron.hpp"

void castIron::panoply(Promien::Config* settings, GLFWwindow* window){
	using namespace Phrame;
	Plate::panoply(settings, window);
	
	using namespace std;
	cout<<"Beginning construction"<<endl;


	using namespace Core;
	//time for initialization stuff
	Shader vertex(GL_VERTEX_SHADER, "shaders/test.vs");
	Shader fragment(GL_FRAGMENT_SHADER, "shader/test.fs");
	
	std::string vlog = vertex.compileShader();
	std::string flog = fragment.compileShader();

	cout<<"Vertex shader"<<endl;
	cout<<vlog<<endl;
	cout<<"Fragment shader"<<endl;
	cout<<flog<<endl;

	program.initialize();

	program.attachShader(vertex);
	program.attachShader(fragment);

	bool signal = program.linkProgram();

	if(signal)
		cout<<"We failed"<<endl;

}

void castIron::draw(){

}

void castIron::eventProcessing(){


}

void castIron::eventCycle(){


}

castIron::~castIron(){}
