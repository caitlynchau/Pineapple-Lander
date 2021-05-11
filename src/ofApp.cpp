
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

GravityForce::GravityForce(const ofVec3f &g) {
<<<<<<< HEAD
    this->g = g;
}

void GravityForce::updateForce(ofVec3f &forces, float t) {
    forces += g;
}
ThrustForce::ThrustForce(float magnitude) {
    this->magnitude = magnitude;
}

void ThrustForce::updateForce(ofVec3f &forces, float t) {
    forces.y += t;
}
TurbulenceForce::TurbulenceForce(const ofVec3f &min, const ofVec3f &max) {
    tmin = min;
    tmax = max;
}

void TurbulenceForce::updateForce(ofVec3f &forces, float t) {
    //
    // We are going to add a little "noise" to a particles
    // forces to achieve a more natual look to the motion
    //
    forces.x += ofRandom(tmin.x, tmax.x);
    forces.y += ofRandom(tmin.y, tmax.y);
    forces.z += ofRandom(tmin.z, tmax.z);
=======
	this->g = g;
}

void GravityForce::updateForce(ofVec3f &forces, float t) {
	forces += g;
}
ThrustForce::ThrustForce(float magnitude) {
	this->magnitude = magnitude;
}

void ThrustForce::updateForce(ofVec3f &forces, float t) {
	forces.y += t;
}
TurbulenceForce::TurbulenceForce(const ofVec3f &min, const ofVec3f &max) {
	tmin = min;
	tmax = max;
}

void TurbulenceForce::updateForce(ofVec3f &forces, float t) {
	//
	// We are going to add a little "noise" to a particles
	// forces to achieve a more natual look to the motion
	//
	forces.x += ofRandom(tmin.x, tmax.x);
	forces.y += ofRandom(tmin.y, tmax.y);
	forces.z += ofRandom(tmin.z, tmax.z);
>>>>>>> moved files to openFrameworks myApps folder
}
//--------------------------------------------------------------
// setup scene, lighting, state and load geometry
//
<<<<<<< HEAD
void ofApp::setup(){
=======
void ofApp::setup() {
>>>>>>> moved files to openFrameworks myApps folder
	bWireframe = false;
	bDisplayPoints = false;
	bAltKeyDown = false;
	bCtrlKeyDown = false;
	bLanderLoaded = false;
	bTerrainSelected = true;
<<<<<<< HEAD
//	ofSetWindowShape(1024, 768);
=======
	//	ofSetWindowShape(1024, 768);
>>>>>>> moved files to openFrameworks myApps folder
	cam.setDistance(25);
	cam.setNearClip(.1);
	cam.setFov(65.5);   // approx equivalent to 28mm in 35mm format
	ofSetVerticalSync(true);
	cam.disableMouseInput();
	ofEnableSmoothing();
	ofEnableDepthTest();
<<<<<<< HEAD
    
    //Initialize forces
    g = new GravityForce(ofVec3f(0,-3.72,0));
    tf = new ThrustForce(10.0);
    turb = new TurbulenceForce(ofVec3f(-10,-10,-10), ofVec3f(10,10,10));
=======

	//Initialize forces
	g = new GravityForce(ofVec3f(0, -3.72, 0));
	tf = new ThrustForce(10.0);
	turb = new TurbulenceForce(ofVec3f(-10, -10, -10), ofVec3f(10, 10, 10));
>>>>>>> moved files to openFrameworks myApps folder
	// setup rudimentary lighting 
	//
	initLightingAndMaterials();

<<<<<<< HEAD
	if(mars.loadModel("mars-low-5x-v2.obj"))
        cout << "Model loaded" << endl;
    else
        cout << "Load failed" << endl;
=======
	if (mars.loadModel("mars-low-5x-v2.obj"))
		cout << "Model loaded" << endl;
	else
		cout << "Load failed" << endl;
>>>>>>> moved files to openFrameworks myApps folder
	mars.setScaleNormalization(false);

	// create sliders for testing
	//
	gui.setup();
	gui.add(numLevels.setup("Number of Octree Levels", 1, 1, 10));
	bHide = false;

	//  Create Octree for testing.
	//
	float beg = ofGetElapsedTimeMillis();
<<<<<<< HEAD
    octree.create(mars.getMesh(0), 20);
    float fin = ofGetElapsedTimeMillis();
    //cout << "Octree Creation Time: " << fin - beg << " millisec" << endl;
    octreeCreation = fin - beg;
    openFile();
    //cout << "Octree Creation Time: " << octreeCreation << " milliseconds" << endl;
    timeData << "Octree Creation Time: " << octreeCreation << " milliseconds\n";
//    closeFile();
    
	cout << "Number of Verts: " << mars.getMesh(0).getNumVertices() << endl;
    ofVec3f point;
        mouseIntersectPlane(ofVec3f(0, 0, 0), cam.getZAxis(), point);
        if (lander.loadModel("lander.obj")) {
            lander.setScaleNormalization(false);
    //        lander.setScale(.1, .1, .1);
        //    lander.setPosition(point.x, point.y, point.z);
            lander.setPosition(1, 1, 0);

            bLanderLoaded = true;
            for (int i = 0; i < lander.getMeshCount(); i++) {
                bboxList.push_back(Octree::meshBounds(lander.getMesh(i)));
            }

            cout << "Mesh Count: " << lander.getMeshCount() << endl;
        }
        else cout << "Error: Can't load model" << endl;
=======
	octree.create(mars.getMesh(0), 20);
	float fin = ofGetElapsedTimeMillis();
	//cout << "Octree Creation Time: " << fin - beg << " millisec" << endl;
	octreeCreation = fin - beg;
	openFile();
	//cout << "Octree Creation Time: " << octreeCreation << " milliseconds" << endl;
	timeData << "Octree Creation Time: " << octreeCreation << " milliseconds\n";
	//    closeFile();

	cout << "Number of Verts: " << mars.getMesh(0).getNumVertices() << endl;
	ofVec3f point;
	mouseIntersectPlane(ofVec3f(0, 0, 0), cam.getZAxis(), point);
	if (lander.loadModel("lander.obj")) {
		lander.setScaleNormalization(false);
		//        lander.setScale(.1, .1, .1);
			//    lander.setPosition(point.x, point.y, point.z);
		lander.setPosition(1, 1, 0);

		bLanderLoaded = true;
		for (int i = 0; i < lander.getMeshCount(); i++) {
			bboxList.push_back(Octree::meshBounds(lander.getMesh(i)));
		}

		cout << "Mesh Count: " << lander.getMeshCount() << endl;
	}
	else cout << "Error: Can't load model" << endl;
>>>>>>> moved files to openFrameworks myApps folder

	testBox = Box(Vector3(3, 3, 0), Vector3(5, 5, 2));

}
<<<<<<< HEAD
 
=======

>>>>>>> moved files to openFrameworks myApps folder
//--------------------------------------------------------------
// incrementally update scene (animation)
//
void ofApp::update() {
<<<<<<< HEAD
    //saveFile();
   
    integrate();
    //g->updateForce(forces, 1.62);
    //tf->updateForce(forces, 5);
    
}
void ofApp::integrate() {

    //pos += (velocity*dt);
    glm::vec3 current = lander.getPosition();
    current += (velocity*dt);
    lander.setPosition(current.x, current.y, current.z);
    // 1D angular motion using omega (angular velocity)
    //
    //rotation += (angularVelocity*dt);

    // update acceleration with accumulated paritcles forces
    // (a = 1/m * f)
    //
    ofVec3f accel = acceleration;    // start with any acceleration already on the particle
    accel += (forces * (1.0 / mass));
    //cout << "accel: " << accel << endl;
    velocity += accel * dt;
    
    //add damping
    velocity *= 0.9;
    cout << velocity << endl;
    angularVelocity *= 0.99;
    
    forces = ofVec3f(0,0,0);

}
void ofApp::openFile() {
    timeData.open("timeData.txt", ofFile::WriteOnly);
}
void ofApp::closeFile() {
    timeData.close();
=======
	//saveFile();

	integrate();
	//g->updateForce(forces, 1.62);
	//tf->updateForce(forces, 5);

}
void ofApp::integrate() {

	//pos += (velocity*dt);
	glm::vec3 current = lander.getPosition();
	current += (velocity*dt);
	lander.setPosition(current.x, current.y, current.z);
	// 1D angular motion using omega (angular velocity)
	//
	//rotation += (angularVelocity*dt);

	// update acceleration with accumulated paritcles forces
	// (a = 1/m * f)
	//
	ofVec3f accel = acceleration;    // start with any acceleration already on the particle
	accel += (forces * (1.0 / mass));
	//cout << "accel: " << accel << endl;
	velocity += accel * dt;

	//add damping
	velocity *= 0.9;
	cout << velocity << endl;
	angularVelocity *= 0.99;

	forces = ofVec3f(0, 0, 0);

}
void ofApp::openFile() {
	timeData.open("timeData.txt", ofFile::WriteOnly);
}
void ofApp::closeFile() {
	timeData.close();
>>>>>>> moved files to openFrameworks myApps folder
}
void ofApp::saveFile()
{
}
//--------------------------------------------------------------
void ofApp::draw() {

	ofBackground(ofColor::black);

	glDepthMask(false);
	if (!bHide) gui.draw();
	glDepthMask(true);

	cam.begin();
	ofPushMatrix();
<<<<<<< HEAD
//    ofSetColor(ofColor::purple);
//    Octree::drawBox(testBox);
=======
	//    ofSetColor(ofColor::purple);
	//    Octree::drawBox(testBox);
>>>>>>> moved files to openFrameworks myApps folder
	if (bWireframe) {                    // wireframe mode  (include axis)
		ofDisableLighting();
		ofSetColor(ofColor::slateGray);
		mars.drawWireframe();
		if (bLanderLoaded) {
			lander.drawWireframe();
			if (!bTerrainSelected) drawAxis(lander.getPosition());
		}
		if (bTerrainSelected) drawAxis(ofVec3f(0, 0, 0));
	}
	else {
		ofEnableLighting();              // shaded mode
		mars.drawFaces();
		ofMesh mesh;
		if (bLanderLoaded) {
			lander.drawFaces();
			if (!bTerrainSelected) drawAxis(lander.getPosition());
			if (bDisplayBBoxes) {
				ofNoFill();
				ofSetColor(ofColor::white);
				for (int i = 0; i < lander.getNumMeshes(); i++) {
					ofPushMatrix();
					ofMultMatrix(lander.getModelMatrix());
					ofRotate(-90, 1, 0, 0);
					Octree::drawBox(bboxList[i]);
					ofPopMatrix();
				}
			}

			if (bLanderSelected) {

				ofVec3f min = lander.getSceneMin() + lander.getPosition();
				ofVec3f max = lander.getSceneMax() + lander.getPosition();

				Box bounds = Box(Vector3(min.x, min.y, min.z), Vector3(max.x, max.y, max.z));
				ofSetColor(ofColor::white);
<<<<<<< HEAD
                ofNoFill();
=======
				ofNoFill();
>>>>>>> moved files to openFrameworks myApps folder
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
		ofSetColor(ofColor::green);
		mars.drawVertices();
	}

	// highlight selected point (draw sphere around selected point)
	//
	if (bPointSelected) {
		ofSetColor(ofColor::blue);
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
<<<<<<< HEAD
    }
=======
	}
>>>>>>> moved files to openFrameworks myApps folder
	else if (bDisplayOctree) {
		ofNoFill();
		ofSetColor(ofColor::white);
		octree.draw(numLevels, 0);
	}

	// if point selected, draw a sphere
	//
	if (pointSelected) {
		ofVec3f p = octree.mesh.getVertex(selectedNode.points[0]);
		ofVec3f d = p - cam.getPosition();
		ofSetColor(ofColor::lightGreen);
		ofDrawSphere(p, .02 * d.length());
	}

	ofPopMatrix();
	cam.end();
<<<<<<< HEAD
    
=======

>>>>>>> moved files to openFrameworks myApps folder
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
<<<<<<< HEAD
	
=======

>>>>>>> moved files to openFrameworks myApps folder

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
		if (cam.getMouseInputEnabled()) cam.disableMouseInput();
		else cam.enableMouseInput();
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
		bDisplayLeafNodes = !bDisplayLeafNodes;
		break;
	case 'O':
	case 'o':
		bDisplayOctree = !bDisplayOctree;
		break;
	case 'r':
		cam.reset();
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
<<<<<<< HEAD
    case 'z':
        bZAxis = true;
        break;
    case OF_KEY_RIGHT:
        velocity.x += 5;
        bKeyPressed = true;
        cout << "right" << endl;
        break;
    case OF_KEY_LEFT:
        bKeyPressed = true;
        velocity.x -= 5;
        cout << "left" << endl;
        break;
    case OF_KEY_UP:     // go forward
        bKeyPressed = true;
        if(bZAxis)
            velocity.z -= 5;
        else
            velocity.y += 5*heading().y;
        cout << "up" << endl;
        break;
    case OF_KEY_DOWN:   // go backward
        bKeyPressed = true;
        if(bZAxis)
            velocity.z += 5;
        else
            velocity.y -= 5*heading().y;
        cout << "down" << endl;
        break;
=======
	case 'z':
		bZAxis = true;
		break;
	case OF_KEY_RIGHT:
		velocity.x += 5;
		bKeyPressed = true;
		cout << "right" << endl;
		break;
	case OF_KEY_LEFT:
		bKeyPressed = true;
		velocity.x -= 5;
		cout << "left" << endl;
		break;
	case OF_KEY_UP:     // go forward
		bKeyPressed = true;
		if (bZAxis)
			velocity.z -= 5;
		else
			velocity.y += 5 * heading().y;
		cout << "up" << endl;
		break;
	case OF_KEY_DOWN:   // go backward
		bKeyPressed = true;
		if (bZAxis)
			velocity.z += 5;
		else
			velocity.y -= 5 * heading().y;
		cout << "down" << endl;
		break;
>>>>>>> moved files to openFrameworks myApps folder
	case OF_KEY_ALT:
		cam.enableMouseInput();
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

	switch (key) {
<<<<<<< HEAD
	
=======

>>>>>>> moved files to openFrameworks myApps folder
	case OF_KEY_ALT:
		cam.disableMouseInput();
		bAltKeyDown = false;
		break;
	case OF_KEY_CONTROL:
		bCtrlKeyDown = false;
		break;
	case OF_KEY_SHIFT:
		break;
<<<<<<< HEAD
    case 'z':
        bZAxis = false;
        break;
    case OF_KEY_RIGHT:
        bKeyPressed = false;
        break;
    case OF_KEY_LEFT:
        bKeyPressed = false;
        break;
    case OF_KEY_UP:     // go forward
        bKeyPressed = false;
        break;
    case OF_KEY_DOWN:   // go backward
        bKeyPressed = false;
        break;
=======
	case 'z':
		bZAxis = false;
		break;
	case OF_KEY_RIGHT:
		bKeyPressed = false;
		break;
	case OF_KEY_LEFT:
		bKeyPressed = false;
		break;
	case OF_KEY_UP:     // go forward
		bKeyPressed = false;
		break;
	case OF_KEY_DOWN:   // go backward
		bKeyPressed = false;
		break;
>>>>>>> moved files to openFrameworks myApps folder
	default:
		break;

	}
}



//--------------------------------------------------------------
<<<<<<< HEAD
void ofApp::mouseMoved(int x, int y ){

	
=======
void ofApp::mouseMoved(int x, int y) {


>>>>>>> moved files to openFrameworks myApps folder
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

	// if moving camera, don't allow mouse interaction
	//
	if (cam.getMouseInputEnabled()) return;

	// if moving camera, don't allow mouse interaction
//
	if (cam.getMouseInputEnabled()) return;

	// if rover is loaded, test for selection
	//
	if (bLanderLoaded) {
		glm::vec3 origin = cam.getPosition();
		glm::vec3 mouseWorld = cam.screenToWorld(glm::vec3(mouseX, mouseY, 0));
		glm::vec3 mouseDir = glm::normalize(mouseWorld - origin);

		ofVec3f min = lander.getSceneMin() + lander.getPosition();
		ofVec3f max = lander.getSceneMax() + lander.getPosition();

		Box bounds = Box(Vector3(min.x, min.y, min.z), Vector3(max.x, max.y, max.z));
		bool hit = bounds.intersect(Ray(Vector3(origin.x, origin.y, origin.z), Vector3(mouseDir.x, mouseDir.y, mouseDir.z)), 0, 10000);
		if (hit) {
			bLanderSelected = true;
			mouseDownPos = getMousePointOnPlane(lander.getPosition(), cam.getZAxis());
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
	ofVec3f rayPoint = cam.screenToWorld(mouse);
	ofVec3f rayDir = rayPoint - cam.getPosition();
	rayDir.normalize();
	Ray ray = Ray(Vector3(rayPoint.x, rayPoint.y, rayPoint.z),
		Vector3(rayDir.x, rayDir.y, rayDir.z));

<<<<<<< HEAD
    float beg = ofGetElapsedTimeMillis();
    pointSelected = octree.intersect(ray, octree.root, selectedNode);
    float fin = ofGetElapsedTimeMillis();
    
    rayIntersection = fin - beg;
    //cout << "Ray Intersection Time: " << rayIntersection << "milliseconds" << endl;
    timeData << "Ray Intersection Time: " << rayIntersection << "milliseconds\n";
=======
	float beg = ofGetElapsedTimeMillis();
	pointSelected = octree.intersect(ray, octree.root, selectedNode);
	float fin = ofGetElapsedTimeMillis();

	rayIntersection = fin - beg;
	//cout << "Ray Intersection Time: " << rayIntersection << "milliseconds" << endl;
	timeData << "Ray Intersection Time: " << rayIntersection << "milliseconds\n";
>>>>>>> moved files to openFrameworks myApps folder

	if (pointSelected) {
		pointRet = octree.mesh.getVertex(selectedNode.points[0]);
	}
	return pointSelected;
}




//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

	// if moving camera, don't allow mouse interaction
	//
	if (cam.getMouseInputEnabled()) return;

	if (bInDrag) {

		glm::vec3 landerPos = lander.getPosition();

		glm::vec3 mousePos = getMousePointOnPlane(landerPos, cam.getZAxis());
		glm::vec3 delta = mousePos - mouseLastPos;
<<<<<<< HEAD
	
=======

>>>>>>> moved files to openFrameworks myApps folder
		landerPos += delta;
		lander.setPosition(landerPos.x, landerPos.y, landerPos.z);
		mouseLastPos = mousePos;

		ofVec3f min = lander.getSceneMin() + lander.getPosition();
		ofVec3f max = lander.getSceneMax() + lander.getPosition();

		Box bounds = Box(Vector3(min.x, min.y, min.z), Vector3(max.x, max.y, max.z));

		colBoxList.clear();
<<<<<<< HEAD
        
        float beg = ofGetElapsedTimeMillis();
        octree.intersect(bounds, octree.root, colBoxList);
        float fin = ofGetElapsedTimeMillis();
        boundIntersection = fin - beg;
        //cout << "Box Intersection Time: " << rayIntersection << "milliseconds" << endl;
        timeData << "Box Intersection Time: " << rayIntersection << "milliseconds\n";
        closeFile();
        
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
=======

		float beg = ofGetElapsedTimeMillis();
		octree.intersect(bounds, octree.root, colBoxList);
		float fin = ofGetElapsedTimeMillis();
		boundIntersection = fin - beg;
		//cout << "Box Intersection Time: " << rayIntersection << "milliseconds" << endl;
		timeData << "Box Intersection Time: " << rayIntersection << "milliseconds\n";
		closeFile();

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
>>>>>>> moved files to openFrameworks myApps folder
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
<<<<<<< HEAD
void ofApp::mouseEntered(int x, int y){
=======
void ofApp::mouseEntered(int x, int y) {
>>>>>>> moved files to openFrameworks myApps folder

}

//--------------------------------------------------------------
<<<<<<< HEAD
void ofApp::mouseExited(int x, int y){
=======
void ofApp::mouseExited(int x, int y) {
>>>>>>> moved files to openFrameworks myApps folder

}

//--------------------------------------------------------------
<<<<<<< HEAD
void ofApp::windowResized(int w, int h){
=======
void ofApp::windowResized(int w, int h) {
>>>>>>> moved files to openFrameworks myApps folder

}

//--------------------------------------------------------------
<<<<<<< HEAD
void ofApp::gotMessage(ofMessage msg){
=======
void ofApp::gotMessage(ofMessage msg) {
>>>>>>> moved files to openFrameworks myApps folder

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
<<<<<<< HEAD
	{5.0, 5.0, 5.0, 0.0 };
=======
	{ 5.0, 5.0, 5.0, 0.0 };
>>>>>>> moved files to openFrameworks myApps folder

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
<<<<<<< HEAD
//	glEnable(GL_LIGHT1);
	glShadeModel(GL_SMOOTH);
} 
=======
	//	glEnable(GL_LIGHT1);
	glShadeModel(GL_SMOOTH);
}
>>>>>>> moved files to openFrameworks myApps folder

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

<<<<<<< HEAD
	
=======

>>>>>>> moved files to openFrameworks myApps folder
}

bool ofApp::mouseIntersectPlane(ofVec3f planePoint, ofVec3f planeNorm, ofVec3f &point) {
	ofVec2f mouse(mouseX, mouseY);
	ofVec3f rayPoint = cam.screenToWorld(glm::vec3(mouseX, mouseY, 0));
	ofVec3f rayDir = rayPoint - cam.getPosition();
	rayDir.normalize();
	return (rayIntersectPlane(rayPoint, rayDir, planePoint, planeNorm, point));
}

//--------------------------------------------------------------
//
// support drag-and-drop of model (.obj) file loading.  when
// model is dropped in viewport, place origin under cursor
//
void ofApp::dragEvent(ofDragInfo dragInfo) {
	if (lander.loadModel(dragInfo.files[0])) {
		bLanderLoaded = true;
		lander.setScaleNormalization(false);
		lander.setPosition(0, 0, 0);
		cout << "number of meshes: " << lander.getNumMeshes() << endl;
		bboxList.clear();
		for (int i = 0; i < lander.getMeshCount(); i++) {
			bboxList.push_back(Octree::meshBounds(lander.getMesh(i)));
		}

		//		lander.setRotation(1, 180, 1, 0, 0);

				// We want to drag and drop a 3D object in space so that the model appears 
				// under the mouse pointer where you drop it !
				//
				// Our strategy: intersect a plane parallel to the camera plane where the mouse drops the model
				// once we find the point of intersection, we can position the lander/lander
				// at that location.
				//

				// Setup our rays
				//
		glm::vec3 origin = cam.getPosition();
		glm::vec3 camAxis = cam.getZAxis();
		glm::vec3 mouseWorld = cam.screenToWorld(glm::vec3(mouseX, mouseY, 0));
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
			glm::vec3 min = lander.getSceneMin();
			glm::vec3 max = lander.getSceneMax();
			float offset = (max.y - min.y) / 2.0;
			lander.setPosition(intersectPoint.x, intersectPoint.y - offset, intersectPoint.z);

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
	glm::vec3 origin = cam.getPosition();
	glm::vec3 camAxis = cam.getZAxis();
	glm::vec3 mouseWorld = cam.screenToWorld(glm::vec3(mouseX, mouseY, 0));
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
