/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Stoyan Yanev
* @idnumber 62240
* @task 3
* @compiler VC
*
*/

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

const long long MAXNUM = 4294967296; /*2^32 = 4294967296*/
void getDigitsOfNumber(long long n, vector<int> &digits);
void theLongestSequenceOfRepeatDigits(vector<int> digits);
void printRepeatDigits(vector<int> digits, int countRepeatDig);

int main(){
	long long num;
	cin >> num;
	if (num >= -MAXNUM && num <= MAXNUM)
	{
		num = abs(num);
		vector<int> digitsOfNumber;
		getDigitsOfNumber(num, digitsOfNumber);
		sort(digitsOfNumber.begin(), digitsOfNumber.end());
		theLongestSequenceOfRepeatDigits(digitsOfNumber);
	}
	else
	{
		cout << -1 << endl;
	}
}
void getDigitsOfNumber(long long n, vector<int> &digits){
	int digit;
	while (n > 0)
	{
		digit = n % 10;
		digits.push_back(digit);
		n = n / 10;
	}
}
void theLongestSequenceOfRepeatDigits(vector<int> digits){
	int maxRepeatDigitInNumber = 0;
	int count = 1;
	for (int i = 0; i < digits.size() - 1; i++)
	{
		if (digits[i] == digits[i + 1])
		{
			count += 1;
		}
		else
		{
			if (count > maxRepeatDigitInNumber)
			{
				maxRepeatDigitInNumber = count;
			}
			count = 1;
		}
	}
	if (count > maxRepeatDigitInNumber)
	{
		maxRepeatDigitInNumber = count;
	}
	printRepeatDigits(digits, maxRepeatDigitInNumber);
}
void printRepeatDigits(vector<int> digits, int countRepeatDig){
	int count = 1;
	for (int i = 0; i < digits.size() - 1; i++)
	{
		if (digits[i] == digits[i + 1])
		{
			count += 1;
		}
		if (count == countRepeatDig)
		{
			cout << digits[i] << "->" << countRepeatDig << endl;
			count = 1;
		}
	}
}