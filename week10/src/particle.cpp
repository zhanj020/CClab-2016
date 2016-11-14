#include "particle.h"
// using the constructor to initialize all the variables
Particle::Particle(ofVec2f position) {
	mPosition = position;
	mVelocity = ofVec2f(ofRandom(-1.f, 1.f), ofRandom(-1.f, 1.f));
	mAcceleration = ofVec2f(0);
	center = ofVec2f(500, 350);
	mLifeSpan = 255.f;

}
//-------------------------------------
void Particle::resetForces()
{
	// reset the acceleration
	mAcceleration *= 0;
}
//-------------------------------------
void Particle::applyForce(ofVec2f force)
{
	// adding for to acceleration
	mAcceleration = centerforce / 3000;
}
//-------------------------------------
void Particle::update(float multiplier)
{
	// apply accelearation to velocity
	mVelocity += mAcceleration;
	mPosition += mVelocity * multiplier;

	// decreasing the particle life
	if (mLifeSpan > 0) {
		mLifeSpan -= 2.f;
	}

	centerforce = ofVec2f(500 - mPosition.x, 350 - mPosition.y);
}
//-------------------------------------
void Particle::draw()
{
	if (mLifeSpan > 100) {
		// new born partilce will be brighter
		ofSetColor(ofMap(mVelocity.x, 0, 3, 200, 255), ofMap(mVelocity.x, 0, 3, 0, 250), 0);
	}
	else if (mLifeSpan <= 100) {
		// do some sparkle!
		ofSetColor(ofMap(mVelocity.x, -3, 0, 255, 200), ofMap(mVelocity.x, -3, 0, 250, 0), 0);
	};

	// closer particle is smaller
	ofDrawCircle(mPosition, 3.f * ofMap(mLifeSpan, 0, 255.f, 0, 1.f));

}
