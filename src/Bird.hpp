#include "ofMain.h"

class Bird{
public:
    Bird();
    
    void update(vector<Bird> & birds);
    void move();
    void draw();
    
    ofVec3f pos;
    ofVec3f vel;
    
    static float r;
    static ofMesh shape;
    
    static float sepRange;// = 20;
    static float aliRange;// = 40;
    static float cohRange;// = 40;
    
    static float sepK;
    static float aliK;
    static float cohK;
    
    static float restrictRange;

private:
    float maxSpeed = 6;
    float minSpeed = 1;
    float maxFrc = 0.2;
    
    ofNode orientationNode;
    
    void setOrientation();
    ofVec3f unit();
};
