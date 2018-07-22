
//Реализирайте своя имплементация на следните функции :
//
//strlen - връща размера на дадена дума
//strcpy - копиране на даден стринг в друг
//strcat - конкатенация на два стринга - резултата се записва в първия стринг
//strcmp - сравнява два дадени стринга лексикографски

//#include <iostream>
//#include<string>
//
//using namespace std;
//
//int strlenI(char str[]);
//void strcpyI(char str1[], const char str2[]);
//char strcatI(char str1[],  char str2[]);
//void strcmpI();
//
//int main()
//{
//	char s[1000];
//	cout << "Enter string" << endl;
//	cin.getline(s, 1000);
//	cout << "Thel length of the string is: " << strlenI(s) << endl;
//
//	char str1[] = "Hello Geeks!";
//	char str2[] = "GeeksforGeeks";
//	cout << "Before copy: " << endl;
//	cout << str1 << endl;
//	cout << str2 << endl;
//	strcpyI(str1, str2);
//	cout << "After copy: " << endl;
//	cout << str1 << endl;
//	cout << str2 << endl;
//	cout << strcatI(str1, str2) << endl;
//return 0;
//}
//int strlenI(char str[])
//{
//	char *ch = str;;
//	int len = 0;
//	while (*ch != '\0')
//	{
//		len++;
//		ch++;
//	}
//	return len;
//}
//void strcpyI(char str1[], const char str2[])
//{
//	int i = 0;
//	while (str2[i] != '\0')
//	{
//		str1[i] = str2[i];
//		i++;
//	}
//}
//char strcatI(char str1[],  char str2[])
//{
//	char *p = str1;
//	char *f = str2;
//	while (*f != '\0')
//	{
//		p++;
//		p = f;
//		f++;
//	}
//	char t = *p;
//	return t;
//}