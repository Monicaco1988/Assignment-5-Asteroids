#pragma once
#include "Play.h"

//frameCounter in main Globally
//int timeStepOne;


class RigidBody
{
//private:
public:
	//poisition
	int x = 100;
	int y = 100;

	int speed = 1;

//public:
	// position
	Point2D position;

	Vector2D velocity;

	// acceleration
	Vector2D acceleration;

	// rotation in radians
	float rotation;

	// radius of object
	int radius;

	
	RigidBody()	 // constructor for rigidbody.acceleration
	{
		position = { x, y };
		velocity = { 0.0f, 0.0f };
		acceleration = { 0.0f, 0.0f };
		rotation = { 0.0f }; // I radianer
		radius = {10};
	}

	~RigidBody()
	{
		//delete rigidBody;
	};

	virtual void DrawObject() = 0; //Pure virtual function

	virtual void SpeedObject();

	virtual void Collision(RigidBody *rigidbody);

	virtual void PhysicsGameUpdate();

};


