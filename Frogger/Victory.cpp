#include "Victory.h"

Victory::Victory()
{

}

Victory::Victory(Vector2D& startPos, Vector2D& size)
	: Obstacle(VICTORY_PATH, startPos.x, startPos.y, size.x, size.y)
{

}

Victory::~Victory()
{

}
