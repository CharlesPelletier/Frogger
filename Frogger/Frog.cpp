#include "Frog.h"

const float Frog::speed = 36.0f;

Frog::Frog()
	: Obstacle(FROG_PATH, 244, 468, 30, 30)
	, isActive(false)
{
	SetVisible(false);
}

Frog::~Frog()
{
	delete rect;
}

void Frog::Update()
{
	Obstacle::Update();

	if (isActive)
	{
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
	}
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
