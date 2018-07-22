///*Реализирайте функция, която приема като параметри две цели числа n и m,
//заделя двумерен масив от цели числа с размери n x m и връща указател към първия му елемент.*/
//
//#include <iostream>
//#include<string>
//
//using namespace std;
//
//int returnFirstElement(int n, int m);
//void fillArray(int n, int m, int **arr);
//
//int main()
//{
//	int n, m;
//	cout << "n= ";
//	cin >> n;
//	cout << "m= ";
//	cin >> m;
//	cout << returnFirstElement(n, m) << endl;
//return 0;
//}
//int returnFirstElement(int n, int m)
//{
//	int **arr = new int*[n];
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = new int[m];
//	}
//
//	fillArray(n, m, arr);
//
//	int p = **arr;
//
//	for (int i = 0; i < n; ++i) {
//		delete[] arr[i];
//	}
//	delete[] arr;
//
//	return p;
//}
//void fillArray(int n, int m, int **arr)
//{
//	int count = 1;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			arr[i][j] = count;
//			count++;
//		}
//	}
//}