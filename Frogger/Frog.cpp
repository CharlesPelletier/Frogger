#include "Frog.h"

const float Frog::speed = 36.0f;

Frog::Frog()
	: Obstacle(FROG_PATH, 244, 468, 30, 30)
	, isActive(false)
	, matchingSpeed(0.f)
{
	SetVisible(false);
}

Frog::~Frog()
{
	delete rect;
}

void Frog::Update()
{
	if (isActive)
	{
		std::cout << "Y: " << GetY() << std::endl;
		
		// Inputs pour bouger la frog
		if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_W))
		{
			SetPosition(GetX(), GetY() - speed);
		}

		if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_S))
		{
			SetPosition(GetX(), GetY() + speed);
		}

		if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_A))
		{
			SetPosition(GetX() - speed * 0.75, GetY());
		}

		if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_D))
		{
			SetPosition(GetX() + speed * 0.75, GetY());
		}

		SetPosition(GetX() + matchingSpeed, GetY());
	}
	Obstacle::Update();
}

void Frog::Die()
{
	isActive = false;
	isVisible = false;
	//SetTexture("SplatSanguin")
}

void Frog::Spawn()
{
	isActive = true;
	isVisible = true;
}
