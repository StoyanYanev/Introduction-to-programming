#include <iostream>

const int MAX_SIZE = 100;

int GetLen(char * str);
bool doExsist(char * symbols, char * word);

int main()
{
	char symbols[MAX_SIZE];
	char word[MAX_SIZE];

	std::cout << "Enter sentence: ";
	std::cin.getline(symbols, MAX_SIZE);

	std::cout << "Enter word: ";
	std::cin.getline(word, MAX_SIZE);

	std::cout << "Is exist the word: " << doExsist(symbols, word) << std::endl;

	return 0;
}

int GetLen(char * str)
{
	int len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return len;
}

bool doExsist(char * symbols, char * word)
{
	if (symbols != NULL && word != NULL)
	{
		int lenSymbols = GetLen(symbols);
		int lenWord = GetLen(word);

		if (lenSymbols >= lenWord)
		{
			int count = 0;
			int index = 0;
			int currentIndex;
			bool isExsist = true;

			for (int i = 0; i < lenSymbols; i++)
			{
				if (symbols[i] == word[index])
				{
					currentIndex = i;;
					while (index <= lenWord - 1)
					{
						if (symbols[currentIndex] != word[index])
						{
							isExsist = false;
							break;
						}
						index++;
						currentIndex++;
					}
					if (isExsist == true)
					{
						count++;
					}
					else
					{
						isExsist = true;
					}
					index = 0;
				}
			}
			if (count >= 2) // how many times the word repeat
			{
				return true;
			}
		}
		return false;
	}
	return false;
}