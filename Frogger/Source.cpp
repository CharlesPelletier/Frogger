#include <iostream>
#include "Engine.h"
#include "Game.h"

int main(int argc, char* args[])
{
	// Initialise la taille de l'�cran
	Engine::GetInstance()->Init(516, 560);

	// Cr�ation du partie
	Game* game = new Game();

	// Commence la boucle de jeu
	Engine::GetInstance()->Start();

	return 0;
}
