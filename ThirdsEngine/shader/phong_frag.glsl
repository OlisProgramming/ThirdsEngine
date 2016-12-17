#version 330 core

// Interpolated values from the vertex shaders
in vec2 UV;

// Ouput data
out vec3 colorOut;

// Values that stay constant for the whole mesh.
uniform sampler2D myTextureSampler;

in vec3 lightAmbient2;

void main() {

	vec3 texColor = texture(myTextureSampler, UV).rgb;

	// Compute lighting for this fragment.
	vec3 totalLight = lightAmbient2;//vec3(1-lightAmbient.x, 1-lightAmbient.y, 1-lightAmbient.z);

	colorOut = totalLight;
}