#pragma once
#include "Play.h"
#include "RigidBody.h"


class Ship : public RigidBody // OBS det ska vara colon : inte semicolon ; !!!!
{
private:
	double shipThrust = 5;

	Point2D position = { 640 / 2,360 / 2 };

	int radius = 10;

public:
	Ship() { position, radius; }; // Initieringslista f�r masterclassens initcierare // hur �ndrar jag x och y startpositioner? eller andra positioner f�r den delen

	void DrawObject();

	void Collision(RigidBody* rigidbody);

	void PhysicsGameUpdate(float elapsedTime);

	void ShipBoundries();

};