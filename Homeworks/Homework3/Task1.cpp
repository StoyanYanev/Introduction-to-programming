#include <iostream>
#include<vector>

const int LENGTH_OF_SIGNS = 54;
const int MAX_LENGTH = 100; /* max length of the expression */

/* save all signs which have morse code */
const char SYMBOLS[LENGTH_OF_SIGNS] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9','.', ',', '?','\'','!','/','(',')','&',':',';','=','-','_','"','$','@','+' };

/* save morse code of the signs */
const char* MORSE_CODE[LENGTH_OF_SIGNS] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." ,"-----", ".----", "..--- ", "...--", "....-", ".....", "-....", "--...","---..","----.",".-.-.-","--..--","..--..",".----.",
"-.-.--","-..-.","-.--.","-.--.-",".-...","---...","-.-.-.","-...-","-....-", "..--.-",".-..-.","...-..-",".--.-.",".-.-." };

int FindIndexByTheLetter(char symbol);
void PrintExpressionInMorseCode(std::vector<int> expression);

int main()
{
	char expression[MAX_LENGTH];
	std::cout << "Enter expression: ";
	std::cin.getline(expression, MAX_LENGTH);

	int len = std::strlen(expression);

	std::vector<int> indexOfMorseCode; /* save index of the symbols */
	bool isValid = true; /* check if the expression is valid */
	int ind; /* save current index */

	for (int i = 0; i < len; i++)
	{
		if (expression[i] != ' ') /* check if the current sign is a whitespace */
		{
			if (isalpha(expression[i]) != 0)
			{
				expression[i] = expression[i] & 0xDF; /* make the low letters capital */
			}
			ind = FindIndexByTheLetter(expression[i]); /* check if the current sign is valid,if it is return his index in the symbols array else return -1 */
			if (ind != -1)
			{
				indexOfMorseCode.push_back(ind);
				indexOfMorseCode.push_back(-1); /* -1 for whitespace */
			}
			else
			{
				isValid = false;
				break;
			}
		}
		else
		{
			indexOfMorseCode.push_back(-1); /* in this case -1 is a whitespace */
		}
	}

	if (isValid == true)
	{
		PrintExpressionInMorseCode(indexOfMorseCode);
	}
	else
	{
		std::cout << "Invalid expression!" << std::endl;
	}
	std::cout << std::endl;

	return 0;
}

int FindIndexByTheLetter(char symbol)
{
	for (int i = 0; i < LENGTH_OF_SIGNS; i++)
	{
		if (SYMBOLS[i] == symbol)
		{
			return i;
		}
	}
	return -1;
}

void PrintExpressionInMorseCode(std::vector<int> expression)
{
	for (int i = 0; i < expression.size(); i++)
	{
		if (expression[i] == -1) /* -1 for whitespace */
		{
			std::cout << " ";
		}
		else
		{
			std::cout << MORSE_CODE[expression[i]];
		}
	}
}