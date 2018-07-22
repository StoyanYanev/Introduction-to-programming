/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Stoyan Yanev
* @idnumber 62240
* @task 2
* @compiler VC
*
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int reversedNumber(int);

int main(){
	int num, revNum;
	cout << "Enter positive number: " << endl;
	cin >> num;
	if (num < 0)
	{
		cout << "Invalide input! The number must be positive!" << endl;
	}
	else
	{
		revNum = reversedNumber(num);
		cout << "The number in hex format is: " << hex << revNum << endl;
	}
	return 0;
}
int reversedNumber(int num){
	int reversedNum = 0, remainder;
	while (num > 0)
	{
		remainder = num % 10;
		reversedNum = reversedNum * 10 + remainder;
		num /= 10;
	}
	return	reversedNum;
}
