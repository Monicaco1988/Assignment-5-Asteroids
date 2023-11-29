#pragma once
#include "Play.h"
#include "RigidBody.h"

class Asteroid : public RigidBody
{
private:

	Point2D position = {100,100};

public:
	Asteroid() { position; };

	void DrawObject();

};

