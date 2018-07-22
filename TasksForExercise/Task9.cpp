#include <iostream>

int main()
{
	const int n = 4;

	int matrix[n][n] =
	{
		{ 1,2,3,4 },
		{ 5,6,7,8 },
		{ 9,10,11,12 },
		{ 13,14,15,16 }
	};

	int d = n - 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i == j) || (i == d) || (j == d))
			{
				matrix[i][j] = 0;
			}
		}
		d--;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}