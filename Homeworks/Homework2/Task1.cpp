#include <iostream>
#include <cstdlib> 
#include <vector>
#include <ctype.h>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;

const int EASYWORDINARRAY = 14; /*from index 0 to 14 the words are easy in the array */
const int HARDWORDINARRAY = 15; /*from index 15 to 29 the words are hard in the array */
const int MAXWORDINARRAY = 29; /*max number of words in the array*/

char *words[] = { "student", "apple", "christmas", "computer", "window", "website", "perimeter", "insomnia", "friendship", "homework", "telephone", "passion", "holiday", "football", "family",
"refrigerator", "modification", "regardless", "disinterested", "lieutenant", "experience", "handkerchief", "presentation", "attention", "imagination", "pronouncement", "programmer", "disappointed", "relationship", "constitution" };

int getLenOfWord(const char *word);
vector<char> originalWord(const char *word, int len);
vector<char> wordWithDash(vector<char> word);
int countMissingLetters(vector<char> word);
void showWord(vector<char> word);
bool checkLetter(vector<char> word, char letter);
void replaceDash(vector<char> originalWord, vector<char> &wordWithDash, char letter);
void startGame(int level);
bool checkEnterLetterIsInSentence(char letter, vector<char> &enteredWords);

int main()
{
	srand(time(NULL));
	char level;
	int ranNum;
	cout << "Choose level" << endl;
	cout << "1. Easy" << endl;
	cout << "2. Hard" << endl;
	cout << "You choose: ";
	cin >> level;
	if (level == '1')
	{
		ranNum = rand() % (EASYWORDINARRAY + 1);
		startGame(ranNum);
	}
	else if (level == '2')
	{
		ranNum = HARDWORDINARRAY + rand() % (MAXWORDINARRAY - HARDWORDINARRAY + 1);
		startGame(ranNum);
	}
	else
	{
		cout << "You have to choose 1 or 2!" << endl;
	}
	return 0;
}
int getLenOfWord(const char *word){
	int len = 0;
	while (*word != '\0')
	{
		len += 1;
		word = word + 1;
	}
	return len;
}

/*save the word which is choosen randomly from array of words*/
vector<char> originalWord(const char *word, int len){
	vector <char> orWord;
	for (int i = 0; i < len; i++)
	{
		orWord.push_back(word[i]);
	}
	return orWord;
}

/*make the word which is choosen randomly from array of words with dash
(show first and last letter of the word and if they meet more than once show them too)*/
vector<char> wordWithDash(vector<char> word){
	char firsLetter = word[0];
	char lastLetter = word[word.size() - 1];
	vector<char> wordWithDash;
	wordWithDash.push_back(firsLetter);
	for (int i = 1; i < word.size() - 1; i++)
	{
		if (word[i] == firsLetter || word[i] == lastLetter)
		{
			wordWithDash.push_back(word[i]);
		}
		else
		{
			wordWithDash.push_back('_');
		}
	}
	wordWithDash.push_back(lastLetter);
	return wordWithDash;
}

/*check if the user guess all letters*/
int countMissingLetters(vector<char> word){
	int countMissingLetters = 0;
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == '_')
		{
			countMissingLetters += 1;
		}
	}
	return countMissingLetters;
}

void showWord(vector<char> word){
	for (int i = 0; i < word.size(); i++)
	{
		cout << word[i];
	}
}

/*check if the user has entered this letter*/
bool checkLetter(vector<char> word, char letter){
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] == letter)
		{
			return true;
		}
	}
	return false;
}

void replaceDash(vector<char> originalWord, vector<char> &wordWithDash, char letter){
	for (int i = 1; i < originalWord.size() - 1; i++)
	{
		if (originalWord[i] == letter)
		{
			wordWithDash[i] = originalWord[i];
		}
	}
}

bool checkEnterLetterIsInSentence(char letter, vector<char> &enteredWords){
	for (int i = 0; i < enteredWords.size(); i++)
	{
		if (enteredWords[i] == letter)
		{
			cout << "This letter is entered!" << endl;
			return false;
		}
	}
	enteredWords.push_back(letter);
	return true;
}

void startGame(int level){
	vector<char> wDash;
	vector<char> oWord;
	vector<char> enteredLetters;
	char letter;
	int countMissingLetter;
	int attempts;
	bool isHaveLetterInWord = false;
	char *word = words[level]; /*get word from array of words*/
	int len = getLenOfWord(word);
	if (level <= EASYWORDINARRAY)
	{
		attempts = len; /*if the user choose easy level his attempts = length of the word*/
	}
	else{
		attempts = len / 2; /*if the user choose hard level his attempts = length / 2 of the word*/
	}
	oWord = originalWord(word, len); /*save the word which is choosen randomly from array of words*/
	wDash = wordWithDash(oWord);  /* make choosen word with dash */
	showWord(wDash);
	enteredLetters.push_back(oWord[0]); /*push first letter in array (this letter is shown)*/
	enteredLetters.push_back(oWord[len - 1]); /*push last letter in array (this letter is shown)*/
	cout << setw(20) << "Attempts left: " << attempts << endl;
	while (attempts > 0)
	{
		cout << "Enter letter: ";
		cin >> letter;
		if (isalpha(letter)) /*check letter is correct*/
		{
			letter = letter | 0x20; /*lcase*/
			if ((checkEnterLetterIsInSentence(letter, enteredLetters)) == true)
			{
				isHaveLetterInWord = checkLetter(oWord, letter);
				if (isHaveLetterInWord == true)
				{
					cout << "Success!" << endl;
					replaceDash(oWord, wDash, letter);
					countMissingLetter = countMissingLetters(wDash);
					if (countMissingLetter == 0)
					{
						cout << endl;
						cout << "Congratulations, you win! " << endl;
						cout << "The word was: ";
						showWord(oWord);
						cout << endl;
						cout << endl;
						break;
					}
					else
					{
						showWord(wDash);
						cout << setw(20) << "Attempts left: " << attempts << endl;
					}
				}
				else{
					cout << "Error!" << endl;
					attempts -= 1;
					showWord(wDash);
					cout << setw(20) << "Attempts left: " << attempts << endl;
					if (attempts == 0)
					{
						cout << endl;
						cout << "You lost!" << endl;
						cout << endl;
					}
				}
			}
		}
		else
		{
			cout << "The letter " << letter << " is no alphabetic!" << endl;
		}
	}
}
