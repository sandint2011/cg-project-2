#version 410

in vec3 fragNormal;

in float distanceFromCamera;

out vec4 outColor;

void main()
{
	outColor = vec4(fragNormal * 0.5 + 0.5, 1.0);
	outColor.a = smoothstep(0.0, 1.0, 1.0 - distanceFromCamera);
}