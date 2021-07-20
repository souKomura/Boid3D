#include "Bird.hpp"

//--------------------------------------------------------------
Bird::Bird(){
    pos = unit() * ofRandom(restrictRange);
    vel = unit() * ofRandom(1);
}

//--------------------------------------------------------------
void Bird::update(vector<Bird> &birds){
    
    ofVec3f posSum(0,0,0);
    ofVec3f velSum(0,0,0);
    ofVec3f posDiffSum(0,0,0);
    
    int cohCnt = 0;
    int aliCnt = 0;
    int sepCnt = 0;
    
    // 1. look up others to calculate forces
    for(int i=0; i<birds.size(); i++){
        Bird &other = birds[i];
        if(this == &other) continue;
        
        float d = pos.distance(other.pos);
        
        if(d < sepRange){
            posDiffSum += ((pos - other.pos) / d).getNormalized();
            sepCnt++;
        }
        
        if(d < aliRange){
            velSum += other.vel;
            aliCnt++;
        }
        
        if(d < cohRange){
            posSum += other.pos;
            cohCnt++;
        }
        
    }
    
    //2. compute forces
    ofVec3f frc(0, 0, 0);
    ofVec3f sepF, aliF, cohF;
    
    if(sepCnt > 0){
        sepF = posDiffSum.normalize() * maxSpeed - vel;
        sepF.limit(maxFrc);
    }
    
    if(aliCnt > 0){
        aliF = velSum.normalize() * maxSpeed - vel;
        aliF.limit(maxFrc);
    }
    
    if(cohCnt > 0){
        cohF = (posSum / cohCnt - pos).normalize() * maxSpeed - vel;
        cohF.limit(maxFrc);
    }
    
    frc += sepF*sepK + aliF*aliK + cohF * cohK;
    
    //3.stay in restricted Range
    ofVec3f centre = ofVec3f(0, 0, 0); //not typo
    ofVec3f diff = centre - pos;
    if(diff.x * diff.x + diff.y + diff.y > restrictRange*restrictRange){
        ofVec3f toCentreF = ((centre - pos).normalize() * maxSpeed - vel);
        toCentreF.limit(maxFrc);
        frc += toCentreF * 1;
    }
    
    vel += frc;
    
    vel.limit(maxSpeed);
    if(vel.length() < minSpeed){
        vel.normalize();
        vel *= minSpeed;
    }
    
}

//--------------------------------------------------------------
void Bird::move(){
    pos += vel;
}

//--------------------------------------------------------------
void Bird::draw(){
    ofPushMatrix();
    ofTranslate(pos);
    
    setOrientation();
    orientationNode.transformGL();
    
    shape.draw();
    
    orientationNode.restoreTransformGL();
    ofPopMatrix();
}


//--------------------------------------------------------------
void Bird::setOrientation(){
    //compute rotation to look at toward future position
    
    glm::vec3 start = {0, -1, 0}; //front of shape
    glm::vec3 dest = glm::normalize(glm::vec3(vel));
    
    float cosTheta = glm::dot(start, dest);
    glm::vec3 rotationAxis;
    
    rotationAxis = cross(start, dest);
    
    float w2 = glm::sqrt((1 + cosTheta)*2);
    float sinHalfTheta  = sqrt(1 - pow(w2/2, 2));
    
    glm::quat q(w2 * 0.5f, rotationAxis.x * sinHalfTheta, rotationAxis.y * sinHalfTheta, rotationAxis.z * sinHalfTheta);
    
    orientationNode.setOrientation(q);
}

//--------------------------------------------------------------
ofVec3f Bird::unit(){
    float _theta = ofRandom(TWO_PI);
    float _phi = ofRandom(TWO_PI);
    float x = glm::sin(_theta) * glm::cos(_phi);
    float y = glm::sin(_theta) * glm::sin(_phi);
    float z = glm::sin(_phi);
    return ofVec3f(x, y, z);
}
