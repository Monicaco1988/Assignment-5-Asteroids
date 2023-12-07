#include "Asteroid.h"
#include "Play.h"

void Asteroid::DrawObject()
{
	Play::DrawSpriteRotated("Asteroid", { randomPosition }, radius, rotationRandom * 0.09, scale * 0.1, 1.0f); // randomize scale and rotation too
}
void Asteroid::PhysicsGameUpdate(float elapsedTime)
{
	randomPosition += velocityRandom;
	rotationRandom += speedRandom;

	AsteroidBoundries();
}

void Asteroid::SpeedObject()
{
	randomPosition += {1, 1}; // need to randomize these values for every Asteroid
};

void Asteroid::AsteroidBoundries()
{
	switch (randomPosition.x < 0)
	{
	case 1:
		randomPosition = {randomPosition.x + 640 , randomPosition.y };
	};
	switch (randomPosition.x > 640)
	{
	case 1:
		randomPosition = { 0 , position.y };
	};
	if (randomPosition.y < 0)
	{
		randomPosition = { position.x , position.y + 360 };
	};
	if (randomPosition.y > 360)
	{
		randomPosition = { position.x , 0 };
	};
};

void Asteroid::Collision(RigidBody* rigidbody) 
{
	int xdiff = randomPosition.x - rigidbody->position.x; // looping over all rigidbody objects and comparing to the "ship rigidbody"

	int ydiff = randomPosition.y - rigidbody->position.y;

	int radii = radius + radius;

	// game progammers don't do square root!

	if ((xdiff * xdiff) + (ydiff * ydiff) < radius * radius)
	{
		rigidbody->position.x = 320;
		rigidbody->position.y = 190;
		rigidbody->velocity = { 0,0 };
		rigidbody->rotation = { 0 };
	};
};