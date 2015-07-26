#pragma once

#include "Obstacle.h"

#define VICTORY_PATH "Images/frog.png"

class Victory :
	public Obstacle
{
public:
	Victory();
	Victory(Vector2D& startPos, Vector2D& size);
	~Victory();
};

