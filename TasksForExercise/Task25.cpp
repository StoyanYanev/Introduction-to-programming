#include<iostream>

int GetLenOfTheNumber(int num);
bool CheckTheNumberIsAutomorphic(int num, int p, int l);

int main()
{
	int num;
	std::cout << "Enter number: ";
	std::cin >> num;
	int p = pow(num, 2);
	int len = GetLenOfTheNumber(num);

	if (CheckTheNumberIsAutomorphic(num, p, len) == true)
	{
		std::cout << num << " -> Yes" << std::endl;
	}
	else
	{
		std::cout << num << " -> No" << std::endl;
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

bool CheckTheNumberIsAutomorphic(int num, int p, int l)
{
	bool isAutomorphic = true;
	while (l > 0)
	{
		if (p % 10 != num % 10)
		{
			isAutomorphic = false;
			break;
		}
		p = p / 10;
		num = num / 10;
		l--;
	}
	return isAutomorphic;
}