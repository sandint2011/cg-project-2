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

	mesh.load("sword3.ply");
	assert(mesh.getNumVertices() > 0);

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
	
	shader.begin();
	shader.setUniformMatrix4f(
		"transform", 
		glm::perspective(glm::radians(90.0f), aspectRatio, 0.1f, 10.0f)
		* glm::translate(glm::vec3(0, 0, -5))
		* glm::rotate(glm::radians(45.0f), glm::vec3(1, 1, 1))
		* glm::scale(glm::vec3(1, 1, 1))
	);
	mesh.draw();
	shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == '`')
	{
		needsShaderReload = true;
	}

	// W A S D
	if (key == 'w')
	{

	}
	else if (key == 'W')
	{

	}
	if (key == 'a')
	{

	}
	else if (key == 'A')
	{

	}
	if (key == 's')
	{

	}
	else if (key == 'S')
	{

	}
	if (key == 'd')
	{

	}
	else if (key == 'D')
	{

	}

	// Q E
	if (key == 'q')
	{

	}
	else if (key == 'Q')
	{

	}
	if (key == 'e')
	{

	}
	else if (key == 'E')
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