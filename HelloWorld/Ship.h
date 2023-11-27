#pragma once
#include "Play.h"
#include "RigidBody.h"

class Ship : public RigidBody // OBS det ska vara colon : inte semicolon ; !!!!
{
private:
	//nothing here
public:

	//void DrawSpriteRotated()



	void DrawObject()
	{
		Ship ship = Ship(); 
		Play::DrawSpriteRotated("Ship", { ship.velocity }, 0, 1.0f, 0.5f);
	};

};


void ShipMovement();