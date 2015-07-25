#pragma once

#include "Cars.h"
#include "Frog.h"
#include "Logs.h"

class Game :
	public Component
{
public:
	Game();
	~Game();

	void Update();

private:
	static const int laneOffsetY = 36;

	bool gameOver;
	int currentFrog;
	std::vector<Cars*> cars;
	std::vector<Logs*> logs;
	std::vector<Frog*> frogs;

	void SetGameOver();

	void SpawnCarLane(Cars::CAR_TYPE type, int numInLane, 
		int startPos, int sizeX, int sizeY, int offset, 
		float laneSpeed, int laneID);

	void SpawnLogLane(Logs::LOG_TYPE type, int numInLane, 
		int startPos, int sizeX, int sizeY, int offset, 
		float laneSpeed, int laneID, int nbSqueezed, int minOffset);

	bool CollisionWithCars();
	bool CollisionWithLogs(Logs** outLog);
};

