#version 330

struct Texel{
	vec3 position;
	vec3 tCoord;
	vec3 normal;
};

struct LightSource{
	vec3 position;
	vec3 colour;
	float spread;
};

uniform LightSource lightSources[24];

in Texel texel;

out vec4 fragColour;

void main(){
	fragColour = vec4(0.5);
}
