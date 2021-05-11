#pragma once

#include "ofMain.h"
<<<<<<< HEAD

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
		
};
=======
#include "ofxGui.h"
#include  "ofxAssimpModelLoader.h"
#include "Octree.h"
#include <glm/gtx/intersect.hpp>



class Force {
protected:
public:
	bool applyOnce = false;
	bool applied = false;
	virtual void updateForce(ofVec3f &forces, float t) = 0;
};
class GravityForce : public Force {
	ofVec3f g;
public:
	GravityForce(const ofVec3f &g);
	void updateForce(ofVec3f &forces, float t);
};
class ThrustForce : public Force {
	float magnitude;
public:
	ThrustForce(float magnitude);
	void updateForce(ofVec3f &forces, float t);
};
class TurbulenceForce : public Force {
	ofVec3f tmin, tmax;
public:
	TurbulenceForce(const ofVec3f & min, const ofVec3f &max);
	void updateForce(ofVec3f &forces, float t);
};


class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent2(ofDragInfo dragInfo);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	void drawAxis(ofVec3f);
	void initLightingAndMaterials();
	void savePicture();
	void toggleWireframeMode();
	void togglePointsDisplay();
	void toggleSelectTerrain();
	void setCameraTarget();
	bool mouseIntersectPlane(ofVec3f planePoint, ofVec3f planeNorm, ofVec3f &point);
	bool raySelectWithOctree(ofVec3f &pointRet);
	glm::vec3 getMousePointOnPlane(glm::vec3 p, glm::vec3 n);
	void openFile();
	void closeFile();
	void saveFile();
	void integrate();
	glm::vec3 heading() {
		glm::vec3 initialHeading = glm::vec3(0, -1, 0);
		glm::mat4 Mrot = glm::rotate(glm::mat4(1.0), glm::radians(rotation), glm::vec3(0, 0, 1));
		glm::vec3 h = Mrot * glm::vec4(initialHeading, 1);
		//head = glm::normalize(h);
		return glm::normalize(h);
	}

	ofEasyCam cam;
	ofxAssimpModelLoader mars, lander;
	ofLight light;
	Box boundingBox, landerBounds;
	Box testBox;
	vector<Box> colBoxList;
	bool bLanderSelected = false;
	Octree octree;
	TreeNode selectedNode;
	glm::vec3 mouseDownPos, mouseLastPos;
	bool bInDrag = false;

	float rotation = 0.0;


	ofxIntSlider numLevels;
	ofxPanel gui;

	bool bZAxis;
	bool bAltKeyDown;
	bool bCtrlKeyDown;
	bool bWireframe;
	bool bDisplayPoints;
	bool bPointSelected;
	bool bHide;
	bool pointSelected = false;
	bool bDisplayLeafNodes = false;
	bool bDisplayOctree = false;
	bool bDisplayBBoxes = false;
	bool bKeyPressed = false;

	bool bLanderLoaded;
	bool bTerrainSelected;

	ofVec3f selectedPoint;
	ofVec3f intersectPoint;

	vector<Box> bboxList;

	const float selectionRange = 4.0;

	ofFile timeData;
	int octreeCreation;
	int rayIntersection;
	int boundIntersection;

	//Physics variables
	GravityForce *g;
	ThrustForce *tf;
	TurbulenceForce *turb;
	ofVec3f velocity = ofVec3f(0, 7, 0);
	ofVec3f acceleration;
	ofVec3f forces = ofVec3f(0, 0, 0);
	float dt = 1.0 / 60.0;
	float angularVelocity = 0;
	float mass = 1.0;
	float damping = 0.99;
	bool rotate;
};
>>>>>>> 42318d85abc74f2c0ba592b6652c6c1db16cd580
