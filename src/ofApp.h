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
	// Gotta ask professor about rotation since a vec3 isn't good for rotations and we haven't learned about quaternions.

	// Helper functions.
	void buildMesh(ofMesh& mesh, glm::vec3 pos, float width, float height);
	
	// Shader reloading.
	bool needsShaderReload { true };
	void reloadShaders();
};
