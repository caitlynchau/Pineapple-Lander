#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxAssimpModelLoader.h"
#include "Octree.h"
#include <glm/gtx/intersect.hpp>
#include "ship.h"




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
        glm::vec3 getMousePointOnPlane(glm::vec3 p , glm::vec3 n);

        //Time
        float thrust_start;
        float thrust_end;
    
        //Forces

        ImpulseForce *iForce;
        GravityForce *gravityForce;
        ThrustForce *thrustForce;
        TurbulenceForce *turbForce;
        
        ofCamera *theCam; // Pointer to set current camera
		ofEasyCam mainCam;
        ofCamera launchCam;
        ofCamera onboardCam;

		ofxAssimpModelLoader mars, lander;
		ofLight light;
		Box boundingBox, landerBounds;
		vector<Box> colBoxList;
		bool bLanderSelected = false;
		Octree octree;
		TreeNode selectedNode;
		glm::vec3 mouseDownPos, mouseLastPos;
		bool bInDrag = false;
        
        ofTrueTypeFont secondsText;
        ofTrueTypeFont velocityText;
        int seconds;
		
    ofxIntSlider numLevels;
		ofxPanel gui;

		bool bSpacePressed = false;
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

		const float selectionRange = 4.0; // not sure what this is for lol
        
		// Ship object
		Ship *pineapple;
        
        void checkCollisions();
        bool landed = false;
        float restitution = 0.5;
        vector<TreeNode> nodeList;
        float time = 0;;
        };
