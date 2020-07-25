#include <iostream>
#include <iomanip>

class Game
{
public:
	Game() {};

	bool Initilaize();
	void RunLoop();
	int ShutDown();

private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();

	bool isRunning;
};