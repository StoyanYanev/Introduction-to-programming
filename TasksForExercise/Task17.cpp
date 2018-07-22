#include <iostream>

int FibonacciNumber(int num);

int main()
{
	int n;
	std::cout << "Enter number: ";
	std::cin >> n;
	std::cout << "Fibonacci number: " << FibonacciNumber(n) << std::endl;
	
	return 0;
}

int FibonacciNumber(int num)
{
	int currrent = 1;
	int prev = 0;
	int next = 0;

	for (int i = 1; i < num; i++)
	{
		next = currrent + prev;
		prev = currrent;
		currrent = next;
	}
	return next;
}