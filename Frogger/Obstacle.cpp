#include "Obstacle.h"

Obstacle::Obstacle()
	: Sprite()
{
	rect = new Rectangle();
}

// Set le path et la position d'un obstacle
Obstacle::Obstacle(std::string path, float posX, float posY)
	: Sprite(path)
{
	SetPosition(posX, posY);
	rect = new Rectangle(GetX(), GetY(), 0.f, 0.f );
}

// Set le path, la position et la grosseur du rectangle d'un obstacle
Obstacle::Obstacle(std::string path, float posX, float posY, float sizeX, float sizeY)
	: Sprite(path)
{
	SetPosition(posX, posY);
	rect = new Rectangle(GetX(), GetY(), sizeX, sizeY);
}

// Set la position et la grosseur du rectangle d'un obstacle
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

// Actualise la position du rectangle
void Obstacle::Update()
{
	rect->SetPosition(GetX(), GetY());
}
