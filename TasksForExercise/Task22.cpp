#include<iostream>

int GetLenOfTheNumber(int num);
int GetReversedNumber(int num, int len);

int main()
{
	int num;
	std::cout << "Enter number: ";
	std::cin >> num;
	int l = GetLenOfTheNumber(num);
	int newNumber = GetReversedNumber(num, l);

	if (newNumber == num)
	{
		std::cout << "The number is palindrome!" << std::endl;
	}
	else
	{
		std::cout << "The number is not palindrome!" << std::endl;
	}

	return 0;
}

int GetLenOfTheNumber(int num)
{
	int count = 0;
	while (num != 0)
	{
		count++;
		num = num / 10;
	}
	return count;
}

int GetReversedNumber(int num, int len)
{
	int newNumber = 0;
	while (num != 0)
	{
		newNumber += num % 10 * pow(10, len-1);
		len--;
		num = num / 10;
	}
	return newNumber;
}