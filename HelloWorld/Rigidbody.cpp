#include "Rigidbody.h"
#include "Play.h"

// virtual methods collisions and physics

void RigidBody::SpeedObject()
{
	velocity.x = speed * sin(rotation); //* timeStep;
	velocity.y = speed * cos(rotation); //* Play::timeStep;
};

void RigidBody::Collision()
{

};

void RigidBody::PhysicsGameUpdate()
{
	velocity += acceleration;
	position += velocity;
	rotation += speed;
};
