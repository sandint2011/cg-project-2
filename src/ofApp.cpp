#include "ofApp.h"
#include <vector>

// .PLY foramt
// -Z forward
// Y up
// ASCII format
// Triangulated

//--------------------------------------------------------------
void ofApp::setup()
{
	ofDisableArbTex();
	ofEnableDepthTest();

	legoMesh.load("lego-old-blender.ply");
	swordMesh.load("sordFinal.ply");

	assert(legoMesh.getNumVertices() > 0);
	assert(swordMesh.getNumVertices() > 0);

	reloadShaders();
}

//--------------------------------------------------------------
void ofApp::reloadShaders()
{
	if (needsShaderReload)
	{
		// Reload all shaders here.
		shader.load("shader.vert", "shader.frag");

		needsShaderReload = false;
	}
}

//--------------------------------------------------------------
void ofApp::update()
{
	reloadShaders();
}

//--------------------------------------------------------------
void ofApp::draw()
{
	float aspectRatio { static_cast<float>(ofGetViewportWidth()) / static_cast<float>(ofGetViewportHeight()) };
	
	// Movel-view-projection.
	glm::mat4 model; // Set for each mesh individually.
	glm::mat4 view = glm::lookAt(cameraPosition, cameraPosition + cameraFront, cameraUp);;
	glm::mat4 projection = glm::perspective(glm::radians(90.0f), aspectRatio, 0.1f, 10.0f);

	shader.begin();
	shader.setUniform3f("cameraPosition", cameraPosition);

	// Lego.
	model = (
		glm::translate(glm::vec3(0, 0, -5))
		* glm::rotate(glm::radians(45.0f), glm::vec3(1, 1, 1))
		* glm::scale(glm::vec3(0.1, 0.1, 0.1))
	);
	shader.setUniformMatrix4f("mvp", projection * view * model);
	legoMesh.draw();

	// Sword.
	model = (
		glm::translate(glm::vec3(3, -2, -5))
		* glm::rotate(glm::radians(45.0f), glm::vec3(1, 1, 1))
		* glm::scale(glm::vec3(.5,.5, .5))
	);
	shader.setUniformMatrix4f("mvp", projection * view * model);
	swordMesh.draw();

	shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == '`')
	{
		needsShaderReload = true;
	}

	const float cameraSpeed = 10;
	const float dt = ofGetLastFrameTime();

	// Forward / backward.
	if (key == 'w')
	{
		cameraPosition += cameraFront * cameraSpeed * dt;
	}
	if (key == 's')
	{
		cameraPosition -= cameraFront * cameraSpeed * dt;
	}

	// Left / right.
	if (key == 'a')
	{
		cameraPosition -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed * dt;
	}
	if (key == 'd')
	{
		cameraPosition += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed * dt;
	}

	// Up / down.
	if (key == 'q')
	{
		cameraPosition -= glm::normalize(glm::cross(cameraUp, cameraFront)) * cameraSpeed * dt;
	}
	if (key == 'e')
	{
		cameraPosition += glm::normalize(glm::cross(cameraUp, cameraFront)) * cameraSpeed * dt;
	}

	// Pitch up / down.
	if (key == 'W')
	{
		
	}
	else if (key == 'S')
	{

	}

	// Head left / right.
	if (key == 'A')
	{
		
	}
	else if (key == 'D')
	{

	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{ 

}

//--------------------------------------------------------------
void ofApp::buildMesh(ofMesh& mesh, glm::vec3 pos, float width, float height)
{
	float verts[12]
	{
		pos.x - width, pos.y - height, pos.z,
		pos.x - width, pos.y + height, pos.z,
		pos.x + width, pos.y + height, pos.z,
		pos.x + width, pos.y - height, pos.z
	};

	float uvs[8]
	{
		0, 0,
		0, 1,
		1, 1,
		1, 0
	};

	for (unsigned int i = 0; i < 4; i++)
	{
		int vertIndex = i * 3;
		int uvIndex = i * 2;

		mesh.addVertex(glm::vec3(verts[vertIndex], verts[vertIndex + 1], verts[vertIndex + 2]));
		mesh.addTexCoord(glm::vec2(uvs[uvIndex], uvs[uvIndex + 1]));
	}

	ofIndexType indices[6] = { 0, 1, 2, 2, 3, 0 };
	mesh.addIndices(indices, 6);
}