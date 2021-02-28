#include <iostream>

int main()
{
	std::string tmpInputs;
	std::int intInputs;
	std::string strInputs;
	std::bool isValid;

	std::cout << "Enter the number of inputs";
	while (!isValid) 
	{
		tmpInputs << cin;
		if (isNumeric(tmpInputs)) 
		{
			if (tmpInputs < 5 && tmpInputs > 0)
			{
				isValid = true
				std::cout << "Input is valid";
			}	
		}
	}
}

bool isNumeric(string checkString)
{
	for (int i = 0; i < checkString.length(); i++)
	{
		if (isdigit(checkString[i]) == false)
		{ 
			return false;
		}
	}
	return true;	
}
