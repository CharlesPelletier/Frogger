#include "Game.h"
#include "Rectangle.h"

Game::Game()
	: currentFrog(0)
	, gameOver(false)
	, numOfFrog(4)
{
	int startPosLine1 = 486;
	int offsetLine1 = 115;
	
	// Création des objets
	Component* c1 = new Component();

	// Sprite du Background
	Sprite* bg = new Sprite("Images/bg.bmp");
	bg->SetPosition(0, 0);

	// Détermine le nombre, la grosseur et la vitesse 
	// des cars dans leur lane respective
	SpawnCarLane(Cars::CAR_TYPE::car1, 4, 486, 30, 30, 130, -0.8f, 0);
	SpawnCarLane(Cars::CAR_TYPE::car2, 4, 486, 30, 30, 130, 0.5f, 1);
	SpawnCarLane(Cars::CAR_TYPE::car3, 4, 486, 30, 30, 130, -1.0f, 2);
	SpawnCarLane(Cars::CAR_TYPE::car4, 4, 486, 30, 30, 130, 1.5f, 3);
	SpawnCarLane(Cars::CAR_TYPE::truck, 3, 486, 50, 30, 170, -1.5f, 4);

	// Détermine le nombre, la grosseur et la vitesse 
	// des logs et turtles dans leur lane respective
	SpawnLogLane(Logs::LOG_TYPE::turtle1, 5, 486, 30, 30, 130, -1.0f, 6, 3, 30);
	SpawnLogLane(Logs::LOG_TYPE::log2, 5, 486, 50, 30, 130, 1.0f, 7, 1, 0);
	SpawnLogLane(Logs::LOG_TYPE::log1, 3, 486, 150, 30, 220, 1.7f, 8, 1, 0);
	SpawnLogLane(Logs::LOG_TYPE::turtle2, 5, 486, 30, 30, 130, -1.0f, 9, 2, 30);
	SpawnLogLane(Logs::LOG_TYPE::log3, 4, 486, 100, 30, 170, 1.3f, 10, 1, 0);

	// Tableau de frog
	for (int i = 0; i < 5; i++)
	{
		Frog* temp = new Frog();
		frogs.push_back(temp);

		int startX = 23;
		int offSetX = 110;

		Vector2D posStart = { startX + i * offSetX, 36 };
		Vector2D size = { 30, 30 };

		Victory* nenupharFrog = new Victory(posStart, size);
		
		nenupharFrog->SetVisible(false);
		nenupharFrog->SetPosition(posStart);
		victories.push_back(nenupharFrog);
	}

	frogs[currentFrog]->SetVisible(true);
	frogs[currentFrog]->Spawn();

	// Sprite du Menu
	menu = new Sprite("Images/menu.png");
	menu->SetPosition(0, 0);
}

Game::~Game()
{

}

void Game::SetGameOver()
{
	// Pre
	frogs[currentFrog]->Die();

	currentFrog++;

	// Post
	if (currentFrog < 5)
	{
		frogs[currentFrog]->Spawn();
	}
	else
	{
		// GameOver
		gameOver = true;
	}
}

void Game::Update()
{
	// Fait disparaitre le menu de départ
	if (Engine::GetInstance()->GetInput()->IsKeyPressed(SDL_SCANCODE_SPACE))
	{
		menu->SetVisible(false);
	}

	
	// S'il y a collision avec une voiture, la frog
	// meurt et recommence à la position de départ
	if (CollisionWithCars())
	{
		SetGameOver();
	}

	if (gameOver)
	{
		return;
	}

	const float midLimit_ScreenCoord = 252;
	if (frogs[currentFrog]->GetY() < midLimit_ScreenCoord)
	{
		// Si collision avec un log ou turtle, la frog
		// prend la vitesse du log en X
		Logs* l;
		if (CollisionWithLogs(&l))
		{
			frogs[currentFrog]->SetMatchingSpeed(l->GetSpeed());
		}
		else
		{
			const float topLimit_ScreenCoord = 60.0f;

			// Sinon, si la frog atteint la top zone, sa
			// vitesse retombe à zéro.
			// If is top zone.
			if (frogs[currentFrog]->GetY() < topLimit_ScreenCoord)
			{
				frogs[currentFrog]->SetMatchingSpeed(0.f);
			}
			else
				// Sinon, si la frog touche à l'eau elle meurt
			{
				SetGameOver();
			}
		}
	}
	else
	{
		// If is under mid line, in the cars zone.
		frogs[currentFrog]->SetMatchingSpeed(0.f);
	}

	// Condition de victoire
	
	for (int i = 0; i < victories.size(); i++)
	{
		if (frogs[currentFrog]->GetRect()->CollidesWith(victories[i]->GetRect()))
		{
			//Place la frog exactement au milieu du nénuphar
			//frogs[currentFrog]->SetPosition(victories[i]->GetX(), victories[i]->GetY());
			std::cout << "Nenuphar touched" << std::endl;;

			victories[i]->SetVisible(true);

			frogs[currentFrog]->SetIsActive(false);
			frogs[currentFrog]->SetVisible(false);
			frogs[currentFrog]->SetMatchingSpeed(0.f);

			//currentFrog++;
			//frogs[currentFrog]->SetVisible(true);
			//frogs[currentFrog]->SetIsActive(true);
			
			//if (currentFrog >= numOfFrog)
			//{
			//	SetGameOver();
			//}

			//Vérifie s'il reste des vies 
			if (currentFrog <= numOfFrog)
			{
				currentFrog++;
				frogs[currentFrog]->SetVisible(true);
				frogs[currentFrog]->SetIsActive(true);
			}
			// Sinon, GameOver
			else
			{
				SetGameOver();
			}
		}
	}
	
	// S'assure que frog est toujours dans l'écran
	if (frogs[currentFrog]->GetX() <= 0)
	{
		frogs[currentFrog]->SetPosition(0, frogs[currentFrog]->GetY());
	}
	if (frogs[currentFrog]->GetX() >= 486)
	{
		frogs[currentFrog]->SetPosition(486, frogs[currentFrog]->GetY());
	}
	if (frogs[currentFrog]->GetY() <= 0)
	{
		frogs[currentFrog]->SetPosition(frogs[currentFrog]->GetX(), 0);
	}
	if (frogs[currentFrog]->GetY() >= 530)
	{
		frogs[currentFrog]->SetPosition(frogs[currentFrog]->GetX(), 530);
	}
	
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

// Détecte s'il y a une collision entre 
// la frog et les cars
bool Game::CollisionWithCars()
{
	if (currentFrog >= 5)
		return false;

	for (int i = 0; i < cars.size(); i++)
	{
		Rectangle* frogRect = frogs[currentFrog]->GetRect();
		Rectangle* carRect = cars[i]->GetRect();
		if (frogRect->CollidesWith(carRect))
		{
			std::cout << "Dead" << std::endl;
			return true;
		}
	}
	return false;
}

// Détecte s'il y a une collision entre 
// la frog et les logs et les turtles
bool Game::CollisionWithLogs(Logs** outLog)
{
	for (int i = 0; i < logs.size(); i++)
	{
		Rectangle* frogRect = frogs[currentFrog]->GetRect();
		Rectangle* logRect = logs[i]->GetRect();
		if (frogRect->CollidesWith(logRect))
		{
			*outLog = logs[i];
			return true;
		}
	}
	return false;
}