#include <iostream>
#include <string>

int main();
bool isNumeric(std::string checkString);
int usrInput(std::string outMessage, int lowerLength, int upperLength);

int main()
{
	std::string tmpInputs;
	int intProducts;
        int intInputs;
	
	intProducts = usrInput("products (number of sumations)", 0, 5);
	intInputs = usrInput("gates (number of different letters)", 0, 5);

        char* products;
    	for (int j = 0; j < intProducts; j++)
    	{
        	std::cout << "Enter another product." << std::endl;
        	std::cin >> products[j];
    	}
}

bool isNumeric(std::string checkString)
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

int usrInput(std::string outMessage, int lowerLength, int upperLength)
{
	std::cout << "Enter the number of " << outMessage << std::endl;
	std::string tmpInput;
	bool isValid = false;
	while (!isValid)
	{
		std::cin >> tmpInput;
		if (isNumeric(tmpInput))
		{
			if ((stoi(tmpInput) < upperLength) && (stoi(tmpInput) > lowerLength))
			{
				std::cout << "Input for " << outMessage << " is valid" << std::endl;
				isValid = true;
			} else {
				std::cout << "Value is out of bounds." << std::endl; 
			}
		} else {
			std::cout << "Value is not a positive integer." << std::endl;
		}
		tmpInput = "1";
	}	
	return stoi(tmpInput);
}

