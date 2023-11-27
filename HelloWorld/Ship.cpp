#include "Ship.h"
#include "Play.h"
#include "RigidBody.h"

void ShipHandle()
{

};


void ShipMovement(RigidBody rigidBody)
{
	if (Play::KeyPressed(VK_UP))
		rigidBody.velocity += {1,1};
	//virtual används när jag vill overloada (override) en function som har samma namn tex Draw() eller liknande
};

void DrawShip(RigidBody rigidBody)
{
	Play::DrawSpriteRotated("Ship", { rigidBody.position }, 0, 1.0f, 0.5f);
};
