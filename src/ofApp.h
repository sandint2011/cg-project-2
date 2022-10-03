#pragma once

#include "ofMain.h"
#include <vector>

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

private:
	ofMesh legoMesh;
	ofMesh swordMesh;
	ofShader shader;

	glm::vec3 cameraPosition = glm::vec3(0, 0, 0);
	glm::vec3 cameraTarget = glm::vec3(0, 0, 0);

	// Camera functions.
	glm::vec3 ofApp::cameraDirection(); // Technically a backwards direction.
	glm::vec3 ofApp::cameraRight();
	glm::vec3 ofApp::cameraUp();

	// Helper functions.
	void buildMesh(ofMesh& mesh, glm::vec3 pos, float width, float height);
	
	// Shader reloading.
	bool needsShaderReload { true };
	void reloadShaders();
};
