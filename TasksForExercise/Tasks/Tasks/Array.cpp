///*Реализирайте функция, която приема параметър L от тип int,
//заделя динамичен масив с дължина L и връща като резултат указател към първия елемент на масива.*/
//#include <iostream>
//#include<string>
//
//using namespace std;
//
//int returnFirstElement(int l);
//void fillArray(int l, int *arr);
//
//int main()
//{
//	int l;
//	cout << "l= ";
//	cin >> l;
//	cout << returnFirstElement(l) << endl;

//return 0;
//}
//int returnFirstElement(int l)
//{
//	int *arr = new int[l];
//	fillArray(l, arr);
//	int f = *arr;
//	delete[] arr;
//	return f;
//}
//void fillArray(int l, int *arr)
//{
//	for (int i = 0; i < l; i++)
//	{
//		arr[i] = (i + 1) * 5;
//	}
//}