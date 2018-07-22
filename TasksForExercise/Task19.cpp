#include<iostream>

int main()
{
	int arr[] = { 1,2,2,3,3,4,4,4,4,4,5,5,5 };
	//int arr[] = { 1,2,3,4 };
	int len = std::end(arr) - std::begin(arr);
	int maxSequence = 1;
	int currentSequence = 1;
	int element;
	for (int i = 0; i < len ; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			currentSequence++;
		}
		else
		{
			if (currentSequence > maxSequence)
			{
				maxSequence = currentSequence;
				element = arr[i];
			}
			currentSequence = 1;
		}
	}
	if (maxSequence > 1)
	{
		std::cout << "Max sequence is: " << element << " with size: " << maxSequence << std::endl;
	}
	else
	{
		std::cout << "There isn't max sequence!" << std::endl;
	}
	return 0;
}