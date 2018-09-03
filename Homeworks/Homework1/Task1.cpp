#include <iostream>
#include <string>

using namespace std;

int main(){
	int firstNum, secondNum;
	bool isIncreasing = false;
	cout << "Enter numbers: " << endl;
	cin >> firstNum;
	if (firstNum > 0)
	{
		cin >> secondNum;
		if (secondNum > 0)
		{
			if (secondNum > firstNum)	/*Enter two numbers and determine whether the sequence is increasing or decreasing*/
			{
				isIncreasing = true;
			}

			while (true)
			{
				firstNum = secondNum;
				cin >> secondNum;
				if (secondNum <= 0)
				{
					if (isIncreasing == true)
					{
						cout << "The sequence is increasing!" << endl;
					}
					else{
						cout << "The sequence is decreasing!" << endl;
					}
					break;
				}
				else
				{
					if (isIncreasing == true)
					{
						if (secondNum < firstNum)
						{
							cout << "The sequence is undefined!" << endl;
							break;
						}
					}
					else
					{
						if (firstNum < secondNum)
						{
							cout << "The sequence is undefined!" << endl;
							break;
						}
					}
				}
			}
		}
		else{
			cout << "The sequence is undefined!" << endl;
		}
	}
	else{
		cout << "The sequence is undefined!" << endl;
	}
	return 0;
};
