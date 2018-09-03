#include <iostream>

int DigitPos(long num, int k);
int NumberOfDigits(int num);

int main()
{
	int number, pos;
	std::cout << "Enter number: ";
	std::cin >> number;
	std::cout << "Enter position: ";
	std::cin >> pos;
	std::cout << "The number in position " << pos << " is: " << DigitPos(number, pos) << std::endl;

	return 0;
}

int DigitPos(long num, int k)
{
	int len = NumberOfDigits(num);
	if (k > len)
	{
		return -1;
	}
	else
	{
		int index = len;
		int currentDigit = 0;
		while (index > 0)
		{
			currentDigit = num % 10;
			if (index == k)
			{
				return currentDigit;
			}
			num = num / 10;
			index--;
		}
	}
	return -1;
}

int NumberOfDigits(int num)
{
	if (num == 0)
	{
		return 1;
	}
	else
	{
		int count = 0;
		while (num != 0)
		{
			num = num / 10;
			count++;
		}
		return count;
	}
}