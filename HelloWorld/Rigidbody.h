#pragma once
#include "Play.h"

//frameCounter in main Globally
//int timeStepOne;


class RigidBody
{

private:
	//position

	int x = 640 / 2;
	int y = 360 / 2;

protected:

	Point2D randomPosition = { Play::RandomRollRange(-200, 200),Play::RandomRollRange(-200, 200) };
	Vector2D velocityRandom = { float(Play::RandomRollRange(-2, 2)),float(Play::RandomRollRange(-2, 2)) };
	float rotationRandom = { float(Play::RandomRollRange(-1, 1)) };
	int speedRandom ={ int(Play::RandomRollRange(-1, 1)) };

public:
	//speed
	int speed;

	// position
	Point2D position; // jag skapar ju en unik varje gång! fyi

	Vector2D velocity;

	// acceleration
	Vector2D acceleration;

	// rotation in radians
	float rotation;

	// radius of object
	int radius;

	// Scale
	float scale;

	//shipThrust

	int shipThrust;
	
	RigidBody()	 // constructor for rigidbody
	{
		position = { x,y };

		velocity = { 0.0f, 0.0f };
		
		acceleration = { 0.0f, 0.0f };

		rotation = { 0.0f }; // I radianer

		radius = {10};

		speed = 1;

		scale = { float(Play::RandomRollRange(5, 15)) };

		shipThrust = 5;
	}

	~RigidBody()
	{
		//delete rigidBody;
	};

	virtual void DrawObject() = 0; //Pure virtual function
	virtual void SpeedObject();
	virtual void Collision(RigidBody *rigidbody);
	virtual void PhysicsGameUpdate(float elapsedTime);

};


