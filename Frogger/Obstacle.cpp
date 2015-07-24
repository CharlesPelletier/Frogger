#include "Obstacle.h"

Obstacle::Obstacle()
	: Sprite()
{
	rect = new Rectangle();
}

Obstacle::Obstacle(std::string path, float posX, float posY)
	: Sprite(path)
{
	SetPosition(posX, posY);
	rect = new Rectangle(GetX(), GetY(), 0.f, 0.f );
}

Obstacle::Obstacle(std::string path, float posX, float posY, float sizeX, float sizeY)
	: Sprite(path)
{
	SetPosition(posX, posY);
	rect = new Rectangle(GetX(), GetY(), sizeX, sizeY);
}

Obstacle::Obstacle(float posX, float posY, float sizeX, float sizeY)
	: Sprite()
{
	SetPosition(posX, posY);
	rect = new Rectangle(GetX(), GetY(), sizeX, sizeY);
}

Obstacle::~Obstacle()
{
	delete rect;
}

void Obstacle::Update()
{
	rect->SetPosition(GetX(), GetY());
}
