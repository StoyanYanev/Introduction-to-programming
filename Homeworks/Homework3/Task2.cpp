#include<iostream>
#include <vector>

const int UP_LIMIT = 10000;
const int DOWN_LIMIT = 1;

const std::string ONES[] = {
	"", "one", "two", "three", "four", "five",
	"six", "seven", "eight", "nine", "ten",
	"eleven", "twelve", "thirteen", "fourteen", "fifteen",
	"sixteen", "seventeen", "eighteen", "nineteen"
};

const std::string TENS[] = {
	"","ten","twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

const std::string UNITS[] = { "","","hundred", "thousand" };

int GetLengthOfTheNumber(int num);
void TwoDigitNumbers(int num, int len, std::vector<std::string> &digitInEnglish);
void ThreeDigitNumbers(int num, int len, std::vector<std::string> &digitInEnglish);
void ForthDigitNumbers(int num, int len, std::vector<std::string> &digitInEnglish);
void PrintNumberOfSymbols(std::vector<std::string> &digitInEnglish);

int main()
{
	int number;
	std::cout << "Enter number (between 1 to 10 000): ";
	std::cin >> number;

	if (number >= DOWN_LIMIT && number <= UP_LIMIT) /* check if the number is valid */
	{
		std::vector<std::string> digitInEnglish; /* save the name of the digits */

		int len = GetLengthOfTheNumber(number);

		if (len == 1)
		{
			digitInEnglish.push_back(ONES[number]);
		}
		else if (len == 2)
		{
			TwoDigitNumbers(number, len, digitInEnglish);
		}
		else if (len == 3)
		{
			ThreeDigitNumbers(number, len, digitInEnglish);
		}
		else if (len == 4)
		{
			ForthDigitNumbers(number, len, digitInEnglish);
		}
		else /* length is 5 and the number can be only 10 000 */
		{
			int firstDigit = number / pow(10, len - 1);
			digitInEnglish.push_back(TENS[firstDigit]);
			digitInEnglish.push_back(UNITS[len - 2]);
		}

		PrintNumberOfSymbols(digitInEnglish);
	}
	else
	{
		std::cout << "Invalid number!" << std::endl;
	}

	return 0;
}

int GetLengthOfTheNumber(int num)
{
	int count = 0;
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return count;
}

void TwoDigitNumbers(int num, int len, std::vector<std::string> &digitInEnglish)
{
	if (num >= 10 && num <= 19)
	{
		digitInEnglish.push_back(ONES[num]);
	}
	else
	{
		int digit;
		while (len > 0)
		{
			/* get the first digit */
			digit = num / pow(10, len - 1); 
			digit %= 10;
			if (digit != 0) /* if the digit isn't 0 */
			{
				if (len == 2)
				{
					digitInEnglish.push_back(TENS[digit]);
				}
				else
				{
					digitInEnglish.push_back(ONES[digit]);
				}
			}
			len--;
		}
	}
}

void ThreeDigitNumbers(int num, int len, std::vector<std::string> &digitInEnglish)
{
	int p = pow(10, len - 1); /* get the first digit */
	digitInEnglish.push_back(ONES[num / p]); /* push the first digit in the vector */
	digitInEnglish.push_back(UNITS[len - 1]);

	int newNum = num % p;
	if (newNum > 0) /* if the new number isn't 0 */
	{
		int newLen = GetLengthOfTheNumber(newNum);
		TwoDigitNumbers(newNum, newLen, digitInEnglish);
	}
}

void ForthDigitNumbers(int num, int len, std::vector<std::string> &digitInEnglish)
{
	int p = pow(10, len - 1);
	digitInEnglish.push_back(ONES[num / p]);
	digitInEnglish.push_back(UNITS[len - 1]);

	int newNum = num % p;
	int newLen = GetLengthOfTheNumber(newNum);
	if (newNum != 0)
	{
		if (newLen > 0 && newLen <= 2)
		{
			TwoDigitNumbers(newNum, newLen, digitInEnglish);
		}
		else
		{
			ThreeDigitNumbers(newNum, newLen, digitInEnglish);
		}
	}
}

void PrintNumberOfSymbols(std::vector<std::string> &digitInEnglish)
{
	int numberOfSymbols = 0;
	for (int i = 0; i < digitInEnglish.size(); i++)
	{
		numberOfSymbols += digitInEnglish[i].length();
	}

	std::cout << numberOfSymbols << std::endl;
}