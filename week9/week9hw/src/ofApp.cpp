#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	synthHit.load("Blade.mp3");

	mCircleRadius = 150.f;
	ofSetCircleResolution(100.f);  /*make the circle smoother*/
	mPos = ofVec2f(ofGetWindowWidth()* 0.5, ofGetWindowHeight() * 0.5);

	synthHit.play();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){


	ofSetBackgroundColor(0);


	
	ofSetColor(255.f, 153.f, 0.f);
	ofDrawCircle(mPos, mCircleRadius);


	ofTranslate(ofGetWindowWidth()* 0.5-90, ofGetWindowHeight() * 0.5-90);
	ofSetColor(0);
	ofDrawRectangle(ofRandom(50), ofRandom(50), mCircleRadius, mCircleRadius);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
		case 'a':
			synthHit.play();

		break;
		
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	switch (key) {
	case 's':
		synthHit.stop();
		ofDrawRectangle(mPos, 150, 150);
		break;
	}
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
