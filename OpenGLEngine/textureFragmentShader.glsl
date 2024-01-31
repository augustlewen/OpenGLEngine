#version 330 core
out vec4 pixelColor;

uniform vec4 tintColor;
in vec2 texCoord;

uniform sampler2D diffuseTexture;


void main()
{
	pixelColor = texture(diffuseTexture, texCoord);
}