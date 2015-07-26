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

	bool GetIsActive() { return isActive; }
	void SetIsActive(bool isActive) { this->isActive = isActive; }

	void SetMatchingSpeed(float speed){ matchingSpeed = speed; }

	void Die();
	void Spawn();

private:
	bool isActive;
	float matchingSpeed;
	static const float speed;
};

