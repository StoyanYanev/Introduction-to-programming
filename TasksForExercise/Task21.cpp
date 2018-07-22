#include <iostream>

int main()
{
	int n;
	std::cout << "Enter n: ";
	std::cin >> n;
	int *sequence = new int[n];

	std::cout << "Enter the elements of the sequence: " << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cin >> sequence[i];
	}

	bool isSymmetrical = true;
	for (int i = 0; i < n / 2; i++)
	{
		if (sequence[i] != sequence[n - 1 - i])
		{
			isSymmetrical = false;
		}
	}

	if (isSymmetrical == true)
	{
		std::cout << "The sequence is symmetrical!" << std::endl;
	}
	else
	{
		std::cout << "The sequence is not symmetrical!" << std::endl;
	}

	delete[] sequence;

	return 0;
}