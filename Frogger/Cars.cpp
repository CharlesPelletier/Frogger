#include "Cars.h"

// path pour les textures des cars
std::string Cars::CAR1_PATH = "Images/car1.png";
std::string Cars::CAR2_PATH = "Images/car2.png";
std::string Cars::CAR3_PATH = "Images/car3.png";
std::string Cars::CAR4_PATH = "Images/car4.png";
std::string Cars::TRUCK_PATH = "Images/truck.png";

Cars::Cars(CAR_TYPE type, float speed, Vector2D& startPos, Vector2D& size)
	: Obstacle(startPos.x, startPos.y, size.x, size.y)
	, speed(speed)
{
	switch (type)
	{
	case Cars::car1:
		SetTexture(&CAR1_PATH);
		break;
	case Cars::car2:
		SetTexture(&CAR2_PATH);
		break;
	case Cars::car3:
		SetTexture(&CAR3_PATH);
		break;
	case Cars::car4:
		SetTexture(&CAR4_PATH);
		break;
	case Cars::truck:
		SetTexture(&TRUCK_PATH);
		break;
	}
}

Cars::~Cars()
{

}

void Cars::Update()
{
	Obstacle::Update();

	// Position et vitesse des cars
	//SetPosition(GetX() + speed, GetY());

	// Si un cars quitte l'écran, réapparait de l'autre côté
	if (speed > 0)
	{
		if (GetX() >= 516)
		{
			SetPosition(0, GetY());
		}
	}
	else
	{
		if (GetX() <= -30)
		{
			SetPosition(486, GetY());
		}
	}
}