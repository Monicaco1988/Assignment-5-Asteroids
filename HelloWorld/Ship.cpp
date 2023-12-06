#include "Ship.h"
#include "Play.h"
#include "RigidBody.h"
#include "Asteroid.h"

void Ship::ShipBoundries()
{
	switch (position.x < 0)
	{
	case 1:
		position = { position.x + 640 , position.y };
	};
	switch (position.x > 640)
	{
	case 1:
		position = { 0 , position.y };
	};
	if (position.y < 0)
	{
		position = { position.x , position.y + 360 };
	};
	if (position.y > 360)
	{
		position = { position.x , 0 };
	};
};

void Ship::PhysicsGameUpdate(float elapsedTime)
{
	if (Play::KeyDown(VK_SPACE))
	{
		acceleration.x += shipThrust * sin(rotation) * elapsedTime;
		acceleration.y += -shipThrust * cos(rotation) * elapsedTime;
	};                                                                                   
	if (Play::KeyDown(VK_LEFT))
	{
		rotation -= 0.1;
	};
	if (Play::KeyDown(VK_RIGHT))
	{
		rotation += 0.1;
	};

	// these physics should be only in rigidbody

	velocity += acceleration;
	position += velocity;

	position += {0, 0};

	acceleration.x = 0;
	acceleration.y = 0;

	ShipBoundries();

	//virtual används när jag vill overloada (override) en function som har samma namn tex Draw() eller liknande
};

void Ship::DrawObject()
{
	Play::DrawSpriteRotated("Ship", { position }, radius, rotation, 0.5f, 1.0f); // what is int frame? maybe to frame it in??
};

void Ship::Collision(RigidBody* rigidbody)
{
		int xdiff = position.x - rigidbody[1].position.x; // looping over all rigidbody objects and comparing to the "ship rigidbody"

		int ydiff = position.y - rigidbody[1].position.y;

		int radii = radius + radius;

		// game progammers don't do square root!

		if ((xdiff * xdiff) + (ydiff * ydiff) < radius * radius)
		{
			position.x = 320;
			position.y = 190;
			velocity = { 0,0 };
			rotation = { 0 };
			//Sleep(1000);
		};

};
