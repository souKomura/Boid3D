#include "Bird.hpp"

//--------------------------------------------------------------
Bird::Bird(){
    pos = unit() * ofRandom(restrictRange);
    vel = unit() * ofRandom(3);
}

//--------------------------------------------------------------
void Bird::update(const vector<Bird> &birds){
    
}

//--------------------------------------------------------------
void Bird::move(){
    vel += -pos * 0.000001;
    vel.limit(1);
    pos += vel;
}

//--------------------------------------------------------------
void Bird::draw(){
    ofPushMatrix();
    
    ofTranslate(pos);
    
    shape.draw();
    
    ofPopMatrix();
}


//--------------------------------------------------------------
void Bird::setOrientation(){
    //compute rotation to look at toward future position
    
    glm::vec3 start = {0, 1, 0}; //front of shape
    glm::vec3 dest = glm::normalize(glm::vec3(vel));
    
    float cosTheta = glm::dot(start, dest);
    glm::vec3 rotationAxis;
    
    rotationAxis = cross(start, dest);
    //SEE WEBSITE
}

//--------------------------------------------------------------
ofVec3f Bird::unit(){
    float _theta = ofRandom(TWO_PI);
    float _phi = ofRandom(TWO_PI);
    float x = glm::sin(_theta) * glm::cos(_phi);
    float y = glm::sin(_theta) * glm::sin(_phi);
    float z = glm::cos(_theta);
    return ofVec3f(x, y, z);
}
