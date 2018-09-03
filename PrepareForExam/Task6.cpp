#include <iostream>

void SortArray(int* arr, int n);
void EnterArray(int* arr, int n);
void PrintArray(int* arr, int n);
int* UnionTwoArrays(int* firstArr, int* secondArr, int n, int m);

int main()
{
	int n;
	int m;
	std::cout << "Enter the number of the elements of the first array: ";
	std::cin >> n;
	std::cout << "Enter the number of the elements of the second array: ";
	std::cin >> m;
	int * firstArr = new int[n];
	int *secondArr = new int[m];

	std::cout << "Enter the elements of the first array: " << std::endl;
	EnterArray(firstArr, n);
	std::cout << "Enter the elements of the second array: " << std::endl;
	EnterArray(secondArr, m);
	SortArray(firstArr, n);
	SortArray(secondArr, m);

	int* newArr = UnionTwoArrays(firstArr, secondArr, n, m);
	SortArray(newArr, m + n);
	PrintArray(newArr, m + n);
	std::cout << std::endl;

	delete[] firstArr;
	delete[] secondArr;

	return 0;
}

void SortArray(int * arr, int n)
{
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void EnterArray(int * arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
}

int * UnionTwoArrays(int * firstArr, int * secondArr, int n, int m)
{
	int* newArr = new int[m + n];
	int index = n;
	for (int i = 0; i < n; i++)
	{
		newArr[i] = firstArr[i];
	}
	for (int j = 0; j < m; j++)
	{
		newArr[index] = secondArr[j];
		index++;
	}

	return newArr;
}

void PrintArray(int * arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
}