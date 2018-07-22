///**
//*
//* Solution to homework task
//* Introduction to programming course
//* Faculty of Mathematics and Informatics of Sofia University
//* Winter semester 2017/2018
//*
//* @author Stoyan Yanev
//* @idnumber 62240
//* @task 3
//* @compiler VC
//*
//*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){

	const unsigned int SECONDS_IN_24_HOURS = 86400; /*86 400 are the seconds in 24 hours = 24 * 3600 */
	const unsigned int SECONDS_IN_60_MINUTES = 3600;
	const unsigned int MINUTES = 60;

	int s, m, h;
	cout << "Enter seconds: ";
	cin >> s;

	if (s > 0 && s < SECONDS_IN_24_HOURS)
	{
		m = (s % SECONDS_IN_60_MINUTES) / MINUTES; /* find how many minutes have in 's' seconds*/
		h = s / SECONDS_IN_60_MINUTES;			   /* find how many hours have in 's' seconds*/
		cout << "HH:MM = ";
		cout << setfill('0') << setw(2) << h << ":";
		cout << setfill('0') << setw(2) << m << endl;
	}
	else{
		cout << "Invalide input! The seconds must be positive!" << endl;
	}
	return 0;
}