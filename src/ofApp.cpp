#include "ofApp.h"

float radius;
ofPoint pt;

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowShape(1280, 960);
    
    cam.setup(640, 480);
    
    finder.setup("haarcascade_frontalface_default.xml");

}

//--------------------------------------------------------------
void ofApp::update(){
    
    cam.update();
    finder.findHaarObjects(cam.getPixels());
    if(finder.blobs.size()>0) {
        pt = finder.blobs[0].boundingRect.getCenter();
    }
    
    float dist = ofDist(300, 300, pt.x, pt.y);
    
    if(dist < 100)
    {
        radius ++;
        if(radius > 100)
        {
            radius = 100;
        }
    }
    
    else
    {
        radius --;
        if(radius < 0)
        {
            radius = 0;
        }
    }
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushMatrix();
    ofScale(2, 2);
    ofSetColor(255, 100);
    cam.draw(0, 0);
    
    ofSetColor(100);
    ofDrawCircle(200, 200, radius);
    ofPopMatrix();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
