#include "Ship.h"
#include "Play.h"
#include "RigidBody.h"

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

void Ship::PhysicsGameUpdate()
{
	if (Play::KeyDown(VK_SPACE))
	{
		acceleration.x += shipThrust * sin(rotation);
		acceleration.y += -shipThrust * cos(rotation);
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
	Play::DrawSpriteRotated("Ship", { position }, 1, rotation, 0.5f, 1.0f);
};

