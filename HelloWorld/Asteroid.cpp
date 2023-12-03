#include "Asteroid.h"
#include "Play.h"

void Asteroid::DrawObject()
{
	Play::DrawSpriteRotated("Asteroid", { position }, radius, rotation*0.01, scale*0.1, 1.0f); // randomize scale and rotation too
}
void Asteroid::PhysicsGameUpdate()
{
	position += velocity;
	rotation += speed;

	AsteroidBoundries();
}

void Asteroid::SpeedObject()
{
	position += {1, 1}; // need to randomize these values for every Asteroid
};

void Asteroid::AsteroidBoundries()
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

void Asteroid::Collision(RigidBody* rigidbody)
{
		int xdiff = position.x - rigidbody[0].position.x; // looping over all rigidbody objects and comparing to the "ship rigidbody"

		int ydiff = position.y - rigidbody[0].position.y;

		int radii = radius + radius;

		// game progammers don't do square root!

		if ((xdiff * xdiff) + (ydiff * ydiff) < radius * radius)
		{
			rigidbody[0].position.x = 320;
			rigidbody[0].position.y = 190;
			rigidbody[0].velocity = { 0,0 };
			rigidbody[0].rotation = { 0 };
			//Sleep(1000);
		};

};