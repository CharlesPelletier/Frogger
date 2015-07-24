#include "Game.h"
#include "Rectangle.h"

Game::Game()
	: currentFrog(0)
	, gameOver(false)
{
	int startPosLine1 = 486;
	int offsetLine1 = 115;
	
	// Création des objets
	Component* c1 = new Component();
	Sprite* bg = new Sprite("Images/bg.bmp");
	bg->SetPosition(0, 0);

	SpawnCarLane(Cars::CAR_TYPE::car1, 4, 486, 30, 30, 130, -0.8f, 0);
	SpawnCarLane(Cars::CAR_TYPE::car2, 4, 486, 30, 30, 130, 0.5f, 1);
	SpawnCarLane(Cars::CAR_TYPE::car3, 4, 486, 30, 30, 130, -1.0f, 2);
	SpawnCarLane(Cars::CAR_TYPE::car4, 4, 486, 30, 30, 130, 1.5f, 3);
	SpawnCarLane(Cars::CAR_TYPE::truck, 3, 486, 50, 30, 170, -1.5f, 4);

	SpawnLogLane(Logs::LOG_TYPE::turtle1, 5, 486, 30, 30, 130, -1.0f, 6, 3, 30);
	SpawnLogLane(Logs::LOG_TYPE::log1, 3, 486, 50, 30, 220, 2.0f, 8, 1, 0);
	SpawnLogLane(Logs::LOG_TYPE::log2, 5, 486, 150, 30, 130, 1.0f, 7, 1, 0);
	SpawnLogLane(Logs::LOG_TYPE::turtle2, 5, 486, 30, 30, 130, -1.0f, 9, 2, 30);
	SpawnLogLane(Logs::LOG_TYPE::log3, 5, 486, 100, 30, 130, 1.3f, 10, 1, 0);

	for (int i = 0; i < 4; i++)
	{
		Frog* temp = new Frog();
		frogs.push_back(temp);
	}

	frogs[currentFrog]->SetVisible(true);
	frogs[currentFrog]->Spawn();
}

Game::~Game()
{

}

void Game::Update()
{
	CollisionWithCars();

	if (gameOver)
		return;

	CollisionWithLogs();
}

// Spawn les Cars dans leur ligne respective
void Game::SpawnCarLane(Cars::CAR_TYPE type, int numInLane, int startPos, 
	int sizeX, int sizeY, int offset, float laneSpeed, int laneID)
{
	for (int i = 0; i < numInLane; i++)
	{
		Vector2D posStart = { startPos, 430 - laneID * laneOffsetY };
		Vector2D size = { sizeX, sizeY };

		Cars* temp = new Cars(type, laneSpeed, posStart, size);
		temp->SetPosition(startPos - i * offset, posStart.y);
		cars.push_back(temp);
	}

}

// Spawn les Logs et les Turtles dans leur ligne respective
void Game::SpawnLogLane(Logs::LOG_TYPE type, int numInLane,int startPos, 
	int sizeX, int sizeY, int offset, float laneSpeed, int laneID, int nbSqueezed, int minOffset)
{
	for (int i = 0; i < numInLane; i++)
	{
		for (int j = 0; j < nbSqueezed; j++)
		{
			Vector2D posStart = { startPos, 430 - laneID * laneOffsetY };
			Vector2D size = { sizeX, sizeY };

			Logs* temp = new Logs(type, laneSpeed, posStart, size);
			temp->SetPosition(startPos - i * offset + j * minOffset, posStart.y);
			logs.push_back(temp);
		}
	}
}

bool Game::CollisionWithCars()
{
	if (currentFrog >= 4)
		return false;

	for (int i = 0; i < cars.size(); i++)
	{
		Rectangle* frogRect = frogs[currentFrog]->GetRect();
		Rectangle* carRect = cars[i]->GetRect();
		if (frogRect->CollidesWith(carRect))
		{
			std::cout << "Hit by a car" << std::endl;

			// Pre
			frogs[currentFrog]->Die();

			currentFrog++;

			// Post
			if (currentFrog < 4)
			{
				frogs[currentFrog]->Spawn();
			}
			else
			{
				// GameOver
				gameOver = true;
			}

			return true;
		}
	}
	return false;
}

bool Game::CollisionWithLogs()
{
	for (int i = 0; i < logs.size(); i++)
	{
		if (frogs[currentFrog]->GetRect()->CollidesWith(logs[i]->GetRect()))
		{
			std::cout << "On a log" << std::endl;

			frogs[currentFrog]->SetPosition(logs[i]->GetX(), logs[i]->GetY());
		}
		return true;
	}
}