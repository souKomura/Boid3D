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
    
    float angleAroundX;
    float angleAroundY;
    float angleAroundZ;
    float angleSpeedY;
    
    ofNode worldNode;
    void resetNodeOrientation();
    
    vector<Bird> birds;
    
    ofxPanel gui;
    
    ofParameterGroup rangeControls;
    ofParameter<float> sRparam = ofParameter<float>("separate", Bird::sepRange, 0, 500);
    ofParameter<float> aRparam = ofParameter<float>("align", Bird::aliRange, 0,500);
    ofParameter<float> cRparam = ofParameter<float>("cohesion", Bird::cohRange, 0, 500);
    
    ofParameterGroup weightControls;
    ofParameter<float> sKparam = ofParameter<float>("separate", Bird::sepK, 0, 2);
    ofParameter<float> aKparam = ofParameter<float>("align", Bird::aliK, 0,2);
    ofParameter<float> cKparam = ofParameter<float>("cohesion", Bird::cohK, 0, 2);
    
    void sepListener(float & v);
    void aliListener(float & v);
    void cohListener(float & v);
    
    void sepkListener(float & v);
    void alikListener(float & v);
    void cohkListener(float & v);
    
};
