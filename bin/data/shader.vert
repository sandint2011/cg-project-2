#version 410

layout (location = 0) in vec3 position;
layout (location = 2) in vec3 normal;

uniform vec3 cameraPosition;

uniform float startFade;
uniform float endFade;

uniform mat4 mv;
uniform mat4 mvp;

out vec3 fragNormal;
out float distanceFromCamera;

void main()
{
	gl_Position = mvp * vec4(position, 1.0);
	fragNormal = normal;

	distanceFromCamera = abs(length((mv * vec4(position, 1.0)).xyz - cameraPosition));
	//distanceFromCamera = clamp(startFade, endFade, distanceFromCamera);
	//distanceFromCamera = 1.0f;
	//distanceFromCamera = distanceFromCamera / endFade + startFade;
	distanceFromCamera = (distanceFromCamera - startFade) / (endFade - startFade);
}