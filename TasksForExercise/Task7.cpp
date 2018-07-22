#include <iostream>

int main()
{
	int height;
	std::cout << "Enter depth: ";
	std::cin >> height;
	int d = 1;
	int currentHeight = 0;
	const int night = 1;
	const int day = 2;
	if (height > 0)
	{
		while (true)
		{
			currentHeight += day;
			if (currentHeight >=height)
			{
				std::cout << d << std::endl;
				break;
			}
			currentHeight--;
			d++;
		}
	}
	else
	{
		std::cout << "Invalide input!" << std::endl;
	}
	
	return 0;
}