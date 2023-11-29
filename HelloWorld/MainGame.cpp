#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "Rigidbody.h"
#include "Asteroid.h"
#include "Ship.h"

int DISPLAY_WIDTH = 640;
int DISPLAY_HEIGHT = 360;
int DISPLAY_SCALE = 2;

RigidBody** rigidbody; // look this up online

// The entry point for a PlayBuffer program
void MainGameEntry( PLAY_IGNORE_COMMAND_LINE )
{
	Play::CreateManager( DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE );

	rigidbody = new RigidBody * [1000]; // allocating space in RigidBody in memory
	rigidbody[0] = new Ship(); // int the allocated dynamic memory the first space is made for the array, jag kommer använda detta som min instantierade
	// "ship" då jag kalla alla mina object för rigidBodies!
	
	for (int i = 1; i < 2; i++)
	{
		rigidbody[i] = new Asteroid();
	}

}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate( float elapsedTime )
{
	Play::ClearDrawingBuffer( Play::cBlack );

	rigidbody[1]->DrawObject();

	rigidbody[1]->SpeedObject();

	rigidbody[1]->PhysicsGameUpdate();

	rigidbody[0]->PhysicsGameUpdate();
	
	rigidbody[0]->DrawObject(); // using the arrow points to the function of the specific place in memory, kolla upp hur -> funkar också, när jag kan och inte kan använda dem

	Play::CentreSpriteOrigin("Ship"); // Nice

	//if (Play::frameCount >= 10)
	//{
	//	Play::frameCount = 0;
	//};

	Play::PresentDrawingBuffer();

	Play::frameCount++;


	return Play::KeyDown( VK_ESCAPE );
}

// Gets called once when the player quits the game 
int MainGameExit( void )
{
	Play::DestroyManager();
	return PLAY_OK;
}
