#version 460 core
in vec2 TexPos;
out vec4 color;

uniform sampler2D tex;

void main()
{
	color =  texture(tex, TexPos);
}