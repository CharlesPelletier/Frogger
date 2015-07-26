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

	// Vérifie si frog est activée
	bool GetIsActive() { return isActive; }

	// Set la frog active à true ou false
	void SetIsActive(bool isActive) { this->isActive = isActive; }

	// Speed de frog devient speed de logs
	void SetMatchingSpeed(float speed){ matchingSpeed = speed; } 

	void Die();
	void Spawn();

private:
	bool isActive;
	float matchingSpeed;
	static const float speed;
};

