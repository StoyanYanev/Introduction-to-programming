#include<iostream>

int main()
{
	int firstSequence[] = { 1, 2, 3 };
	int secondSequence[] = { 2, 1, 2, 3, 4, 5, 1, 2, 3, 1, 2 };
	int lenOfFirstSequence = std::end(firstSequence) - std::begin(firstSequence);
	int lenOfSecondSequence = std::end(secondSequence) - std::begin(secondSequence);
	int count = 0;

	for (int i = 0; i < lenOfSecondSequence; i++)
	{
		bool isFind = true;
		for (int j = 0; j < lenOfFirstSequence; j++)
		{
			if (firstSequence[j] != secondSequence[i + j])
			{
				isFind = false;
				break;
			}

		}

		if (isFind == true)
		{
			count++;
		}
	}

	std::cout << "The sequence ";
	for (int i = 0; i < lenOfFirstSequence; i++)
	{
		std::cout << firstSequence[i] << " ";
	}
	std::cout << " is found " << count << " times" << std::endl;

	return 0;
}