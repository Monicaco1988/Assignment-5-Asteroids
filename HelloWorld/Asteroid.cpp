#include "Asteroid.h"
#include "Play.h"


void Asteroid::DrawObject()
{
	Play::DrawSpriteRotated("Asteroid", { 250,250 }, 0, 0.01f);
};