#include <iostream>

void EnterMatrix(int** arr, int n);
void ÒransposedMatrix(int** arr, int n);
void PrintMatrix(int** arr, int n);
void DeleteMatrix(int** arr, int n);

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
		EnterMatrix(arr, n);
		ÒransposedMatrix(arr, n);
		PrintMatrix(arr, n);
		DeleteMatrix(arr, n);
	}
	else
	{
		std::cout << "The number must be positeve!" << std::endl;
	}

	return 0;
}

void EnterMatrix(int ** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cin >> arr[i][j];
		}
	}
}

void ÒransposedMatrix(int ** arr, int n)
{
	int** newArr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		newArr[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			newArr[i][j] = arr[j][i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = newArr[i][j];
		}
	}
	DeleteMatrix(newArr, n);
}

void PrintMatrix(int ** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void DeleteMatrix(int ** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}