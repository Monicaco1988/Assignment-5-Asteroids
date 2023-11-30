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
	int xdiff = rigidbody[0].position.x - rigidbody[1].position.x;

	int ydiff = rigidbody[0].position.x - rigidbody[1].position.y;

	int radii = radius + radius;

	// game progammers don't do square root!

	if ((xdiff * xdiff) + (ydiff * ydiff) < radius * radius)
	{
		rigidbody[0].position.x = 300;
	};
};

void RigidBody::PhysicsGameUpdate()
{
	velocity += acceleration;
	position += velocity;
	rotation += speed;
};
