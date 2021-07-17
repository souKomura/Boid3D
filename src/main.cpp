#include "ofMain.h"
#include "ofApp.h"

float Bird::r = 2;
ofMesh Bird::shape;

float Bird::sepRange = 20;
float Bird::aliRange = 40;
float Bird::cohRange = 40;

float Bird::restrictRange;

//========================================================================
int main( ){
	ofSetupOpenGL(768,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
