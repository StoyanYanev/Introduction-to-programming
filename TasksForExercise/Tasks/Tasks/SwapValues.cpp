/*Реализирайте функция, която разменя стойностите на 2 променливи от тип int
чрез псевдоними - void swap(int& a,int& b)
чрез указатели - void swap(int* a,int* b)*/
//
//#include <iostream>
//#include<string>
//
//using namespace std;
//
//void swapN(int &a, int &b);
//void swapP(int *a, int *b);
//
//int main()
//{
//	int a = 5;
//	int b = 10;
//	cout << "Before swap" << endl;
//	cout << a << endl;
//	cout << b << endl;
//	cout << "After swap" << endl;
//	swapN(a, b);
//	cout << a << endl;
//	cout << b << endl;
//
//	int *l;
//	l = &a;
//	int *f = &b;
//	swapP(l, f);
//	cout << *l << endl;
//	cout << *f << endl;
//return 0;
//}
//void swapN(int &a, int &b)
//{
//	int t = a;
//	a = b;
//	b = t;
//}
//void swapP(int *a, int *b)
//{
//	int y = *a;
//	*a = *b;
//	*b = y;
//}