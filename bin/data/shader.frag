#version 410

in vec3 fragNormal;

uniform float nearClip;
uniform float farClip;

out vec4 outColor;

void main()
{
	outColor = vec4(fragNormal * 0.5 + 0.5, 1.0);
}