#include<iostream>

int FindZeroElements(int arr[],int len);
void FillNewArrayWithElements(int *newArr, int len,int arr[]);
void PrintElementsInRevOrder(int *arr, int n);
void PrintArray(int *arr, int n);

int main()
{
	int arr[] = { 1, 0,0,5,10,666,0,3,0,8 };
	int len = std::end(arr) - std::begin(arr);
	int newLen = len - FindZeroElements(arr, len);
	int *newArr = new int[newLen];
	FillNewArrayWithElements(newArr, len, arr);
	PrintArray(newArr, newLen);
	std::cout << std::endl;
	PrintElementsInRevOrder(newArr, newLen);
	std::cout << std::endl;

	delete[] newArr;

	return 0;
}

int FindZeroElements(int arr[],int len)
{
	int count = 0;
	int i = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == 0)
		{
			count++;
		}
	}
	return count;
}

void FillNewArrayWithElements(int * newArr, int len, int arr[])
{
	int index = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] != 0)
		{
			newArr[index] = arr[i];
			index++;
		}
	}
}

void PrintElementsInRevOrder(int * arr, int n)
{
	for (int i = n-1; i >= 0; i--)
	{
		std::cout << arr[i] << " ";
	}
}

void PrintArray(int * arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}
}