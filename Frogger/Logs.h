#pragma once

#include "Obstacle.h"

class Logs :
	public Obstacle
{
public:
	enum LOG_TYPE { turtle1, log1, log2, turtle2, log3 };

	Logs(LOG_TYPE type, float speed, Vector2D& startPos, Vector2D& size);
	~Logs();

	void Update();

private:
	static std::string TURTLE1_PATH;
	static std::string LOG1_PATH;
	static std::string LOG2_PATH;
	static std::string TURTLE2_PATH;
	static std::string LOG3_PATH;

	static const int TURTLE_SQUARED_SIZE = 30;
	static const int LOG1_SIZE_X = 50;
	static const int LOG1_SIZE_Y = 30;
	static const int LOG2_SIZE_X = 150;
	static const int LOG2_SIZE_Y = 30;
	static const int LOG3_SIZE_X = 100;
	static const int LOG3_SIZE_Y = 30;

	float speed;
};