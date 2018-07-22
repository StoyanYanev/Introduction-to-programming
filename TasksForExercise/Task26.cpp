#include<iostream>

int AscendingOrder(int startPosition, int endPosition, int sequence[]);
int DescendingOrder(int startPosition, int endPosition, int sequence[]);

int main()
{
	int sequence[] = { 1,3,5,6,4,2 };
	int len = std::end(sequence) - std::begin(sequence);
	int middle = len / 2;
	int firstElement = 0;

	if (len >= 5 && len <= 55)
	{
		bool isBigger = sequence[firstElement] > sequence[firstElement + 1];
		if (isBigger == true)
		{
			// if the sequence (from the first element to the middle element) is in descending order
			// and the sequence (from the middle element to the last element) is in ascending order
			// then the sequence (from the first element to the last element) is triangle
			if (DescendingOrder(firstElement, middle, sequence) == 0 && AscendingOrder(middle, len, sequence) == 0)
			{
				std::cout << "Yes" << std::endl; //the sequence is triangle
			}
			else
			{
				std::cout << "No" << std::endl; //the sequence is not triangle
			}
		}
		else
		{
			// if the sequence (from the first element to the middle element) is in ascending order 
			// and the sequence (from the middle element to the last element) is in descending order
			// then the sequence (from the first element to the last element) is triangle
			if (AscendingOrder(firstElement, middle, sequence) == 0 && DescendingOrder(middle, len - 1, sequence) == 0)
			{
				std::cout << "Yes" << std::endl; //the sequence is triangle
			}
			else
			{
				std::cout << "No" << std::endl; //the sequence is not triangle
			}
		}
	}
	else
	{
		std::cout << "Invalide sequence!" << std::endl;
	}

	return 0;
}

int AscendingOrder(int startPosition, int endPosition, int sequence[])
{
	int count = 0; // count how many times the sign <= has changed

	for (int i = startPosition; i <= endPosition - 1; i++)
	{
		if (sequence[i] <= sequence[i + 1])
		{
		}
		else
		{
			count++;
		}
	}

	return count; // if the sign has not changed then the sequence is in ascending order
}

int DescendingOrder(int startPosition, int endPosition, int sequence[])
{
	int count = 0; // count how many times the sign >= has changed

	for (int i = startPosition; i <= endPosition - 1; i++)
	{
		if (sequence[i] >= sequence[i + 1])
		{
		}
		else
		{
			count++;
		}
	}

	return count; // if the sign has not changed then the sequence is in descending order
}