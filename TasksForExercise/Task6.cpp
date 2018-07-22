#include <iostream>

int main()
{
	int number;
	std::cout << "Enter number: ";
	std::cin >> number;
	if (number >= 100 && number <= 30000)
	{
		int min = 9;
		int max = 0;
		int currentDigit = 0;
		while (number != 0)
		{
			currentDigit = number % 10;
			if (max < currentDigit)
			{
				max = currentDigit;
			}
			if (min > currentDigit)
			{
				min = currentDigit;
			}
			number = number / 10;
		}
		std::cout << "Max: " << max << std::endl;
		std::cout << "Min: " << min << std::endl;
		std::cout << "Average: " << (max + min) / 2.0 << std::endl;
	}
	else
	{
		std::cout << "Invalide input!" << std::endl;
	}
	
	return 0;
}