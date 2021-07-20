#include "ofMain.h"
#include "ofApp.h"

float Bird::r = 3;
ofMesh Bird::shape;

float Bird::sepRange = 12;
float Bird::aliRange = 70;
float Bird::cohRange = 125;
float Bird::sepK = 0.8;
float Bird::aliK = 0.6;
float Bird::cohK = 0.08;

float Bird::restrictRange;

//========================================================================
int main( ){
	ofSetupOpenGL(768,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
