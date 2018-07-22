#include<iostream>

void ExchangePleaces(int arr[], int l);
void Print(int arr[], int l);

int main()
{
	int arr[] = { 9, 6, 1, 2, 7, 3, 4 }; /*{ 1, 2, 4, 3, 5, 6, 7,8 };*/
	int len = std::end(arr) - std::begin(arr);
	ExchangePleaces(arr, len);
	Print(arr, len);
	std::cout << std::endl;

	return 0;
}

void ExchangePleaces(int arr[], int l)
{
	int temp;
	for (int i = 0, j = l - 1; i <= j; i++, j--)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void Print(int arr[], int l)
{
	for (int i = 0; i < l; i++)
	{
		std::cout << arr[i] << " ";
	}
}