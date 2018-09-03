#include<iostream>

int const MAX_LENGTH = 100;

bool doExist(char* symbols, char* word);

int main()
{
	//char *symbols = new char[MAX_LENGTH];
	//char *word = new char[MAX_LENGTH];

	char symbols[MAX_LENGTH];
	char word[MAX_LENGTH];

	std::cout << "Enter sentence: ";
	std::cin.getline(symbols, MAX_LENGTH);

	std::cout << "Enter word: ";
	std::cin.getline(word, MAX_LENGTH);

	std::cout << "Is exist the word: " << doExist(symbols, word) << std::endl;

	//delete[] symbols;
	//delete[] word;

	return 0;
}

bool doExist(char * symbols, char * word)
{
	int lenOfSentence = strlen(symbols);
	int lenOfWord = strlen(word);

	if (lenOfSentence >= lenOfWord)
	{
		int index = 0;
		int currentIndex;
		bool isExist = true;

		for (int i = 0; i < lenOfSentence; i++)
		{
			if (symbols[i] == word[index])
			{
				currentIndex = i;
				while (index <= lenOfWord - 1)
				{
					if (symbols[currentIndex] != word[index])
					{
						isExist = false;
						break;
					}
					index++;
					currentIndex++;
				}
				index = 0;
				if (isExist == true)
				{
					return isExist;
				}
				else
				{
					isExist = true;
				}
			}
		}
	}
	return false;
}