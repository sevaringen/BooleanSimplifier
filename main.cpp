#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main();
bool isNumeric(std::string checkString);
int usrInput(std::string outMessage, int lowerLength, int upperLength);
std::vector<std::string> splitString(const std::string &sentence, char delim);
int grayIndex(std::string grayCode);
void display(int** thisArray, int rows, int cols);
// find(map(left(exp,2)), map(right(exp,2)))
std::string strLeft(std::string strIn, int count);
std::string strRight(std::string strIn, int count);

int main()
{
	std::string tmpInputs = "";
	int intInputs = usrInput("inputs", 1, 5);
	std::cout << "Enter the unsimplified boolean expression as sums of products" << std::endl;
	std::cin >> tmpInputs;
	std::vector<std::string> sumoprod = splitString(tmpInputs, '+');
	
	int iLength =0 ; int jLength= 0;
	int xLen; int yLen;
	switch (intInputs)
	{
		case 2: 
			iLength = 2; jLength = 2; xLen = 1; yLen = 1; break;
		case 3: 
			iLength = 4; jLength = 2; xLen = 2; yLen = 1; break;
		case 4: 
			iLength = 4; jLength = 4; xLen = 2; yLen = 2; break;
	}
	std::cout << xLen << yLen << std::endl;
	int** kMap;
	kMap = new int*[iLength];
	for (int l = 0; l < iLength; l++)
	{
		kMap[l] = new int[jLength];
		for (int h = 0; h < jLength; h++)
		{
			kMap[l][h] = 0;
		}
	}
	
	int grayX = 0; int grayY = 0;
	for (int k = 0; k < sumoprod.size(); k++)
	{
		tmpInputs = sumoprod[k];
		std::cout << tmpInputs;
		grayX = grayIndex(strLeft(tmpInputs, xLen));
		grayY = grayIndex(strRight(tmpInputs, yLen));
		kMap[grayX][grayY] = 1;
	}
	display(kMap, iLength, jLength);
	return 0;
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
				std::cout << "Input for " << outMessage << " is valid." << std::endl;
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

int grayIndex(std::string grayCode)
{
	switch (stoi(grayCode))
	{
		case 0: return 0;
		case 1: return 1;
		case 11: return 2;
		case 10: return 3; 
		default: return 0;
	}
}

std::vector<std::string> splitString(const std::string &sentence, char delim)
{
	std::vector<std::string> elements;
	std::stringstream strStream(sentence);
	std::string word;
	while (std::getline(strStream, word, delim))
	{
		elements.push_back(word);
	}
	return elements;
}

void display(int** thisArray, int rows, int cols) 
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << thisArray[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

std::string strLeft(std::string strIn, int count)
{
	std::string tmpStr(1, strIn[0]);
	if (count == 2)
	{
		tmpStr.push_back(strIn[1]);
	}
	std::cout << tmpStr;
	return tmpStr;
}

std::string strRight(std::string strIn, int count)
{
	std::string tmpStr(1,strIn[strIn.size() - count]);
	if (count == 2) 
	{
		tmpStr.push_back(strIn[strIn.size() - 1]);
	}
	std::cout << tmpStr << std::endl;
	return tmpStr;
}
