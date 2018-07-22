#include<iostream>

void SumOfNOD(int n, int* arr);
void PrintNumber(int* arr);

int main()
{
	// Find all perfect numbers between 1 and n
	int n;
	std::cout << "Enter number: ";
	std::cin >> n;
	int* saveNumbers = new int[n];
	if (n > 1)
	{
		SumOfNOD(n, saveNumbers);
		std::cout << "Perfect number/s between 1 and " << n << ": ";
		PrintNumber(saveNumbers);

		//***********************************************************************
		// Check if the entered number is perfect
		/*int sum = 0;
		for (int i = 1; i < n; i++)
		{
			if (n % i == 0 )
			{
				sum += i;
			}
		}
		if (sum == n)
		{
			std::cout << "The number is a perfect!!" << std::endl;
		}
		else
		{
			std::cout << "The number is not a perfect!!" << std::endl;
		}*/
	}
	else
	{
		std::cout << "Invalide input!" << std::endl;
	}
	delete[] saveNumbers;
	return 0;
}

void SumOfNOD(int n, int* arr)
{
	int sum = 0;
	int index = 0;
	for (int i = 2; i < n; i++)
	{
		for (int j = 1; j < n - 1; j++)
		{
			if (i % j == 0 && i > j)
			{
				sum += j;
			}
		}
		if (sum == i)
		{
			arr[index] = i;
			index++;
		}
		sum = 0;
	}
	arr[index] = 0;
}

void PrintNumber(int * arr)
{
	while (*arr != '\0')
	{
		std::cout << *arr << " ";
		arr++;
	}
	std::cout << std::endl;
}