#pragma once
#include "Play.h"
#include "RigidBody.h"

class Asteroid : public RigidBody
{
private:

	Point2D position = { Play::RandomRollRange(-200, 200),Play::RandomRollRange(-200, 200) };

public:
	Asteroid() { position; };

	void DrawObject();

	void SpeedObject();

	void AsteroidBoundries(); // could have placed this under game physics, oh well

	void PhysicsGameUpdate();

	int counter = 0;

};

