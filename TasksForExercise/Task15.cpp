#include <iostream>

void MorseCode(int num);
void ReverseNumber(int &num, int len);
int NumberOfDigits(int num);

int main()
{
	int num;
	std::cout << "Wnter num: ";
	std::cin >> num;
	if (num >= 10 && num <= 30000)
	{
		int len = NumberOfDigits(num);
		ReverseNumber(num, len);
		while (num != 0)
		{
			MorseCode(num % 10);
			num /= 10;
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Invalide number!" << std::endl;
	}

	return 0;
}

void MorseCode(int num)
{
	switch (num)
	{
	case 0:
		std::cout << "----- ";
		break;
	case 1:
		std::cout << ".... ";
		break;
	case 2:
		std::cout << "...- ";
		break;
	case 3:
		std::cout << "..-- ";
		break;
	case 4:
		std::cout << "..--- ";
		break;
	case 5:
		std::cout << ".---- ";
		break;
	case 6:
		std::cout << "-... ";
		break;
	case 7:
		std::cout << "--.. ";
		break;
	case 8:
		std::cout << "---.. ";
		break;
	case 9:
		std::cout << "----. ";
		break;
	}
}

int NumberOfDigits(int num)
{
	int count = 0;
	while (num != 0)
	{
		count++;
		num /= 10;
	}
	return count;
}

void ReverseNumber(int & num, int len)
{
	int newNum = 0;
	while (num != 0)
	{
		newNum += num % 10 * pow(10, len-1);
		len--;
		num /= 10;
	}
	num = newNum;
}