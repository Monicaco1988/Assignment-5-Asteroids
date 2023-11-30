#include "Rigidbody.h"
#include "Play.h"

// virtual methods collisions and physics

void RigidBody::SpeedObject()
{
	velocity.x = speed * sin(rotation); //* timeStep;
	velocity.y = speed * cos(rotation); //* Play::timeStep;
};

bool RigidBody::Collision(RigidBody *rigidbody)
{
	//if ()
	int xDiff = this->position.x - rigidbody[1].position.x;

	int yDiff = this->position.y - rigidbody[1].position.y;

	int radii = radius + radius;

	// Game progammers don't do square root!
	return((xDiff * xDiff) + (yDiff * yDiff) < radii * radii);
};

void RigidBody::PhysicsGameUpdate()
{
	velocity += acceleration;
	position += velocity;
	rotation += speed;
};
