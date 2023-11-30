#include "Rigidbody.h"
#include "Play.h"

// virtual methods collisions and physics

void RigidBody::SpeedObject()
{
	velocity.x = speed * sin(rotation); //* timeStep;
	velocity.y = speed * cos(rotation); //* Play::timeStep;
}

void RigidBody::Collision(RigidBody* rigidbody)
{
	//for (int i = 1; i <= 5; i++) // make the asteroid amount global
	//{
	//	int xdiff = rigidbody[i].position.x - position.x; // looping over all rigidbody objects and comparing to the "ship rigidbody"

	//	int ydiff = rigidbody[i].position.y - position.y;

	//	int radii = radius + radius;

	//	// game progammers don't do square root!

	//	if ((xdiff * xdiff) + (ydiff * ydiff) < radius * radius)
	//	{
	//		//Sleep(1000);
	//		position.x = 640 / 2;
	//		position.y = 360 / 2;

	//	};
	//};
};

void RigidBody::PhysicsGameUpdate()
{
	velocity += acceleration;
	position += velocity;
	rotation += speed;
};
