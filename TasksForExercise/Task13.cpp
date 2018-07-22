#include<iostream>

int main()
{
	int n;
	int k;
	std::cout << "Enter n: ";
	std::cin >> n;
	std::cout << "Enter k: ";
	std::cin >> k;

	if ((n >= 100 || n <= 1000) && (k >= 100 || k <= 1000))
	{
		int min = n;
		int max = n;
		if (min > k)
		{
			min = k;
		}
		else
		{
			max = k;
		}
		int count = 0;
		int currentNum;
		int currentDigit;
		for (int i = min; i <= max; i++)
		{
			currentNum = i;
			while (currentNum != 0)
			{
				currentDigit = currentNum % 10;
				if (currentDigit == 5)
				{
					count++;
				}
				currentNum /= 10;
			}
		}
		std::cout << count << std::endl;
	}
	else
	{
		std::cout << "Invalide input!" << std::endl;
	}

	return 0;
}