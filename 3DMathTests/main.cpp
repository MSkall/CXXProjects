#include <iostream>
#include <sstream>
#include "Quaternion.h"
#include "Vector.h"
#include "ValidateProgram.h"

// referenced work from: https://github.com/BSVino/MathForGameDevelopers

// future work: make a visualization

int main(int argc, char* argv[])
{
	ValidateProgram vp;

	// RunLoop()
	bool isRunning = true;
	while(isRunning)
	{
		bool askToContinue = true;
		if(!vp.MainMenu()) // if invalid
		{
			askToContinue = false;
		}

		// Do we continue? (add another entry)
		if(askToContinue) {
			bool validInput = false;
			while(validInput == false) // until validInput is true, keep looping
			{
				if(!vp.DoWeContinue(validInput, " program"))
				{
					isRunning = false;
					std::cout << "Quit program." << std::endl;
					break;
				}
			}
		}
	}
	return 0;
}
