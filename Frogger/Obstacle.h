#pragma once

#include "Common.h"
#include "Sprite.h"
#include "Rectangle.h"

class Obstacle :
	public Sprite
{
public:
	
	Obstacle();
	Obstacle(float posX, float posY, float sizeX, float sizeY);
	Obstacle(std::string path, float posX, float posY, float sizeX, float sizeY);
	Obstacle(std::string path, float posX, float posY);
	virtual ~Obstacle();
	virtual void Update();

	Rectangle* GetRect() { return rect; }

protected:
	Rectangle* rect;
};

