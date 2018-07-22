#include <iostream>

void FillArrayWithAllCards(int cards[]);
void PrintCard(int currentCard);
void PrintColorOfCard(int num);

const int numberOfColor = 4;
const int numberOfCards = 52;

int main()
{
	int cards[numberOfCards];
	FillArrayWithAllCards(cards);

	int num;
	std::cout << "Enter number from 1 to 52: ";
	std::cin >> num;
	if (num > 0 && num < 53)
	{
		PrintCard(cards[num - 1]);
		PrintColorOfCard(num);
	}
	else
	{
		std::cout << "Invalide input" << std::endl;
	}

	return 0;
}

void FillArrayWithAllCards(int cards[])
{
	int count = 1;
	int card = 2;
	int index = 0;
	while (card < 15)
	{
		while (count <= numberOfColor)
		{
			cards[index] = card;
			index++;
			count++;
		}
		card++;
		count = 1;
	}
}

void PrintCard(int currentCard)
{
	switch (currentCard)
	{
	case 2:
		std::cout << currentCard;
		break;
	case 3:
		std::cout << currentCard;
		break;
	case 4:
		std::cout << currentCard;
		break;
	case 5:
		std::cout << currentCard;
		break;
	case 6:
		std::cout << currentCard;
		break;
	case 7:
		std::cout << currentCard;
		break;
	case 8:
		std::cout << currentCard;
		break;
	case 9:
		std::cout << currentCard;
		break;
	case 10:
		std::cout << currentCard;
		break;
	case 11:
		std::cout << "vale";
		break;
	case 12:
		std::cout << "dama";
		break;
	case 13:
		std::cout << "pop";
		break;
	case 14:
		std::cout << "aso";
		break;
	default:
		break;
	}
}

void PrintColorOfCard(int num)
{
	int rem = num % numberOfColor;

	switch (rem)
	{
	case 0:
		std::cout << " pika" << std::endl;
		break;
	case 1:
		std::cout << " spatiq" << std::endl;
		break;
	case 2:
		std::cout << " karo" << std::endl;
		break;
	case 3:
		std::cout << " kupa" << std::endl;
		break;
	default:
		break;
	}
}