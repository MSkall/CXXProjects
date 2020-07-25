#include <iostream>
#include <sstream>
#include <iomanip>
#include "Quaternion.h"
#include "Vector.h"
#include "ValidateProgram.h"

bool ValidateProgram::MainMenu()
{
	std::cout << "==========================" << std::endl;
	std::cout << "| MAIN MENU |" << std::endl;
	std::cout << "==========================" << std::endl;
	std::cout << "Select a test by typing the corresponding number: " << std::endl;
	std::cout << "1) Quaternion Test" << std::endl;
	std::cout << "2) Vector Test" << std::endl;
	std::cout << "(OR Enter '0' to go back)" << std::endl;
	std::cout << "==========================" << std::endl;

	std::string line;
	std::getline(std::cin, line);

	// verify an int has been entered
	std::stringstream ss(line);
	int num;
	if(!(ss >> num))
	{
		std::cout << "Must input a number to select a test" << std::endl;
	}

	ss << num;
	if(num == 0)
	{
		return true;
	}
	else if(num == 1)
	{
		RunQuaternionTest();
		return true;
	}
	else if(num == 2)
	{
		RunVectorTest();
		return true;
	}
	else
	{
		std::cout << "You entered a number that does not correspond to a test. Try again." << std::endl;
	}
	
	return false;
}

bool ValidateProgram::ChooseVectorOperation()
{
	std::cout << "No current operations available" << std::endl;
	return true;

	// std::cout << "Select a test by typing the corresponding number: " << std::endl;
	// std::cout << "1) Vector addition" << std::endl;
	// std::cout << "2) Vector subtraction" << std::endl;
	// std::cout << "3) Dot product" << std::endl;
	// std::cout << "4) Cross product" << std::endl;
	// std::cout << "(OR Enter '0' to go back)" << std::endl;

	// std::string line;
	// std::getline(std::cin, line);

	// // verify an int has been entered
	// std::stringstream ss(line);
	// int num;
	// if(!(ss >> num))
	// {
	// 	std::cout << "Must input a number to select a test" << std::endl;
	// }

	// ss << num;
	// if(num == 0)
	// {
	// 	return true;
	// }
	// else if(num == 1)
	// {
	// 	return true;
	// }
	// else if(num == 2)
	// {
	// 	return true;
	// }
	// else
	// {
	// 	std::cout << "You entered a number that does not correspond to a test. Try again." << std::endl;
	// }
	
	// return false;
}

void ValidateProgram::RunQuaternionTest()
{
	std::cout << std::endl;
	std::cout << "==========================" << std::endl;
	std::cout << "QUATERNION TEST" << std::endl;
	std::cout << "==========================" << std::endl;

	bool runTest = true;
	while(runTest)
	{
		std::cout << "Enter an angle (in degrees)" << std::endl;

		std::string line;
		std::getline(std::cin, line);

		float io_x, io_y, io_z;
		float io_angle;
		
		if(ReadAngleParamInput(line, io_angle))
		{
			std::cout << "Enter a vector, format: (float x, float y, float z):" << std::endl;
			std::getline(std::cin, line);
			
			if(ReadVectorParamInput(line, io_x, io_y, io_z))
			{
				// Create quaternion
				Vector vec = Vector(io_x, io_y, io_z);
				Quaternion q;
				q.PrintQuaternion(vec, io_angle);
			}
		}
		else
		{
			std::cout << "Cannot make Quaternion with given parameters" << std::endl;
		}
		bool validInput = false;
		while(validInput == false) // until validInput is true, keep looping
		{
			if(!DoWeContinue(validInput, " Quaternion Test"))
			{
				runTest = false;
				std::cout << "Terminating Quaternion Test..." << std::endl;
				break;
			}
		}
	}
}

void ValidateProgram::RunVectorTest()
{
	std::cout << std::endl;
	std::cout << "==========================" << std::endl;
	std::cout << "VECTOR TEST" << std::endl;
	std::cout << "==========================" << std::endl;

	bool runTest = true;
	while(runTest)
	{
		std::cout << "Select which vector operation you want to execute..." << std::endl;
		if(ChooseVectorOperation())
		{

		}

		bool validInput = false;
		while(validInput == false) // until validInput is true, keep looping
		{
			if(!DoWeContinue(validInput, " Vector Test"))
			{
				runTest = false;
				std::cout << "Terminating Vector Test..." << std::endl;
				break;
			}
		}
	}
}

bool ValidateProgram::ReadVectorParamInput(std::string line, float& io_x, float& io_y, float& io_z)
{
	std::size_t foundparenthesis1 = line.find('(');
	std::size_t foundparenthesis2 = line.find(')');
	if(foundparenthesis1 != std::string::npos && foundparenthesis2 != std::string::npos) // found '(' and ')'
	{
		// expect 2 commas
		// expect at most 3 decimals
		std::stringstream ss(line);
		char ch;
		int commaCount = 0;
		int decimalPointCount = 0;
		while(ss >> ch)
		{
			if(ch == ',')
			{
				commaCount++;
			}
			if(ch == '.')
			{
				decimalPointCount++;
			}
		}
		if(!(commaCount == 2))
		{
			std::cout << "USAGE: COMMA | Did not match format (float x, float y, float z)" << std::endl;
			return false;
		}
		if(decimalPointCount > 3)
		{
			std::cout << "USAGE: DECIMAL POINT | Did not match format (float x, float y, float z)" << std::endl;
			return false;
		}

		// get the three coordinates
		std::string str;
		std::vector<std::string> coords;
		for(int i = 0; i < line.size(); i++)
		{
			// skip spaces and parenthesis
			if(isspace(line[i]) || line[i] == '(')
			{
				continue;
			}
			else if(line[i] == ',' || line[i] == ')')
			{
				coords.push_back(str);
				str.clear();
			}
			else if(line[i] == '/') // found separator
			{
				std::cout << "USAGE: SLASH | Did not match format (float x, float y, float z). Ex. (1.0, 3.5, 2)" << std::endl;
				return false;
			}
			else
			{
				str += line[i];
			}
		}

		// checking coordinates saved
		int count = 0;
		for(int i = 0; i < coords.size(); i++)
		{
			// ensure that we have read in a float, otherwise did not match format
			std::stringstream ss1(coords[i]);
			float f;
			if(!(ss1 >> f))
			{
				std::cout << "USAGE: FLOAT | Coordinate " << i+1 << " not a float. Did not match format (float x, float y, float z)" << std::endl;
				return false;
			}
			else // assign x,y,z variables
			{
				ss1 << f;
				if(count == 0)
				{
					io_x = f;
				}
				else if(count == 1)
				{
					io_y = f;
				}
				else if(count == 2)
				{
					io_z = f;
				}
				count++;
				ss1.flush();
			}
		}
		return true;
	}
	else
	{
		std::cout << "USAGE: Did not match format (float x, float y, float z)" << std::endl;
	}
	return false;
}

bool ValidateProgram::ReadAngleParamInput(std::string line, float& io_angle)
{
	// determine whether in radians or degrees

	// verify we have a float
	std::stringstream ss(line);
	float f;
	if(!(ss >> f))
	{
		std::cout << "USAGE: FLOAT | " << line << " not a float." << std::endl;
		return false;
	}

	// assign io_angle
	ss << f;
	io_angle = f;
	ss.flush();
	return true;
}

bool ValidateProgram::DoWeContinue(bool& validInput, std::string str)
{
	std::cout << std::endl << "Continue running" << str << "? Y/N: ";

	// get user input
	std::string line;
	std::getline(std::cin, line);

	// read user input
	std::stringstream ss(line);
	char ch;
	if(line.size() == 1) // if 1 character response
	{
		while(ss >> ch)
		{
			if((ch == 'Y' || ch == 'y'))
			{
				validInput = true;
				return true;
			}
			else if((ch == 'N' || ch == 'n'))
			{
				validInput = true;
				return false;
			}
			else
			{
				validInput = false;
				return true;
			}
		}
	}
	else // longer than 1 character response
	{
		// check full input
		if(line == "Yes" || line == "yes" || line == "YES")
		{
			validInput = true;
			return true;
		}
		else if(line == "No" || line == "no" || line == "NO")
		{
			validInput = true;
			return false;
		}
		else
		{
			std::cout << "Invalid input. Please try again." << std::endl;
			validInput = false;
			return true;
		}
	}
	return false;
}

