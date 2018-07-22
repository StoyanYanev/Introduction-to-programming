#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int  a, b, c;
	cout << "Enter a= ";
	cin >> a;
	cout << "Enter b= ";
	cin >> b;
	cout << "Enter c= ";
	cin >> c;
	if (a < 0 && b < 0 && c < 0)
	{
		cout << "Invalid input!" << endl;
	}
	else if (a > 100000 && b > 100000 && c > 100000) {
		cout << "The number must be smaller then 100000!" << endl;
	}
	else {
		const int length = 10;

		int line[length];
		int l = length; //save the length
		for (int i = 0; i < length; i++)
		{
			if (i % a == 0)
			{
				line[i] = 0;
			}

			if ((l - b) >= 0)
			{
				if (line[l - b] != 0)
				{
					line[l - b] = 1;
				}
				l = l - b;
			}
		}
		int count = 0;
		for (int i = 0; i < length; i++)
		{
			if (i + c < length)
			{
				if (line[i] == 0 && line[i + c] == 1)
				{
					count += 1;
				}
				else if (line[i] == 1 && line[i + c] == 0)
				{
					count += 1;
				}
			}
		}
		//cout << count << endl;
		cout << "The lenght of the line is: " << length - count  << endl;
	}

	return 0;
}