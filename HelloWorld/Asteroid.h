#pragma once
#include "Play.h"
#include "RigidBody.h"

class Asteroid : public RigidBody
{
public:

	Asteroid() {};

	void DrawObject();

	void SpeedObject();

	void AsteroidBoundries();

	void Collision(RigidBody* rigidbody);

	void PhysicsGameUpdate(float elapsedTime);

};

