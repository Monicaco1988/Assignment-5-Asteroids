#include "Rigidbody.h"
#include "Play.h"

// virtual methods collisions and physics

void RigidBody::SpeedObject()
{
	velocity.x = speed * sin(rotation); //* timeStep;
	velocity.y = speed * cos(rotation); //* timeStep;
}

void RigidBody::Collision(RigidBody* rigidbody)
{

		int xdiff = position.x - rigidbody[1].position.x; // looping over all rigidbody objects and comparing to the "ship rigidbody"

		int ydiff = position.y - rigidbody[1].position.y;

		int radii = radius + radius;

		// game progammers don't do square root!

		if ((xdiff * xdiff) + (ydiff * ydiff) < radius * radius)
		{
			Sleep(1000);
		};
};

void RigidBody::PhysicsGameUpdate(float elapsedTime)
{
	velocity += acceleration;
	position += velocity;
	rotation += speed;
};
