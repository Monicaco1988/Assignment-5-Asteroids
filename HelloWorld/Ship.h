#pragma once
#include "Play.h"
#include "RigidBody.h"


class Ship : public RigidBody // OBS det ska vara colon : inte semicolon ; !!!!
{
private:
	double shipThrust = 0.1;

	Point2D position = {200,300};

public:
	Ship() { position; }; // Initieringslista f�r masterclassens initcierare // hur �ndrar jag x och y startpositioner? eller andra positioner f�r den delen

	void DrawObject();

	void PhysicsGameUpdate();

	void ShipBoundries();


};

//void ShipMovement();