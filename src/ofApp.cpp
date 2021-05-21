//--------------------------------------------------------------
//
//  Kevin M. Smith
//
//  Octree Test - startup scene
// 
//
//  Student Name:   Caitlyn Chau
//  Date: 20210502


#include "ofApp.h"
#include "Util.h"


// remove later lol
//#include "TMarker.h"

//--------------------------------------------------------------
// setup scene, lighting, state and load geometry
//
void ofApp::setup() {
    if(background.load("spongebobBG2.jpeg"))
          cout << "background loaded" << endl;
       else cout << "background load failed" << endl;

	bWireframe = false;
	bDisplayPoints = false;
	bAltKeyDown = false;
	bCtrlKeyDown = false;
	bLanderLoaded = false;
	bTerrainSelected = true;
	//	ofSetWindowShape(1024, 768);
    //background.load("spongebobBG1.jpeg");
        
    theCam = &launchCam;    // set the cam to the launchCam
    mainCam.setDistance(25);
    mainCam.setNearClip(.1);
    mainCam.setFov(65.5);   // approx equivalent to 28mm in 35mm format
	ofSetVerticalSync(true);
    mainCam.disableMouseInput();
	ofEnableSmoothing();
	ofEnableDepthTest();
    
    //Init forces

    iForce = new ImpulseForce();
    gravityForce = new GravityForce(ofVec3f(0, -3.72, 0));
    thrustForce = new ThrustForce(5.0);
    turbForce = new TurbulenceForce(ofVec3f(-10, -10, -10), ofVec3f(10, 10, 10));

    
    
	// setup rudimentary lighting 
	//
	initLightingAndMaterials();

   
    
    background.resize(736*6, 368*6);
//	if (mars.loadModel("mars-low-5x-v2.obj"))
    ofDisableArbTex();
    ofLoadImage(sandTexture, "spongebobSand.png");
        if (mars.loadModel("bbTerrain3.obj"))
		cout << "Model loaded" << endl;
	else
		cout << "Load failed" << endl;
	mars.setScaleNormalization(false);


	// game variables
	gameStarted = false; 
	gameEnded = false;


	// Trajectory markers for testing xD
	testMarkers = new MarkerSystem();
	testMarkers->init();
	numMarkersHit = 0;

	// create sliders for testing
	//
	gui.setup();
	gui.add(numLevels.setup("Number of Octree Levels", 1, 1, 10));
	bHide = false;

	//  Create Octree for testing.
	//
	octree.create(mars.getMesh(0), 20);

	cout << "Number of Verts: " << mars.getMesh(0).getNumVertices() << endl;
	ofVec3f point;
	mouseIntersectPlane(ofVec3f(0, 0, 0), mainCam.getZAxis(), point);
	
	// Try loading model
	if (lander.loadModel("burger.obj")) {
		lander.setScaleNormalization(false);
		//        lander.setScale(.1, .1, .1);
			//    lander.setPosition(point.x, point.y, point.z);
		lander.setPosition(0, -1, 0);

		bLanderLoaded = true;
		for (int i = 0; i < lander.getMeshCount(); i++) {
			bboxList.push_back(Octree::meshBounds(lander.getMesh(i)));
		}

		cout << "Mesh Count: " << lander.getMeshCount() << endl;

		// Create new ship
		pineapple = new Ship(lander);
		pineapple->setup();
		
	}
	else cout << "Error: Can't load model" << endl;
    
    explosion = new ParticleEmitter(new ParticleSystem());
    explosion->setOneShot(true);
    explosion->setEmitterType(RadialEmitter);
    explosion->setLifespan(0.4);
    explosion->setRate(5);
    explosion->setParticleRadius(0.5);
    explosion->setGroupSize(50);
    explosion->setVelocity(ofVec3f(30, 30, 30));
    
    //Create themed background
    for(int i = 0; i < 100; i++) {
        //front
        stars.push_back(glm::vec3(ofRandom(-700,700), ofRandom(-700,700), ofRandom(-600, -500)));
        //back
        stars.push_back(glm::vec3(ofRandom(-700,700), ofRandom(-700,700), ofRandom(500, 600)));
        //left
        stars.push_back(glm::vec3(ofRandom(-600,-500), ofRandom(-700,700), ofRandom(-700, 700)));
        //right
        stars.push_back(glm::vec3(ofRandom(500,600), ofRandom(-700,700), ofRandom(-700, 700)));
        //top
        stars.push_back(glm::vec3(ofRandom(-700,700), ofRandom(-600,-500), ofRandom(-700, 700)));
        //bottom
        stars.push_back(glm::vec3(ofRandom(-700,700), ofRandom(500,600), ofRandom(-700, 700)));
    }

    
	if (!secondsText.load("Krabby_Patty.ttf", 15) ||
		!velocityText.load("Krabby_Patty.ttf", 15) ||
		!gameStateText.load("Krabby_Patty.ttf", 48) ||
		!markersText.load("Krabby_Patty.ttf", 15)){
		cout << "Error: Can't load font" << endl;
	}

}

//--------------------------------------------------------------
// incrementally update scene (animation)
//
void ofApp::update() {

	

    //Update forces
    if (!gameStarted && !gameEnded) // new game
    {
        launchCam.setPosition(glm::vec3(pineapple->model.getPosition().x, pineapple->model.getPosition().y + 10, pineapple->model.getPosition().z + 50));
        launchCam.lookAt(pineapple->model.getPosition());
        onboardCam.setPosition(pineapple->model.getPosition());
        onboardCam.lookAt(glm::vec3(0,0,0));
    }
    else if (gameStarted && !gameEnded)  // Game in progress
    {
        pineapple->integrate(); // should we move this to ship's update?
        pineapple->update();
//        explosion->update();
        launchCam.setPosition(glm::vec3(pineapple->model.getPosition().x, pineapple->model.getPosition().y + 10, pineapple->model.getPosition().z + 50));
        launchCam.lookAt(pineapple->model.getPosition());
        onboardCam.setPosition(pineapple->model.getPosition());
        onboardCam.lookAt(glm::vec3(0,0,0));
        
        if(gameState == Flying) { // not landed, not crashed
                gravityForce->updateForce(pineapple, -3.72);
                turbForce->updateForce(pineapple, 10);
            }
        if (pineapple->thrustersOn) {
            thrustForce->updateForce(pineapple, 5.0);
        }
        
        checkCollisions();
        checkFlightPath();
    }
    else if (!gameStarted && gameEnded) // Game over
    {
        //Update camera views
        launchCam.setPosition(crashPosition);
        launchCam.lookAt(pineapple->model.getPosition());
        onboardCam.setPosition(crashPosition);
        onboardCam.lookAt(glm::vec3(0,0,0));
    }
    explosion->update();
    
//	else if (gameState == Crashed) { // crashed
//		// explosion
//		cout << "CRASHED" << endl;
//
//		// delete ship? TO BE CONTINUED
//		//explosion.sys->addForce()
//	}
//	else if (gameState == Landed) { // landed successfully
//		//cout << "LANDED" << endl;
//	}
	
    
    //Onscreen text to help player
//    ofDrawText(pineapple->timeLeft/1000 + "seconds of fuel left");

    // if (!gameStarted && !gameEnded)
    // new game
    
//    launchCam.setPosition(glm::vec3(pineapple->model.getPosition().x, pineapple->model.getPosition().y + 10, pineapple->model.getPosition().z + 50));
//    launchCam.lookAt(pineapple->model.getPosition());
//    onboardCam.setPosition(pineapple->model.getPosition());
//    onboardCam.lookAt(glm::vec3(0,0,0));

	// Game state
	if (pineapple->timeLeft <= 0) {;
		gameStarted = false;
		gameEnded = true;
		pineapple->model.setPosition(0, 0, 0);
		pineapple->velocity = ofVec3f(0, 0, 0);
		pineapple->angularVelocity = 0;
		pineapple->rotation = 0;
		pineapple->forces = ofVec3f(0, 0, 0);
	}
}


//--------------------------------------------------------------
void ofApp::draw() {

	ofBackground(ofColor::cornflowerBlue);
    //background.resize(ofGetWindowWidth(), ofGetWindowHeight());
    //background.draw(0,0);
    

	glDepthMask(false);
	if (!bHide) gui.draw();
	glDepthMask(true);


	if (!gameStarted && !gameEnded) { // new game
		gameStateText.drawString("Press space to start", ofGetWindowWidth() / 3, ofGetWindowHeight() / 2);
	}
	if (!gameStarted && gameEnded) { // game over
		gameStateText.drawString("Game over", ofGetWindowWidth() / 3, ofGetWindowHeight() / 2);
	}
	else if (gameStarted && !gameEnded) { // game in progress
		seconds = pineapple->timeLeft / 1000;
		//Onscreen text to guide player
        ofSetColor(ofColor::white);
		secondsText.drawString(std::to_string(seconds) + " seconds of fuel left", ofGetWindowWidth() - 250, 20);
		velocityText.drawString("Velocity: " + std::to_string(pineapple->velocity.y), ofGetWindowWidth() - 250, 40);
		markersText.drawString("Num markers hit: " + std::to_string(numMarkersHit), ofGetWindowWidth() - 250, 60);
	}
    
	theCam->begin();
    background.draw(-2200,-1000,-600);

    for(int i = 0; i < stars.size(); i++) {
        ofDrawSphere(stars[i], 1.5);
        if(i%5==0)
            ofSetColor(ofColor::darkGreen);
        else if(i%4==0)
            ofSetColor(ofColor::lightPink);
        else if(i%3==0)
            ofSetColor(ofColor::magenta);
        else if(i%2==0)
            ofSetColor(ofColor::lavender);
        else
            ofSetColor(ofColor::white);
    }
	ofPushMatrix();
	//    ofSetColor(ofColor::purple);
	//    Octree::drawBox(testBox);
    //if(gameState == Crashed)
    explosion->draw();
	if (bWireframe) {                    // wireframe mode  (include axis)
		ofDisableLighting();
		// ofSetColor(255, 0, 0);
		mars.drawWireframe();
		if (bLanderLoaded) {
			pineapple->model.drawWireframe();
			if (!bTerrainSelected) drawAxis(pineapple->model.getPosition());
		}
		if (bTerrainSelected) drawAxis(ofVec3f(0, 0, 0));
	}
	else {
		ofDisableLighting();              // shaded mode
        sandTexture.bind();
		mars.drawFaces();
        sandTexture.unbind();
		ofMesh mesh;
		if (bLanderLoaded && !gameEnded) {
			pineapple->model.drawFaces();
			if (!bTerrainSelected) drawAxis(pineapple->model.getPosition());
			if (bDisplayBBoxes) {
				ofNoFill();
				ofSetColor(ofColor::white);
				for (int i = 0; i < pineapple->model.getNumMeshes(); i++) {
					ofPushMatrix();
					ofMultMatrix(pineapple->model.getModelMatrix());
					ofRotate(-90, 1, 0, 0);
					Octree::drawBox(bboxList[i]);
					ofPopMatrix();
				}
			}

			if (bLanderSelected) {

				ofVec3f min = pineapple->model.getSceneMin() + pineapple->model.getPosition();
				ofVec3f max = pineapple->model.getSceneMax() + pineapple->model.getPosition();

				Box bounds = Box(Vector3(min.x, min.y, min.z), Vector3(max.x, max.y, max.z));
				ofSetColor(ofColor::white);
				ofNoFill();
				Octree::drawBox(bounds);

				// draw colliding boxes
				//
				ofSetColor(ofColor::purple);
				for (int i = 0; i < colBoxList.size(); i++) {
					Octree::drawBox(colBoxList[i]);
				}
			}
		}
	}
	if (bTerrainSelected) drawAxis(ofVec3f(0, 0, 0));

	

	if (bDisplayPoints) {                // display points as an option    
		glPointSize(3);
		//ofSetColor(ofColor::green);
		mars.drawVertices();
	}

	// highlight selected point (draw sphere around selected point)
	//
	if (bPointSelected) {
		//ofSetColor(ofColor::blue);
		ofDrawSphere(selectedPoint, .1);
	}


	// recursively draw octree
	//
	ofDisableLighting();
	int level = 0;
	//	ofNoFill();

	if (bDisplayLeafNodes) {
		octree.drawLeafNodes(octree.root);
		//cout << "num leaf: " << octree.numLeaf << endl;
	}
	else if (bDisplayOctree) {
		ofNoFill();
		//ofSetColor(ofColor::white);
		octree.draw(numLevels, 0);
	}

	// if point selected, draw a sphere
	//
	if (pointSelected) {
		ofVec3f p = octree.mesh.getVertex(selectedNode.points[0]);
		ofVec3f d = p - theCam->getPosition();
		//ofSetColor(ofColor::lightGreen);
		ofDrawSphere(p, .02 * d.length());
	}

	// draw ship's particle emitter
	if (pineapple->thrustersOn) 	pineapple->draw();

	// for testing lol
	testMarkers->draw();


	ofPopMatrix();
	theCam->end();
}


// 
// Draw an XYZ axis in RGB at world (0,0,0) for reference.
//
void ofApp::drawAxis(ofVec3f location) {

	ofPushMatrix();
	ofTranslate(location);

	ofSetLineWidth(1.0);

	// X Axis
	ofSetColor(ofColor(255, 0, 0));
	ofDrawLine(ofPoint(0, 0, 0), ofPoint(1, 0, 0));


	// Y Axis
	ofSetColor(ofColor(0, 255, 0));
	ofDrawLine(ofPoint(0, 0, 0), ofPoint(0, 1, 0));

	// Z Axis
	ofSetColor(ofColor(0, 0, 255));
	ofDrawLine(ofPoint(0, 0, 0), ofPoint(0, 0, 1));

	ofPopMatrix();
}


void ofApp::keyPressed(int key) {
	switch (key) {
	case 'B':
	case 'b':
		bDisplayBBoxes = !bDisplayBBoxes;
		break;
	case 'C':
	case 'c':
		if (mainCam.getMouseInputEnabled()) mainCam.disableMouseInput();
		else mainCam.enableMouseInput();
		break;
	case 'F':
	case 'f':
		ofToggleFullscreen();
		break;
	case 'H':
	case 'h':
		break;
	case 'L':
	case 'l':
		//bDisplayLeafNodes = !bDisplayLeafNodes;
        theCam = &launchCam;
		break;
    case 'm':
        theCam = &mainCam;
        break;
	case 'O':
	case 'o':
		//bDisplayOctree = !bDisplayOctree;
        theCam = &onboardCam;
		break;
  case 'r':
    mainCam.reset();
		pineapple->model.setPosition(0, 0, 0);
		pineapple->velocity = ofVec3f(0, 0, 0);
		pineapple->angularVelocity = 0;
		pineapple->rotation = 0;
		pineapple->forces = ofVec3f(0, 0, 0);
		break;
	case 's':
		savePicture();
		break;
	case 't':
		setCameraTarget();
		break;
	case 'u':
		break;
	case 'v':
		togglePointsDisplay();
		break;
	case 'V':
		break;
	case 'w':
		toggleWireframeMode();
		break;
	case 'z':
		bZAxis = true;
		break;
	case ',': // '<' key
        if (gameStarted && !gameEnded)
        {
            pineapple->thrustersOn = true;
            thrust_start = ofGetElapsedTimeMillis();
            pineapple->angularVelocity -= 0.2;
            pineapple->axis = ofVec3f(0, 1, 0);
        }
		break;
	case '.': // '>' key
        if (gameStarted && !gameEnded)
        {
            pineapple->thrustersOn = true;
            thrust_start = ofGetElapsedTimeMillis();
            pineapple->angularVelocity += 0.2;
            pineapple->axis = ofVec3f(0, 1, 0);
        }
		break;
	case OF_KEY_RIGHT:
        if (gameStarted && !gameEnded)
        {
            pineapple->thrustersOn = true;
            thrust_start = ofGetElapsedTimeMillis();
            if (bZAxis) {
                pineapple->velocity.z += 2;
                pineapple->axis = ofVec3f(0, 0, 1);
            }
            else {
                pineapple->velocity.x += 2;
                pineapple->axis = ofVec3f(1, 0, 0);
            }
        }
		break;
	case OF_KEY_LEFT:
        if (gameStarted && !gameEnded)
        {
            pineapple->thrustersOn = true;
            thrust_start = ofGetElapsedTimeMillis();
            if (bZAxis) {
                pineapple->velocity.z -= 2;
                pineapple->axis = ofVec3f(0, 0, 1);
            }
            else {
                pineapple->velocity.x -= 2;
                pineapple->axis = ofVec3f(1, 0, 0);
            }
        }
		break;
	case OF_KEY_UP:
        if (gameStarted && !gameEnded)
        {
            pineapple->thrustersOn = true;
            thrust_start = ofGetElapsedTimeMillis();
            pineapple->velocity -= 2 * pineapple->heading();
        }
		break;
	case OF_KEY_DOWN:
        if (gameStarted && !gameEnded)
        {
            pineapple->thrustersOn = true;
            thrust_start = ofGetElapsedTimeMillis();
            pineapple->velocity += 2 * pineapple->heading();
        }
		
		break;
	case ' ':
		if (!gameStarted && !gameEnded) { // new player
			gameStarted = true;
		}
		
		break;
	case OF_KEY_ALT:
		mainCam.enableMouseInput();
		bAltKeyDown = true;
		break;
	case OF_KEY_CONTROL:
		bCtrlKeyDown = true;
		break;
	case OF_KEY_SHIFT:
		break;
	case OF_KEY_DEL:
		break;
	default:
		break;
	}
}

void ofApp::toggleWireframeMode() {
	bWireframe = !bWireframe;
}

void ofApp::toggleSelectTerrain() {
	bTerrainSelected = !bTerrainSelected;
}

void ofApp::togglePointsDisplay() {
	bDisplayPoints = !bDisplayPoints;
}

void ofApp::keyReleased(int key) {
    float fin;
	switch (key) {

	case OF_KEY_ALT:
		mainCam.disableMouseInput();
		bAltKeyDown = false;
		break;
	case OF_KEY_CONTROL:
		bCtrlKeyDown = false;
		break;
	case OF_KEY_SHIFT:
		break;
	case 'z':
		bZAxis = false;
		break;
	case '>':
	case '<':
	case OF_KEY_RIGHT:
	case OF_KEY_LEFT:
	case OF_KEY_UP: 
	case OF_KEY_DOWN: // switch case fall through
		thrust_end = ofGetElapsedTimeMillis();
		pineapple->thrustersOn = false;
		pineapple->timeLeft -= (thrust_end - thrust_start) * 3; //lol im trying to make the time go by faster
	case ' ': 
		break;
	default:
		break;

	}
}



//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {



}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

	// for testing: draw markers for trajectory
	/*
	glm::vec3 p = theCam->screenToWorld(glm::vec3(x, y, 0)); // convert to 3d
	cout << "mouse pressed " << p << endl;
	Marker m;
	m.setPosition(p);
	testMarkers->add(m);
	*/

	// if moving camera, don't allow mouse interaction
	//
	if (mainCam.getMouseInputEnabled()) return;

	// if moving camera, don't allow mouse interaction
//
	if (mainCam.getMouseInputEnabled()) return;

	// if rover is loaded, test for selection
	//
	if (bLanderLoaded) {
		glm::vec3 origin = mainCam.getPosition();
		glm::vec3 mouseWorld = mainCam.screenToWorld(glm::vec3(mouseX, mouseY, 0));
		glm::vec3 mouseDir = glm::normalize(mouseWorld - origin);

		ofVec3f min = pineapple->model.getSceneMin() + pineapple->model.getPosition();
		ofVec3f max = pineapple->model.getSceneMax() + pineapple->model.getPosition();

		Box bounds = Box(Vector3(min.x, min.y, min.z), Vector3(max.x, max.y, max.z));
		bool hit = bounds.intersect(Ray(Vector3(origin.x, origin.y, origin.z), Vector3(mouseDir.x, mouseDir.y, mouseDir.z)), 0, 10000);
		if (hit) {
			bLanderSelected = true;
			mouseDownPos = getMousePointOnPlane(pineapple->model.getPosition(), mainCam.getZAxis());
			mouseLastPos = mouseDownPos;
			bInDrag = true;
		}
		else {
			bLanderSelected = false;
		}
	}
	else {
		ofVec3f p;
		raySelectWithOctree(p);
		
	}
}

bool ofApp::raySelectWithOctree(ofVec3f &pointRet) {
	ofVec3f mouse(mouseX, mouseY);
	ofVec3f rayPoint = mainCam.screenToWorld(mouse);
	ofVec3f rayDir = rayPoint - mainCam.getPosition();
	rayDir.normalize();
	Ray ray = Ray(Vector3(rayPoint.x, rayPoint.y, rayPoint.z),
		Vector3(rayDir.x, rayDir.y, rayDir.z));

	pointSelected = octree.intersect(ray, octree.root, selectedNode);

	if (pointSelected) {
		pointRet = octree.mesh.getVertex(selectedNode.points[0]);
	}
	return pointSelected;
}


//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

	// if moving camera, don't allow mouse interaction
	//
	if (mainCam.getMouseInputEnabled()) return;

	if (bInDrag) {

		glm::vec3 landerPos = pineapple->model.getPosition();

		glm::vec3 mousePos = getMousePointOnPlane(landerPos, mainCam.getZAxis());
		glm::vec3 delta = mousePos - mouseLastPos;

		landerPos += delta;
		pineapple->model.setPosition(landerPos.x, landerPos.y, landerPos.z);
		mouseLastPos = mousePos;

		ofVec3f min = pineapple->model.getSceneMin() + pineapple->model.getPosition();
		ofVec3f max = pineapple->model.getSceneMax() + pineapple->model.getPosition();

		Box bounds = Box(Vector3(min.x, min.y, min.z), Vector3(max.x, max.y, max.z));

		colBoxList.clear();

		octree.intersect(bounds, octree.root, colBoxList);


		//        cout << "leaves: " << colBoxList.size() << endl;
		//        if(colBoxList.size() > 0) {
		//            for(int i = 0; i < colBoxList.size(); i++) {
		//                if (bounds.overlap(colBoxList[i])) {
		//                    cout << "overlap" << endl;
		//                }
		//                else {
		//                    cout << "not" << endl;
		//                }
		//            }
		//        }

	}
	else {
		ofVec3f p;
		raySelectWithOctree(p);
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	bInDrag = false;
}



// Set the camera to use the selected point as it's new target
//  
void ofApp::setCameraTarget() {

}


//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}



//--------------------------------------------------------------
// setup basic ambient lighting in GL  (for now, enable just 1 light)
//
void ofApp::initLightingAndMaterials() {

	static float ambient[] =
	{ .5f, .5f, .5, 1.0f };
	static float diffuse[] =
	{ 1.0f, 1.0f, 1.0f, 1.0f };

	static float position[] =
	{ 5.0, 5.0, 5.0, 0.0 };

	static float lmodel_ambient[] =
	{ 1.0f, 1.0f, 1.0f, 1.0f };

	static float lmodel_twoside[] =
	{ GL_TRUE };


	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	glLightfv(GL_LIGHT1, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT1, GL_POSITION, position);


	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_TWO_SIDE, lmodel_twoside);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	//	glEnable(GL_LIGHT1);
	glShadeModel(GL_SMOOTH);
}

void ofApp::savePicture() {
	ofImage picture;
	picture.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
	picture.save("screenshot.png");
	cout << "picture saved" << endl;
}

//--------------------------------------------------------------
//
// support drag-and-drop of model (.obj) file loading.  when
// model is dropped in viewport, place origin under cursor
//
void ofApp::dragEvent2(ofDragInfo dragInfo) {


}

bool ofApp::mouseIntersectPlane(ofVec3f planePoint, ofVec3f planeNorm, ofVec3f &point) {
	ofVec2f mouse(mouseX, mouseY);
	ofVec3f rayPoint = mainCam.screenToWorld(glm::vec3(mouseX, mouseY, 0));
	ofVec3f rayDir = rayPoint - mainCam.getPosition();
	rayDir.normalize();
	return (rayIntersectPlane(rayPoint, rayDir, planePoint, planeNorm, point));
}

//--------------------------------------------------------------
//
// support drag-and-drop of model (.obj) file loading.  when
// model is dropped in viewport, place origin under cursor
//
void ofApp::dragEvent(ofDragInfo dragInfo) {
	if (pineapple->model.loadModel(dragInfo.files[0])) {
		bLanderLoaded = true;
		pineapple->model.setScaleNormalization(false);
		pineapple->model.setPosition(0, 0, 0);
		cout << "number of meshes: " << pineapple->model.getNumMeshes() << endl;
		bboxList.clear();
		for (int i = 0; i < pineapple->model.getMeshCount(); i++) {
			bboxList.push_back(Octree::meshBounds(pineapple->model.getMesh(i)));
		}

		//		pineapple->model.setRotation(1, 180, 1, 0, 0);

				// We want to drag and drop a 3D object in space so that the model appears 
				// under the mouse pointer where you drop it !
				//
				// Our strategy: intersect a plane parallel to the camera plane where the mouse drops the model
				// once we find the point of intersection, we can position the lander/lander
				// at that location.
				//

				// Setup our rays
				//
		glm::vec3 origin = mainCam.getPosition();
		glm::vec3 camAxis = mainCam.getZAxis();
		glm::vec3 mouseWorld = mainCam.screenToWorld(glm::vec3(mouseX, mouseY, 0));
		glm::vec3 mouseDir = glm::normalize(mouseWorld - origin);
		float distance;

		bool hit = glm::intersectRayPlane(origin, mouseDir, glm::vec3(0, 0, 0), camAxis, distance);
		if (hit) {
			// find the point of intersection on the plane using the distance 
			// We use the parameteric line or vector representation of a line to compute
			//
			// p' = p + s * dir;
			//
			glm::vec3 intersectPoint = origin + distance * mouseDir;

			// Now position the lander's origin at that intersection point
			//
			glm::vec3 min = pineapple->model.getSceneMin();
			glm::vec3 max = pineapple->model.getSceneMax();
			float offset = (max.y - min.y) / 2.0;
			pineapple->model.setPosition(intersectPoint.x, intersectPoint.y - offset, intersectPoint.z);

			// set up bounding box for lander while we are at it
			//
			landerBounds = Box(Vector3(min.x, min.y, min.z), Vector3(max.x, max.y, max.z));
		}
	}


}

//  intersect the mouse ray with the plane normal to the camera 
//  return intersection point.   (package code above into function)
//
glm::vec3 ofApp::getMousePointOnPlane(glm::vec3 planePt, glm::vec3 planeNorm) {
	// Setup our rays
	//
	glm::vec3 origin = mainCam.getPosition();
	glm::vec3 camAxis = mainCam.getZAxis();
	glm::vec3 mouseWorld = mainCam.screenToWorld(glm::vec3(mouseX, mouseY, 0));
	glm::vec3 mouseDir = glm::normalize(mouseWorld - origin);
	float distance;

	bool hit = glm::intersectRayPlane(origin, mouseDir, planePt, planeNorm, distance);

	if (hit) {
		// find the point of intersection on the plane using the distance 
		// We use the parameteric line or vector representation of a line to compute
		//
		// p' = p + s * dir;
		//
		glm::vec3 intersectPoint = origin + distance * mouseDir;

		return intersectPoint;
	}
	else return glm::vec3(0, 0, 0);
}


void ofApp::debug() {

}

void ofApp::explode(ofVec3f p) {
    explosion->setPosition(p);
    explosion->sys->reset();
    explosion->start();
}

void ofApp::checkCollisions()
{
    nodeList.clear();                 // clear list of overlapped nodes

    // box's min & max
    glm::vec3 min = pineapple->model.getSceneMin() + pineapple->model.getPosition();
    glm::vec3 max = pineapple->model.getSceneMax() + pineapple->model.getPosition();

    // lander box
    Box pineappleBounds = Box(Vector3(min.x, min.y, min.z), Vector3(max.x, max.y, max.z));
    
    // update nodeList
    octree.nodeIntersect(pineappleBounds, octree.root, nodeList);
    for (int i = 0; i < nodeList.size(); i++)
    {
        glm::vec3 vel = pineapple->velocity;
//        if (vel.y >= 0)
//        {
//            break;
//        }
        
        glm::vec3 vertex = octree.mesh.getVertex(nodeList.at(i).points.at(0));
        glm::vec3 pineapplePosition = pineapple->model.getPosition();
        float distance = glm::distance(pineapplePosition, vertex);
        //cout << "dist: " << distance << endl;
        
        if (distance <= 2)
        {
            
            glm::vec3 norm = octree.mesh.getNormal(nodeList.at(i).points.at(0));
        
            //vel *= 0.9;
            glm::vec3 impulseF = ((restitution + 1.0) * ((-glm::dot(vel, norm)) * norm));
            //cout << "i: " << impulseF << endl;
            //cout << "g: " << gravityForce->g << endl;
            //cout << "forces: " << pineapple->forces << endl;
            //cout << "turb: " << turbForce << endl;
            if (!iForce->applied)
            {
                pineapple->forces += ofGetFrameRate() * impulseF;
                iForce->applied = true;

				// if the incoming velocity is greater than 15(?), then crash
				if (vel.y < -15) {
					gameState = Crashed;
                    gameEnded = true;
                    gameStarted = false;
                    crashPosition = launchCam.getPosition();
                    //explosion->setPosition(vertex);
                    explode(vertex);
                    //explosion.start();
                    break;
				}
				else {
					gameState = Landed;
				}
            }
        }
    }
    if (iForce->applied) // reset the impulse force
    {
        iForce->applied = false;
    }

    if (nodeList.size() == 0)
    {
        //landed = false; // im not sure what dis means,, is game over?
		gameState = Flying;
    }
}

void ofApp::checkFlightPath() {

	glm::vec3 min = pineapple->model.getSceneMin() + pineapple->model.getPosition();
	glm::vec3 max = pineapple->model.getSceneMax() + pineapple->model.getPosition();
	Box pineappleBounds = Box(Vector3(min.x, min.y, min.z), Vector3(max.x, max.y, max.z));

	for (int i = 0; i < testMarkers->markers.size(); i++) {
		glm::vec3 marker = testMarkers->markers[i]->position;
		
		bool hit = pineappleBounds.intersect(Ray(Vector3(marker.x, marker.y, marker.z), Vector3(marker.x+5, marker.y+5, marker.z+5)), 0, 10000);
		
		if (hit && !testMarkers->markers[i]->hit) {
			numMarkersHit++;
			testMarkers->markers[i]->hit = true; 
		}
	}
}
