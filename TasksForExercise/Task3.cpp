#include<iostream>

int SumOneDigitsNumber();
int SumTwoDigitsNumber(int num);

int main()
{
	int number;
	int sum = 0;
	std::cout << "Enter number between 10 and 99: ";
	std::cin >> number;
	if (number >= 10 && number <= 99)
	{
		sum = SumOneDigitsNumber() + SumTwoDigitsNumber(number);
		std::cout << "The sum is: " << sum << std::endl;
	}
	else
	{
		std::cout << "Invalide input!" << std::endl;
	}
	//********************Ànother way********************************
	/*for (int i = 0; i < number; ++i) {
		sum += (i / 10) + (i % 10);
	}*/
	
	return 0;
}

int SumOneDigitsNumber()
{
	int s = 0;
	for (int i = 1; i <= 9; i++)
	{
		s += i;
	}
	return s;
}

int SumTwoDigitsNumber(int num)
{
	int s = 0;
	int saveCurrentNum;
	for (int i = 10; i < num; i++)
	{
		saveCurrentNum = i;
		while (saveCurrentNum != 0)
		{
			s += saveCurrentNum % 10;
			saveCurrentNum = saveCurrentNum / 10;
		}
	}
	return s;
}