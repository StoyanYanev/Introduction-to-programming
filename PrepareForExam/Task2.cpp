#include <iostream>

const int LENGTH_OF_DATE = 6;
bool CheckDate(char date[]);

int main()
{
	char date[LENGTH_OF_DATE];
	std::cout << "Enter date in format (DD.MM): ";
	std::cin.getline(date, LENGTH_OF_DATE);
	int len = strlen(date);
	if (len == LENGTH_OF_DATE - 1)
	{
		std::cout << CheckDate(date) << std::endl;
	}
	else
	{
		std::cout << "Invalid date!" << std::endl;
	}

	return 0;
}

bool CheckDate(char date[])
{
	int coutDot = 0;
	int len = strlen(date);
	int index = 0;
	while (index < len)
	{
		if (date[index] == '.')
		{
			coutDot++;
		}
		index++;
	}
	if (coutDot == 1)
	{
		int day = (date[0] - '0') * pow(10, 1) + (date[1] - '0');
		int month = (date[3] - '0') * pow(10, 1) + (date[4] - '0');
		if (day >= 1 && day <= 31)
		{
			if (month >= 1 && month <= 12)
			{
				return true;
			}
		}
	}
	return false;
}