#pragma once
#include "Play.h"
#include "RigidBody.h"


class Ship : public RigidBody // OBS det ska vara colon : inte semicolon ; !!!!
{
public:
	Ship() {}; // Initieringslista f�r masterclassens initcierare // hur �ndrar jag x och y startpositioner? eller andra positioner f�r den delen

	void DrawObject();

	void Collision(RigidBody* rigidbody);

	void PhysicsGameUpdate(float elapsedTime);

	void ShipBoundries();

};