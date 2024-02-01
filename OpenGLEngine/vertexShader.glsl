#version 330 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 1) in vec4 aCol; // the color variable has attribute position 1
layout (location = 2) in vec2 aTexCoord;

uniform vec2 offset;
  
out vec4 vertexColour; // output a color to the fragment shader
out vec2 texCoord;



void main()
{
    gl_Position = vec4(aPos.x + offset.x, aPos.y + offset.y, aPos.z, 1.0);
    vertexColour = aCol; // set ourColor to the input color we got from the vertex data
    texCoord = vec2(aPos.x + offset.x, aPos.y + offset.y);
//    texCoord = aTexCoord;

} 