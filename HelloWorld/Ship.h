#pragma once
#include "Play.h"
#include "RigidBody.h"


class Ship : public RigidBody // OBS det ska vara colon : inte semicolon ; !!!!
{
public:
	Ship() {}; // Initieringslista för masterclassens initcierare // hur ändrar jag x och y startpositioner? eller andra positioner för den delen

	void DrawObject();

	void Collision(RigidBody* rigidbody);

	void PhysicsGameUpdate(float elapsedTime);

	void ShipBoundries();

};