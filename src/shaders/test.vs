#version 330

in vec3 position;
in vec3 tCoord;
in vec3 normal;

struct Texel{
	vec3 position;
	vec3 tCoord;
	vec3 normal;
};

out Texel texel;

void main(){
	texel.position = position;
	texel.tCoord = tCoord;
	texel.normal = normal;
	gl_Position = vec4(position, 1.0);
}
