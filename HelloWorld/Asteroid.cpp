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
