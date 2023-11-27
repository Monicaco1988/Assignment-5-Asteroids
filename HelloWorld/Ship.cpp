#include "Ship.h"
#include "Play.h"
#include "RigidBody.h"

void ShipHandle()
{

};

void ShipMovement()
{
 Ship ship = Ship();
	if (Play::KeyPressed(VK_UP)) {};
		ship.velocity += {1,1};
	//virtual används när jag vill overloada (override) en function som har samma namn tex Draw() eller liknande
};

void DrawObject();
