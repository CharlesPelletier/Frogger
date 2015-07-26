#include "Victory.h"

Victory::Victory()
{

}

// Constructeur pour le path, la position et la 
//grosseur du rectangle des frogs sur les nénuphars
Victory::Victory(Vector2D& startPos, Vector2D& size)
	: Obstacle(VICTORY_PATH, startPos.x, startPos.y, size.x, size.y)
{

}

Victory::~Victory()
{

}
