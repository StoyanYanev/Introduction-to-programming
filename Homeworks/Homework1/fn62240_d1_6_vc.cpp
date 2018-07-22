/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Stoyan Yanev
* @idnumber 62240
* @task 6
* @compiler VC
*
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
	const int maxheight = 25;
	int height;
	unsigned char symbol;
	cout << "Enter symbol: " << endl;
	cin >> symbol;
	cout << "Enter height of the triangle: " << endl;
	cin >> height;
	if (height > 0)
	{
		if (height <= maxheight)
		{
			for (int i = 1; i <= height; i++)
			{
				for (int j = 1; j <= height - i; j++) cout << " ";
				for (int j = 1; j <= i; j++) cout << symbol << " ";
				cout << "\n";
			}
			cout << "\n";
		}
		else
		{
			cout << "Enter smaller height then 25!" << endl;
		}
	}
	else{
		cout << "Invalide input! The height must be positive!" << endl;
	}
	return 0;
}