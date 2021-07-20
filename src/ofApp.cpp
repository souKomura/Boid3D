#include "ofApp.h"
#include "ofxGui.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(false);
    ofSetFrameRate(30);
    
    //values of coordination system's rotation
    angleAroundX = -15;
    angleAroundY = 60;
    angleAroundZ = 0;
    angleSpeedY = 0.3;
    resetNodeOrientation();
    
    //rest boid system
    Bird::restrictRange = min(ofGetWidth(), ofGetHeight()) / 3.0f; // => 250
    int num = 700;
    birds.resize(num);
    for(int i=0; i<birds.size(); i++){
        birds[i] = Bird();
    }
    
    //shape of bird
    Bird::shape = ofMesh::cone(Bird::r, Bird::r*3);
    
    //gui parameters
    gui.setup("controls");
    
    rangeControls.setName("look up ranges");
    rangeControls.add(sRparam);
    rangeControls.add(aRparam);
    rangeControls.add(cRparam);
    gui.add(rangeControls);
    
    weightControls.setName("weight of force");
    weightControls.add(sKparam);
    weightControls.add(aKparam);
    weightControls.add(cKparam);
    gui.add(weightControls);
    
    sRparam.addListener(this, &ofApp::sepListener);
    aRparam.addListener(this, &ofApp::aliListener);
    cRparam.addListener(this, &ofApp::cohListener);
    
    sKparam.addListener(this, &ofApp::sepkListener);
    aKparam.addListener(this, &ofApp::alikListener);
    cKparam.addListener(this, &ofApp::cohkListener);
}

//--------------------------------------------------------------
void ofApp::resetNodeOrientation(){
    glm::quat qAroundX = glm::angleAxis(ofDegToRad(angleAroundX), glm::vec3(1, 0, 0));
    glm::quat qAroundY = glm::angleAxis(ofDegToRad(angleAroundY), glm::vec3(0, 1, 0));
    glm::quat qAroundZ = glm::angleAxis(ofDegToRad(angleAroundZ), glm::vec3(0, 0, 1));
    
    worldNode.setOrientation(qAroundX * qAroundY * qAroundZ);
}

//--------------------------------------------------------------
void ofApp::update(){
    angleAroundY = fmod(angleAroundY + angleSpeedY, 360);
    resetNodeOrientation();
    
    for(int i=0; i<birds.size(); i++){
        birds[i].update(birds);
    }
    
    for(int i=0; i<birds.size(); i++){
        birds[i].move();
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(60, 60, 60), ofColor(10, 10, 10));
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
    
    //rotate coordinate system
    worldNode.transformGL();
    
    //show Axis
    ofDrawAxis(200);
//    ofSetColor(100, 200, 100, 10);
//    ofDrawSphere(Bird::restrictRange);
    
    //show birds
    for(int i=0; i<birds.size(); i++){
        birds[i].draw();
    }
    
    worldNode.restoreTransformGL();
    ofPopMatrix();
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::sepListener(float &v){ Bird::sepRange = v; }

void ofApp::aliListener(float &v){ Bird::aliRange = v; }

void ofApp::cohListener(float &v){ Bird::cohRange = v; }

void ofApp::sepkListener(float & v){ Bird::sepK = v; }

void ofApp::alikListener(float & v){ Bird::aliK = v; }

void ofApp::cohkListener(float & v){ Bird::cohK = v; }

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for(int i=0; i<birds.size(); i++){
        birds[i] = Bird();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
