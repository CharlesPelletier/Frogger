#include "Logs.h"

std::string Logs::TURTLE1_PATH = "Images/turtle1.png";
std::string Logs::LOG2_PATH = "Images/log1.png";
std::string Logs::LOG1_PATH = "Images/log2.png";
std::string Logs::TURTLE2_PATH = "Images/turtle2.png";
std::string Logs::LOG3_PATH = "Images/log3.png";

Logs::Logs(LOG_TYPE type, float speed, Vector2D& startPos, Vector2D& size)
	: Obstacle(startPos.x, startPos.y, size.x, size.y)
	, speed(speed)
{
	switch (type)
	{
	case Logs::turtle1:
		SetTexture(&TURTLE1_PATH);
		break;
	case Logs::log1:
		SetTexture(&LOG1_PATH);
		break;
	case Logs::log2:
		SetTexture(&LOG2_PATH);
		break;
	case Logs::turtle2:
		SetTexture(&TURTLE2_PATH);
		break;
	case Logs::log3:
		SetTexture(&LOG3_PATH);
		break;
	}
	this->speed = speed;
}

Logs::~Logs()
{

}

void Logs::Update()
{
	Obstacle::Update();
	SetPosition(GetX() + speed, GetY());

	if (speed > 0)
	{
		if (GetX() >= 516)
		{
			SetPosition(-150, GetY());
		}
	}
	else
	{
		if (GetX() <= -150)
		{
			SetPosition(486, GetY());
		}
	}
}