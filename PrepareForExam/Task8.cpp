#include <iostream>
#include <iomanip>

const int MAX_WIDTH = 80;
const int MAX_HEIGHT = 25;

void FillRectangle(int w, int h, char symbol);

int main()
{
	int n;
	int m;
	char symbol;
	std::cout << "Enter the width of the rectangle: ";
	std::cin >> n;
	std::cout << "Enter the height of the rectangle: ";
	std::cin >> m;
	std::cout << "Enter the symbol: ";
	std::cin >> symbol;

	if ((n >= 1 && n <= MAX_WIDTH) && (m >= 1 && m <= MAX_HEIGHT))
	{
		FillRectangle(n, m, symbol);
	}
	else
	{
		std::cout << "Invalide input!" << std::endl;
	}

	return 0;
}

void FillRectangle(int w, int h, char symbol)
{
	int whitespaceWidth = (MAX_WIDTH - w) / 2;
	int whitespaceHeight = (MAX_HEIGHT - h) / 2;

	for (int i = 0; i < h; i++)
	{
		std::cout << std::endl;
	}
	for (int i = 0; i < h; i++)
	{
		std::cout << std::setw(whitespaceWidth);
		for (int i = 0; i < w; i++)
		{
			std::cout << symbol;
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < h; i++)
	{
		std::cout << std::endl;
	}
}