#version 330 core
out vec4 pixelColor;

uniform vec4 tintColor;
in vec2 texCoord;
in vec4 vertexColour;
uniform sampler2D diffuseTexture;
uniform sampler2D blendTexture;


void main()
{
//	pixelColor = texture(diffuseTexture, texCoord) * texture(blendTexture, texCoord);
	pixelColor = texture(diffuseTexture, texCoord);

}