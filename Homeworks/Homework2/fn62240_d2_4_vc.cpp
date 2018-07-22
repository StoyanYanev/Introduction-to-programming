/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Stoyan Yanev
* @idnumber 62240
* @task 4
* @compiler VC
*
*/

#include <iostream>
#include <vector>

using namespace std;

const int MAXLENGTH = 50;

char *subSequence(char*, int, int);
void findAllPalindroms(char *inputText);
void saveSubSequence(char*, int, vector<char> &w);
bool checkWordsIsEqual(vector<char> &word, int startIndex, int startIndex2, int endIndex);
void check(vector<int> &ind, vector<char> &words, vector<int> &copyInd);
void printCurrentPalindrom(vector<char> &word, int startIndex, int len);

int main()
{
	char str[MAXLENGTH];
	cin.get(str, MAXLENGTH);
	findAllPalindroms(str);
	return 0;
}
char *subSequence(char* mainSentence, int from, int to){
	char *tgt = new char[to - from + 1];
	for (int i = 0; i < (to - from); i++)
	{
		tgt[i] = mainSentence[i + from];
	}
	tgt[to - from] = '\0';
	return tgt;
}
void findAllPalindroms(char *inputText){
	vector<char> pal;
	vector<int> index;
	vector<int> copyIndex;
	if (!inputText)
	{
		cout << "Input cannot be null" << endl;
		return;
	}
	if (strlen(inputText) <= 2)
	{
		cout << "Minimum three caracters should be present!" << endl;
		return;
	}
	int l = strlen(inputText);
	if (l % 2 == 1)
	{
		//odd occuring palindromes
		for (int i = 1; i < l - 1; i++)
		{
			for (int j = i - 1, k = i + 1; j >= 0 && k < l; j--, k++)
			{
				if (inputText[j] == inputText[k])
				{
					char *subSeq = subSequence(inputText, j, k + 1);
					int len = strlen(subSeq);
					saveSubSequence(subSeq, len, pal); /*save all palindromes in vector*/
					index.push_back(len); /*save length of all palindromes*/
					delete subSeq;
				}

				else break;
			}
		}
		copyIndex = index;
		check(index, pal, copyIndex);
	}
	else
	{
		//even occuring palindromes
		for (int i = 1; i < l - 1; i++)
		{
			for (int j = i, k = i + 1; j >= 0 && k < l; j--, k++)
			{
				if (inputText[j] == inputText[k])
				{
					char *subSeq = subSequence(inputText, j, k + 1);
					int len = strlen(subSeq);
					saveSubSequence(subSeq, len, pal); /*save all palindromes in vector*/
					index.push_back(len); /*save length of all palindromes*/
					delete subSeq;
				}
				else break;
			}
		}
		copyIndex = index;
		check(index, pal, copyIndex);
	}
}
void saveSubSequence(char *subS, int len, vector<char> &w){
	for (int i = 0; i < len; i++)
	{
		w.push_back(subS[i]);
	}
	w.push_back(' ');
}
void check(vector<int> &ind, vector<char> &words, vector<int> &copyInd){
	int count = 1;
	int sumJ = 0;/*set index of the next palindromes*/
	int sumI = 0;/*set index of the current palindrome*/
	int currentlen;
	int sum = 0;/*save length of the palindromes*/
	for (int i = 0; i < ind.size(); i++)
	{
		sum += ind[i];
		currentlen = ind[i];
		sumI += sum + i;
		sumJ += sum;
		/*if the palindrome is not print then compare with the the other 
		palindromes and print current palindrom how many times is found*/
		if (copyInd[i] != 0)
		{
			for (int j = i + 1; j <= ind.size() - 1; j++)
			{
				sumJ += ind[j];
				/*if the palindrome is print then the length of the 
				copyInd = 0(use copyInd to see if the current index = 0 then the current palindrome is print)*/
				if (copyInd[j] != 0) 
				{
					if (ind[i] == ind[j])
					{
						if (checkWordsIsEqual(words, sumI - 1, j + sumJ - 1, currentlen) == true)
						{
							count += 1;
							copyInd[j] = 0;
						}
					}
				}
			}
			if (count == 1)
			{
				printCurrentPalindrom(words, sumI - 1, currentlen);
				cout << " -> " << count << " times" << endl;;
			}
			else{
				printCurrentPalindrom(words, sumI - 1, currentlen);
				cout << " -> " << count << " times" << endl;;
			}
			count = 1;
			sumJ = 0;
			sumI = 0;
		}
	}
}
void printCurrentPalindrom(vector<char> &word, int startIndex, int len){
	int count = 0;
	while (count < len && startIndex < word.size())
	{
		cout << word[startIndex];
		startIndex = startIndex - 1;
		count += 1;
	}
}
bool checkWordsIsEqual(vector<char> &word, int startIndex, int startIndex2, int endIndex){
	int count = 0;
	while (count < endIndex)
	{
		if (word[startIndex] != word[startIndex2]) return false;
		startIndex = startIndex - 1;
		startIndex2 = startIndex2 - 1;
		count += 1;
	}
	return true;
}