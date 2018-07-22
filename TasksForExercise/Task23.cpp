#include <iostream>

int main()
{
	int len;
	std::cout << "Enter length of the sequence: ";
	std::cin >> len;
	if (len > 0)
	{
		char* sequence = new char[len];
		char* symbols = new char[len];
		std::cout << "Enter the sequence: ";
		for (int i = 0; i < len; i++)
		{
			std::cin >> sequence[i];
		}

		int index = 0;
		int i = 0;
		int countOfSymbols = 0;
		while (i < len)
		{
			if (sequence[i] != sequence[len - 1])
			{
				symbols[index] = sequence[i];
				index++;
				countOfSymbols++;
			}
			else
			{
				len--;
			}
			i++;
		}
		symbols[index] = 0;

		if (countOfSymbols == 0)
		{
			std::cout << countOfSymbols << std::endl;
		}
		else
		{
			std::cout << countOfSymbols << " , ";
			while (countOfSymbols-1 >= 0)
			{
				std::cout << symbols[countOfSymbols-1] << " ";
				countOfSymbols--;
			}
			std::cout << std::endl;
		}

		delete[] sequence;
		delete[] symbols;
	}
	else
	{
		std::cout << "Invalide length!" << std::endl;
	}

	return 0;
}