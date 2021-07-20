#pragma once
#include "ofMain.h"
#include "Bird.hpp"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
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
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //coordination Axis will be slightly leaned by values bellow.
    ofEasyCam cam;
    float angleAroundX;
    float angleAroundY;
    float angleAroundZ;
    float angleSpeedY;
    ofNode worldNode;
    void resetNodeOrientation();
    
    //boid
    vector<Bird> birds;
    void resetParameters();
    
    //GUI related parameter ----------------
    ofxPanel gui;
    ofxButton resetButton;
    
    ofParameterGroup rangeControls;
    ofParameter<float> sRparam = ofParameter<float>("separate", 0, 0, 20);
    ofParameter<float> aRparam = ofParameter<float>("align", 0, 0,200);
    ofParameter<float> cRparam = ofParameter<float>("cohesion", 0, 0, 500);
    
    ofParameterGroup weightControls;
    ofParameter<float> sKparam = ofParameter<float>("separate", 0, 0, 2);
    ofParameter<float> aKparam = ofParameter<float>("align", 0, 0,2);
    ofParameter<float> cKparam = ofParameter<float>("cohesion", 0, 0, 2);
    
    void sepListener(float & v);
    void aliListener(float & v);
    void cohListener(float & v);
    
    void sepkListener(float & v);
    void alikListener(float & v);
    void cohkListener(float & v);
    
    //----------------
    
};
