#include <iostream>

int ScratchPosition(int num, int k);
int LengthOfNumber(int num);

int main()
{
	int num;
	int k;
	std::cout << "Enter number: ";
	std::cin >> num;
	std::cout << "Enter position: ";
	std::cin >> k;
	int len = LengthOfNumber(num);
	if (num > 0 && k > 0 && len >= k)
	{

		std::cout << "New number: " << ScratchPosition(num, k) << std::endl;
	}
	else
	{
		std::cout << "Invalide input!" << std::endl;
	}

	return 0;
}

int ScratchPosition(int num, int k)
{
	int currentPosition = 1;
	int newNumber = 0;
	while (num != 0)
	{
		if (currentPosition != k)
		{
			if (currentPosition > k)
			{
				newNumber += num % 10 * pow(10, currentPosition - 2);
			}
			else
			{
				newNumber += num % 10 * pow(10, currentPosition - 1);
			}
		}
		currentPosition++;
		num = num / 10;
	}
	return newNumber;
}

int LengthOfNumber(int num)
{
	int len = 0;
	int n = num;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return len;
}