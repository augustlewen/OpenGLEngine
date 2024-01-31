#version 330 core
out vec4 FragColor;
uniform vec4 tintColor;
in vec4 vertexColour;
  
void main()
{
	FragColor = vertexColour;
}