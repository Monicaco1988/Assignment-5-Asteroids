#pragma once
#include "Play.h"
#include "RigidBody.h"

class Asteroid : public RigidBody
{
private:

	Point2D position = {200,200};

public:
	Asteroid() { position; };

	void DrawObject();

	void SpeedObject();

	//void Collision();

	void AsteroidBoundries();

	void PhysicsGameUpdate();

};

