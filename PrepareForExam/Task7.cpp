#include <iostream>

void EnterArray(int** arr, int n);
int Sum(int** arr, int n);
void DeleteArray(int** arr, int n);

int main()
{
	int n;
	std::cout << "Enter n:";
	std::cin >> n;
	if (n > 0)
	{
		int** arr = new int*[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = new int[n];
		}
		std::cout << "Enter the element of the matrix: " << std::endl;
		EnterArray(arr, n);
		std::cout << "The sum is: " << Sum(arr, n) << std::endl;

		DeleteArray(arr, n);
	}
	else
	{
		std::cout << "The number must be positeve!" << std::endl;
	}

	return 0;
}

void EnterArray(int ** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> arr[i][j];
		}
	}
}

int Sum(int ** arr, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j > i)
			{
				sum += arr[i][j];
			}
		}
	}
	return sum;
}

void DeleteArray(int ** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}