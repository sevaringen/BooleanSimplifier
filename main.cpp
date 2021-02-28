#include <iostream>
#include <string>

int main()
{
	std::string tmpInputs;
	int intProducts;
    int intInputs;
	std::string strInputs;
	bool isValid;

	std::cout << "Enter the number of products (number of sumations)" << std::endl;
	while (!isValid) 
	{
		tmpInputs << std::cin;
		if (isNumeric(tmpInputs)) 
		{
			if (tmpInputs < 5 && tmpInputs > 0)
			{
				intProducts = stoi(tmpInputs)
                isValid = true;
				std::cout << "Input is valid";
			}	
		} else {
            std::cout "Enter a positive integer";
        }
	}

    std::cout << "Enter the number of inputs (number of gates)" << std::endl;
    while (isValid) 
	{
		tmpInputs << std::cin;
		if (isNumeric(tmpInputs)) 
		{
			if (tmpInputs < 5 && tmpInputs > 0)
			{
				intInputs = stoi(tmpInputs)
                isValid = false;
				std::cout << "Input is valid";
			}	
		} else {
            std::cout "Enter a positive integer";
        }
	}

    char* products;
    for (int j = 0; j < intProducts; j++)
    {
        cout << "Enter another product." << << std::end;
        products[j] = std::cin;
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
