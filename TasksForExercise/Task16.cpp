#include<iostream>

void Distance(int n, int *coordinatesForX, int *coordinatesForY);
void EnterCoordinates(int n, int *coordinatesForX, int *coordinatesForY);

int main()
{
	int n;
	std::cout << "Enter n: ";
	std::cin >> n;
	if (n > 1)
	{
		int *coordinatesForX = new int[n];
		int *coordinatesForY = new int[n];
		EnterCoordinates(n, coordinatesForX, coordinatesForY);
		std::cout << std::endl;
		Distance(n, coordinatesForX, coordinatesForY);
		delete[] coordinatesForX;
		delete[] coordinatesForY;
	}
	else
	{
		std::cout << "Invalide input!" << std::endl;
	}
	return 0;
}

void Distance(int n, int * coordinatesForX, int * coordinatesForY)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			std::cout << "Distance between: " << "(" << coordinatesForX[i] << "," << coordinatesForY[i] << ") " << "and " << "(" << coordinatesForX[j] << "," << coordinatesForY[j] << ") is: " <<
				sqrt(pow(coordinatesForX[j] - coordinatesForX[i], 2) +
					pow(coordinatesForY[j] - coordinatesForY[i], 2)) << std::endl;
			std::cout << std::endl;
		}
	}
}

void EnterCoordinates(int n, int * coordinatesForX, int * coordinatesForY)
{
	int index = 0;
	while (index < n)
	{
		std::cout << "Enter coordinate X" << index << ": ";
		std::cin >> coordinatesForX[index];
		std::cout << "Enter coordinate Y" << index << ": ";
		std::cin >> coordinatesForY[index];
		index++;
	}
}