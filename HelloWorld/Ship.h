#pragma once
#include "Play.h"
#include "RigidBody.h"


class Ship : public RigidBody // OBS det ska vara colon : inte semicolon ; !!!!
{
private:
	double shipThrust = 0.1;

	Point2D position = { 640 / 2,360 / 2 };

public:
	Ship() { position; }; // Initieringslista för masterclassens initcierare // hur ändrar jag x och y startpositioner? eller andra positioner för den delen

	void DrawObject();

	void Collision(RigidBody* rigidbody);

	void PhysicsGameUpdate();

	void ShipBoundries();


};

//void ShipMovement();