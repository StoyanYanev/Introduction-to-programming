#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int LENGTHOFSPECIALSIGNS = 5;
const int MAXLENGTHOFSENTENSE = 100;

char signs[LENGTHOFSPECIALSIGNS] = { ',', '.', '!', '?' };
bool checkSentenceIsAlpha(const char *sen);
void removeSpecialSigns(char *str, int len);
void replaceTabWithWhitespace(char *str, int len);
int findTheLongestWordInTheSentence(const char *s, int len);
void printSentence(const char *str, int maxLen, int lenOfSentence);
void printDash(int size);
void printLine();

int main(){
	char sentence[MAXLENGTHOFSENTENSE];
	cin.get(sentence, MAXLENGTHOFSENTENSE);
	int len = strlen(sentence);
	removeSpecialSigns(sentence, len);
	replaceTabWithWhitespace(sentence, len);
	int maxLenOfWord = findTheLongestWordInTheSentence(sentence, len);
	printSentence(sentence, maxLenOfWord, len);
}
void removeSpecialSigns(char *str, int len){
	int index = 0;
	for (int i = 0; i < LENGTHOFSPECIALSIGNS; i++)
	{
		while (index < len)
		{
			if (str[index] == signs[i])
			{
				str[index] = ' ';
			}
			index += 1;
		}
		index = 0;
	}
	return 0;
}
void replaceTabWithWhitespace(char *str, int len){
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '\t')
		{
			str[i] = ' ';
		}
	}
}
int findTheLongestWordInTheSentence(const char *s, int len){
	int maxLenOfWord = 0;
	int lengthOfWord = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] != ' ')
		{
			lengthOfWord++;
		}
		else
		{
			if (lengthOfWord > maxLenOfWord)
			{
				maxLenOfWord = lengthOfWord;
			}
			lengthOfWord = 0;
		}
	}
	if (lengthOfWord > maxLenOfWord)
	{
		maxLenOfWord = len;
	}
	return maxLenOfWord;
}
void printSentence(const char *str, int maxLen, int lenOfSentence)
{
	printDash(maxLen + 2);
	cout << endl;
	printLine();
	int len = 0;
	bool isPrint = false;
	for (int i = 0; i < lenOfSentence; i++)
	{
		if (str[i] != ' ')
		{
			cout << str[i];
			len++;
			if (i == lenOfSentence - 1)
			{
				cout << setw(maxLen - len + 1);
				printLine();
			}
			isPrint = false;
		}
		else{

			if (i == lenOfSentence - 1)
			{
				cout << setw(maxLen - len + 1);
				printLine();
			}
			else{
				if (isPrint == false)
				{
					cout << setw(maxLen - len + 1);
					printLine();
					cout << endl;
					printLine();
					len = 0;
					isPrint = true;
				}
			}
		}
	}
	cout << endl;
	printDash(maxLen + 2);
	cout << endl;
}
void printDash(int size){
	for (int i = 0; i < size; i++)
	{
		cout << '-';
	}
}
void printLine(){
	cout << '|';
}
