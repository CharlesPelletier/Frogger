#pragma once

#include "Obstacle.h"

#define FROG_PATH "Images/frog.png"

class Frog :
	public Obstacle
{
public:
	Frog();
	~Frog();

	void Update();

	//bool GetIsActive() { return isActive; }
	//void SetIsActive(bool isActive) { this->isActive = isActive; }

	void Die();
	void Spawn();

private:
	bool isActive;
	static const float speed;
};

