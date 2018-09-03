#include <iostream>

const int MAX_SIZE = 100;
void Revert(char word[]);

int main()
{
	char word[MAX_SIZE];
	 std::cout<<"Enter word: ";
	std::cin.getline(word, MAX_SIZE);
	Revert(word);

	for (int i = 0; i < std::strlen(word); i++)
	{
		std::cout << word[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}

void Revert(char word[])
{
	int len = std::strlen(word);
	for (int i = 0; i < len; i++)
	{
		if (((int)word[i] >= 65) && ((int)word[i] <= 90))
		{
			word[i] = word[i] | 0x20;
		}
		else if (((int)word[i] >= 98) && ((int)word[i] <= 122))
		{
			word[i] = word[i] & 0xDF;
		}
	}
}