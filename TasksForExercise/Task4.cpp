#include<iostream>

int main()
{
	int first = 0;
	int second = 0;
	int third = 0;

	for (int i = 100; i <= 999; i++)
	{
		first = i / 100;
		second = (i % 100) / 10;
		third = i % 10;
		if ((first != second) && (second != third) && (first != third))
		{
			std::cout << i << std::endl;
		}
	}
	return 0;
}