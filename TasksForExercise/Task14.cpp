#include <iostream>

void EnterElementOfTheVector(int* arr, int n);
int * MultiplicarionVectors(int *first, int *second, int n);
void PrintVector(int *arr, int n);
int main()
{
	int n;
	std::cout << "Enter n: ";
	std::cin >> n;

	int *firstVector = new int[n];
	int *secondVector = new int[n];

	std::cout << "Enter the element of the first vector:" << std::endl;
	EnterElementOfTheVector(firstVector, n);
	std::cout << "Enter the element of the second vector:" << std::endl;
	EnterElementOfTheVector(secondVector, n);

	int*multiplicarionVector = new int[n];
	multiplicarionVector = MultiplicarionVectors(firstVector, secondVector, n);
	std::cout << "The multiplicarion vector is: ";
	PrintVector(multiplicarionVector, n);
	std::cout << std::endl;

	delete[] firstVector;
	delete[] secondVector;
	delete[] multiplicarionVector;

	return 0;
}

void EnterElementOfTheVector(int * arr, int n)
{
	int index = 0;
	while (index < n)
	{
		std::cin >> arr[index];
		index++;
	}
}

int * MultiplicarionVectors(int * first, int * second, int n)
{
	int*multiplicarionVector = new int[n];
	for (int i = 0; i < n; i++)
	{
		multiplicarionVector[i] = first[i] * second[i];
	}
	return multiplicarionVector;
}

void PrintVector(int * arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
}