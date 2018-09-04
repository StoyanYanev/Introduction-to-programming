#include <iostream>

const int MAX_REPEAT_DIGITS = 5; // even numbers from 0 to 9

int NumberOfDigits(long num);
void GetDigitsFromNumber(long num, int* arrayOfDigits, int len);
bool CheckIsAdd(int* num, int len, int number);
int* CheckNums(long num1, int long num2);

int main()
{
	int firstNum, secondNum;
	std::cout << "Enter the first number: ";
	std::cin >> firstNum;
	std::cout << "Enter the second number: ";
	std::cin >> secondNum;

	int * arr = CheckNums(firstNum, secondNum);
	int ind = 0;
	while (arr[ind] != '\0')
	{
		std::cout << arr[ind] << " ";
		ind++;
	}
	std::cout << std::endl;
	delete[] arr;

	return 0;
}
int NumberOfDigits(long num)
{
	int len = 0;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return len;
}
void GetDigitsFromNumber(long num, int * arrayOfDigits, int len)
{
	for (int i = 0; i < len; i++)
	{
		arrayOfDigits[i] = num % 10;
		num = num / 10;
	}
}
bool CheckIsAdd(int * num, int len, int number)
{
	for (int i = 0; i < len; i++)
	{
		if (num[i] == number)
		{
			return false;
		}
	}
	return true;
}
int* CheckNums(long num1, int long num2)
{
	int firstLengthOfNum = NumberOfDigits(num1);
	int secondLengthOfNum = NumberOfDigits(num2);

	int* firstNum = new int[firstLengthOfNum];
	int* secondNum = new int[secondLengthOfNum];

	int* repeatDigits = new int[MAX_REPEAT_DIGITS];
	int index = 0;

	GetDigitsFromNumber(num1, firstNum, firstLengthOfNum);
	GetDigitsFromNumber(num2, secondNum, secondLengthOfNum);

	for (int i = 0; i < firstLengthOfNum; i++)
	{
		for (int j = 0; j < secondLengthOfNum; j++)
		{
			if ((firstNum[i] == secondNum[j]) && (firstNum[i] % 2 == 0))
			{
				if (CheckIsAdd(repeatDigits, MAX_REPEAT_DIGITS, firstNum[i]) == true)
				{
					repeatDigits[index] = firstNum[i];
					index++;
				}
			}
		}
	}
	repeatDigits[index] = '\0';
	delete[] firstNum;
	delete[] secondNum;

	return repeatDigits;
}