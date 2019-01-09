#version 460 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexPos;

out vec2 TexPos;

void main() 
{
	gl_Position = vec4(aPos, 1.0);
    TexPos = aTexPos;
}