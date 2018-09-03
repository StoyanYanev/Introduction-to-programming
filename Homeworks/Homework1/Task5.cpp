#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main(){
	unsigned int num, firstDigit, lastDigit, newNum, len, power;
	cout << "Enter number: ";
	cin >> num;
	if (num > 0 && num <= (pow(2, 32) - 1))
	{
		len = log10(num) + 1;		/* find the length of the number*/
		power = pow(10, len - 1);
		lastDigit = num % 10;	/*get the last digit of the number*/
		firstDigit = num / power;	/*get the first digit of the number*/
		num = (num % power) / 10;
		newNum = lastDigit * power + num * 10 + firstDigit;
		cout << "The new number is: " << newNum << endl;
	}
	else
	{
		cout << "Invalide input! The number must be smaller than 2^32-1 and bigger than 0!" << endl;
	}
	return 0;
}
