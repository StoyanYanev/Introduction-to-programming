#include<iostream>

int main()
{
	int a1;
	int d;
	int len;
	std::cout << "Enter the first member of the sequence: ";
	std::cin >> a1;
	std::cout << "Enter the step of the sequence: ";
	std::cin >> d;
	std::cout << "Enter the number of members in the sequence: ";
	std::cin >> len;

	int prevoiusMember = 0;
	std::cout << a1 << " ";
	for (int i = 1; i < len; i++)
	{
		prevoiusMember += a1 + d;
		std::cout << prevoiusMember << " ";
	}
	std::cout << std::endl;

	return 0;
}