
/*Реализирайте функция, която приема двумерен масив от цели числа
и освобождава паметта, която той използва. Помислете какви параметри трябва да приема функцията.
*/
//#include <iostream>
//#include<string>
//
//using namespace std;
//
//void deleteTwoDemisionalArray(int n, int **arr);
//void fillArray(int n, int m, int **arr);
//
//int main()
//{
//	int n, m;
//	cout << "n= ";
//	cin >> n;
//	cout << "m= ";
//	cin >> m;
//	int **arr = new int*[n];
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = new int[m];
//	}
//	fillArray(n, m, arr);
//	deleteTwoDemisionalArray(n, arr);
//return 0;
//}
//void deleteTwoDemisionalArray(int n, int **arr)
//{
//	for (int i = 0; i < n; ++i) {
//		delete[] arr[i];
//	}
//	delete[] arr;
//}
//void fillArray(int n, int m, int **arr)
//{
//	cout << "Enter elements" << endl;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cin >> arr[i][j];
//
//		}
//	}
//}