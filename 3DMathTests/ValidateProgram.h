#pragma once

class ValidateProgram
{
public:
	ValidateProgram() {};
	
	bool MainMenu();
	
	// helper functions
	bool ReadAngleParamInput(std::string line, float& io_angle);
	bool ReadVectorParamInput(std::string line, float& io_x, float& io_y, float& io_z);
	bool DoWeContinue(bool& validInput, std::string str);

	// tests
	void RunQuaternionTest();
	void RunVectorTest();

protected:
	bool ChooseVectorOperation();

	float m_angle;
	float m_vx, m_vy, m_vz;
};