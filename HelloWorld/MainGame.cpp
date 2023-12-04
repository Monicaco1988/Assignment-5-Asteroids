#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "Rigidbody.h"
#include "Asteroid.h"
#include "Ship.h"

int DISPLAY_WIDTH = 640;
int DISPLAY_HEIGHT = 360;
int DISPLAY_SCALE = 2;

int asteroidAmount = 15;

const int ShipAmount = 1;

RigidBody** rigidbody;

// The entry point for a PlayBuffer program
void MainGameEntry( PLAY_IGNORE_COMMAND_LINE )
{
	Play::CreateManager( DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE );

	rigidbody = nullptr;

	rigidbody = new RigidBody * [asteroidAmount+ShipAmount]; // allocating space in RigidBody in memory Only delete what you allocate with new.
	rigidbody[0] = new Ship(); // int the allocated dynamic memory the first space is made for the array

	for (int i = 1; i <= asteroidAmount; i++)
	{
		rigidbody[i] = new Asteroid();
	}
	//delete rigidBody;
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate( float elapsedTime )
{
	Play::ClearDrawingBuffer( Play::cBlack );

	//Ship [0]

	rigidbody[0]->PhysicsGameUpdate();

	rigidbody[0]->DrawObject(); // using the arrow points to the function of the specific place in memory

	Play::CentreSpriteOrigin("Ship"); // Nice

	//Asteroids [i] except [0]

	for (int i = 1; i <= asteroidAmount; i++)
	{
		rigidbody[i]->DrawObject();
		rigidbody[i]->SpeedObject();
		rigidbody[i]->PhysicsGameUpdate();
		rigidbody[0]->Collision(rigidbody[i]);
	};
	
	Play::CentreSpriteOrigin("Asteroid");
	
	Play::PresentDrawingBuffer();

	return Play::KeyDown( VK_ESCAPE );
}

// Gets called once when the player quits the game 
int MainGameExit( void )
{

	for(int i=0; i< asteroidAmount+ShipAmount; i++)
	delete rigidbody[i];

	delete rigidbody;

	Play::DestroyManager();
	return PLAY_OK;
}



