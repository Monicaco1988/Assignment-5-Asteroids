#include "Rigidbody.h"

// Save the current position in case we need to go back
//obj.oldPos = obj.pos;
//obj.oldRot = obj.rotation;

// Velocity

void SpeedObject(RigidBody rigidBody, int speed)
{

	rigidBody.velocity.x = speed * sin(rigidBody.rotation) * timeStep;
	rigidBody.velocity.y = speed * cos(rigidBody.rotation) * timeStep;
};
// virtual methods collisions and physics

void Collision()
{
};

void PhysicsGameUpdate(RigidBody rigidBody, int speed)
{
	rigidBody.velocity += rigidBody.acceleration;
	rigidBody.position += rigidBody.velocity;
	rigidBody.rotation += speed;
};

// pure virtual function for drawing, use drawspriterotaded

void Draw()
{
};