#include<iostream>

void EnterElementsOfArray(int* arr, int n);
bool CheckSequenceIsZigzag(int* arr, int n);

int main()
{
	int n;
	std::cout << "Enter n: ";
	std::cin >> n;
	int* arr = new int[n];
	std::cout << "Enter the elements of array:" << std::endl;
	EnterElementsOfArray(arr, n);
	bool isZigzag = CheckSequenceIsZigzag(arr, n);
	if (isZigzag == true)
	{
		std::cout << "The sequence is zigzag!" << std::endl;
	}
	else
	{
		std::cout << "The sequence is not zigzag!" << std::endl;
	}

	delete[] arr;

	return 0;
}

void EnterElementsOfArray(int * arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}
}

bool CheckSequenceIsZigzag(int * arr, int n)
{
	bool isZigzag = true;
	for (int i = 0; i < n-1; i++)
	{
		if (i % 2 == 0)
		{
			if (arr[i] > arr[i + 1])
			{
				isZigzag = false;
				break;
			}
		}
		else
		{
			if (arr[i] < arr[i + 1])
			{
				isZigzag = false;
				break;
			}
		}
	}

	return isZigzag;
}