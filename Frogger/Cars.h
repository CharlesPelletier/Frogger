#pragma once

#include "Obstacle.h"

class Cars :
	public Obstacle
{
public:
	// énumération des types de cars
	enum CAR_TYPE { car1, car2, car3, car4, truck};

	Cars(CAR_TYPE type, float speed, Vector2D& startPos, Vector2D& size);
	~Cars();

	void Update();

private:
	static std::string CAR1_PATH;
	static std::string CAR2_PATH;
	static std::string CAR3_PATH;
	static std::string CAR4_PATH;
	static std::string TRUCK_PATH;

	static const int CAR_SQUARED_SIZE = 30;
	static const int TRUCK_SIZE_X = 50;
	static const int TRUCK_SIZE_Y = 30;

	float speed;
};