#include "ofMain.h"
#include "ofApp.h"

float Bird::r = 3;
ofMesh Bird::shape;

float Bird::sepRange;
float Bird::aliRange;
float Bird::cohRange;
float Bird::sepK;
float Bird::aliK;
float Bird::cohK;

float Bird::sepAng = PI/4;
float Bird::aliAng = PI/6;
float Bird::cohAng = PI/4;

float Bird::sepCos, Bird::aliCos, Bird::cohCos;

float Bird::restrictRange;

//========================================================================
int main( ){
	ofSetupOpenGL(1000,1000,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}
