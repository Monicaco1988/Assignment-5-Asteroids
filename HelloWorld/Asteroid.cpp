#include "Asteroid.h"
#include "Play.h"
//int Play::RandomRollRange(0, 5)

void Asteroid::DrawObject()
{
	Play::DrawSpriteRotated("Asteroid", { position.x,position.y }, 0, rotation* 0.01, 1.0f, 1.0f); // randomize scale and rotation too
}
void Asteroid::PhysicsGameUpdate()
{
	velocity += acceleration;
	position += velocity;
	rotation += speed* Play::RandomRollRange(0, 1);

	AsteroidBoundries();
}

void Asteroid::SpeedObject()
{
	//velocity.x = speed * sin(rotation); //* timeStep;		Why did i even have this one here? only needed once in RigidBody parent class
	//velocity.y = speed * cos(rotation); //* Play::timeStep;

	position += {Play::RandomRollRange(0, 2), Play::RandomRollRange(0, 2)}; // need to randomize these values for every Asteroid

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