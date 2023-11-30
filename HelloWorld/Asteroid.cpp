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
	//if ()
	int xDiff = rigidbody[0].position.x - rigidbody[1].position.x;

	int yDiff = rigidbody[0].position.y - rigidbody[1].position.y;

	int radii = radius + radius;

	// Game progammers don't do square root!
	((xDiff * xDiff) + (yDiff * yDiff) < radii * radii);

	if ((xDiff * xDiff) + (yDiff * yDiff) < 1000)
	{
		position.x = 0;
	};
};