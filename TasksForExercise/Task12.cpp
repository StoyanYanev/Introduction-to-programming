#include <iostream>
#include<time.h>

int main()
{
	srand(time(NULL));
	const int n = 4;
	int matrix[n][n];

	//fill array with random numbers
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrix[i][j] = i + rand() % 100 - i;
		}
	}

	//print array 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	//Clockwise Rotation

	int newMatrix[n][n];
	std::cout << std::endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1,  p = 0; j >= 0 , p < n; j--, p++)
		{
			newMatrix[i][p] = matrix[j][i];
		}
	}

	//print new array 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << newMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	return 0;
}