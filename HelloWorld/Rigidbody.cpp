#include "Rigidbody.h"
#include "Play.h"

// virtual methods collisions and physics

void RigidBody::SpeedObject()
{
	velocity.x = speed * sin(rotation);
	velocity.y = speed * cos(rotation); 
}

void RigidBody::Collision(RigidBody* rigidbody)  // not really wordking
{

	int xdiff = this->position.x - rigidbody->position.x; // looping over all rigidbody objects and comparing to the "ship rigidbody"

	int ydiff = this->position.y - rigidbody->position.y;

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

void RigidBody::PhysicsGameUpdate(float elapsedTime)
{
	velocity += acceleration;
	position += velocity;
	rotation += speed;
};
