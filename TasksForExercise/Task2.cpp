#include <iostream>
#include <random>
#include <ctime>

int main()
{
	srand(time(NULL));
	int randomNumber = rand() % 100 + 1;
	int number;
	std::cout << "Enter number in rage 1 to 100: ";
	std::cin >> number;
	int attempts = 0;
	if (number >= 1 && number <= 100)
	{
		while (true)
		{
			if (number == randomNumber)
			{
				std::cout << "Attempts: " << attempts << std::endl;
				break;
			}
			else if (number > randomNumber)
			{
				std::cout << "Down" << std::endl;
				attempts++;
			}
			else
			{
				std::cout << "Up" << std::endl;
				attempts++;
			}
			std::cout << "Enter new number: ";
			std::cin >> number;
		}
	}
	else
	{
		std::cout << "Invalide input!" << std::endl;
	}
	
	return 0;
}