#define PLAY_IMPLEMENTATION
#define PLAY_USING_GAMEOBJECT_MANAGER
#include "Play.h"
#include "Rigidbody.h"
#include "Asteroid.h"
#include "Ship.h"


int DISPLAY_WIDTH = 640;
int DISPLAY_HEIGHT = 360;
int DISPLAY_SCALE = 2;

// The entry point for a PlayBuffer program
void MainGameEntry( PLAY_IGNORE_COMMAND_LINE )
{
	Play::CreateManager( DISPLAY_WIDTH, DISPLAY_HEIGHT, DISPLAY_SCALE );
}

// Called by PlayBuffer every frame (60 times a second!)
bool MainGameUpdate( float elapsedTime )
{
	Play::ClearDrawingBuffer( Play::cBlack );
	
	//Play::DrawDebugText( { DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2 }, "" );
	
	RigidBody rigidBody = RigidBody();

	DrawShip(rigidBody);
	DrawAsteroid();
	
	ShipMovement(rigidBody);

	Play::PresentDrawingBuffer();
	//timeStepOne++;

	Play::frameCount++;

	

	return Play::KeyDown( VK_ESCAPE );
}

// Gets called once when the player quits the game 
int MainGameExit( void )
{
	Play::DestroyManager();
	return PLAY_OK;
}
