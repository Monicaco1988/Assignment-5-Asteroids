#pragma once
#include "Play.h"
#include "RigidBody.h"



class Ship : public RigidBody // OBS det ska vara colon : inte semicolon ; !!!!
{
private:
	//nothing here
public:
	Ship() 
	{
		position = { x, y }; // how do i inherit this though????????????????????????????????? Mr.Chan))))
		velocity = { 0.0f, 0.0f };
		acceleration = { 0.0f, 0.0f };
		rotation = { 0.0f }; // I radianer
		radius = { 0 };
	};
	//void DrawSpriteRotated()

	void DrawObject()
	{
		Play::DrawSpriteRotated("Ship", { position }, 1, rotation, 0.5f);
	};

	void ShipMovement()
	{

		
		if (Play::KeyPressed(VK_UP))
		{
			position += {1,1};

		};
		if (Play::KeyPressed(VK_LEFT))
		{
			rotation -= 0.5;
		};
		if (Play::KeyPressed(VK_RIGHT))
		{
			rotation += 0.5;
		};

		velocity += acceleration;
		position += velocity;

		velocity.x = 1 * sin(rotation);
		velocity.y = 1 * cos(rotation);

		acceleration.x = 0;
		acceleration.y = 0;

		//virtual används när jag vill overloada (override) en function som har samma namn tex Draw() eller liknande
	};
};

//void ShipMovement();