#version 330 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 1) in vec4 aCol; // the color variable has attribute position 1
layout (location = 2) in vec2 aTexCoord;

  
out vec4 vertexColour; // output a color to the fragment shader
out vec2 texCoord;

uniform mat4 transform;

void main()
{
    gl_Position = transform * vec4(aPos.xyz, 1);
    texCoord = aTexCoord;

} 