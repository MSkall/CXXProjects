#include <iostream>
#include "Game.h"

bool Game::Initilaize()
{
	isRunning = true;
	return true;
}

void Game::RunLoop()
{
	while(isRunning)
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}

void Game::ProcessInput()
{

}

void Game::UpdateGame()
{

}

void Game::GenerateOutput()
{

}

int Game::ShutDown()
{
	return 0;
}

