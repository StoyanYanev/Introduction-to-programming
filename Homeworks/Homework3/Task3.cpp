#include<iostream>
#include <string>

struct Date
{
	int day;
	int month;
	int year;
};

/* save the number of the days for every month */
const int MONTH_DAYS[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; 
const int DAYS_IN_LEAP_YEAR = 366;
const int DAYS_IN_YEAR = 365;
const int MAX_LENGTH_OF_DATE = 10;

const Date START_DATE = { 1, 1, 2000 };

bool CheckTheDateIsValid(std::string date);
bool CheckTheDigitsOfTheDate(const std::string date);
bool IsLeap(int year);
int GetDigits(std::string date, int startIndex, int endIndex);
int FindNumberOfWeeks(Date endDate);

int main()
{
	std::string date;
	std::cout << "Enter the date in format (DD.MM.YYYY), the year should be after 2000 : ";
	std::cin >> date;

	if (date.length() == MAX_LENGTH_OF_DATE && CheckTheDateIsValid(date) == true)
	{
		int endIndex = date.find('.', 0);
		Date endDate;
		endDate.day = GetDigits(date, 0, endIndex);
		endDate.month = GetDigits(date, endIndex + 1, date.find('.', endIndex + 1));
		endDate.year = GetDigits(date, date.find('.', endIndex + 1) + 1, date.length() - 1);

		std::cout << FindNumberOfWeeks(endDate) / 7 << " weeks " << std::endl; /* number of weeks */
	}
	else
	{
		std::cout << "Invalid date!" << std::endl;
	}
}

bool CheckTheDateIsValid(std::string date)
{
	int index = 0;
	int countPoint = 0;
	while (index < date.length())
	{
		if (date[index] != '.')
		{
			/* from 48 to 57 is the ascii code about the numbers from 1 to 9 */
			if ((int)date[index] < 48 || (int)date[index]> 57) 
			{
				return false;
			}
		}
		else
		{
			countPoint++;
		}
		index++;
	}
	if (countPoint == 2)
	{
		if (CheckTheDigitsOfTheDate(date) == true)
		{
			return true;
		}
	}
	return false;
}

bool CheckTheDigitsOfTheDate(const std::string date)
{
	int endIndex = date.find('.', 0);
	int day = GetDigits(date, 0, endIndex);
	int month = GetDigits(date, endIndex + 1, date.find('.', endIndex + 1));
	int year = GetDigits(date, date.find('.', endIndex + 1) + 1, date.length() - 1);

	if (year < START_DATE.year)
	{
		return false;
	}
	if (day < 1 || day > 31) /* check if the day is valid */
	{
		return false;
	}
	if (month < 1 || month > 12) /* check if the month is valid */
	{
		return false;
	}
	if (month == 2) /* for February check if the year is leap */
	{
		if (IsLeap(year) == true) /* if the year is leap the days are 29 */
		{
			if (day <= 29)
			{
				return true;
			}
			return false;
		}
		else
		{
			if (day <= 28) /* if the year is not leap the days are 28 */
			{
				return true;
			}
			return false;
		}
	}
	/* if the months are April, June, September, November the number of days is 30 */
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day <= 30)
		{
			return true;
		}
		return false;
	}
	return true;
}

bool IsLeap(int year)
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
	{
		return true;
	}
	return false;
}

int GetDigits(std::string date, int startIndex, int endIndex)
{
	return std::stoi(date.substr(startIndex, endIndex)); /* convert substring to number */
}

int FindNumberOfWeeks(Date endDate)
{
	int numbersOfDays = 0;

	for (int i = 0; i < endDate.month - 1; i++) /* add the days from every month only from the current year */
	{
		numbersOfDays += MONTH_DAYS[i];
	}

	numbersOfDays += endDate.day; /* add the days from the current month */

	for (int i = START_DATE.year; i <= endDate.year - 1; i++)
	{
		if (IsLeap(i) == true)
		{
			numbersOfDays += DAYS_IN_LEAP_YEAR;
		}
		else
		{
			numbersOfDays += DAYS_IN_YEAR;
		}
	}

	return numbersOfDays;
}