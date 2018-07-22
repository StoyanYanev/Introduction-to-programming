
//Реализирайте функция, която:
//
//прочита две цели числа n и m от конзолата и заделя двумерен масив(матрица) от цели числа с размери n x m
//прочита n*m числа и ги записва последователно по редове в матрицата
//изписва матрицата транспонирана
//освобождава заделената за матрицата памет
//
//#include <iostream>
//#include<string>
//
//using namespace std;
//
//void deleteTwoDemisionalArray(int n, int **arr);
//void fillArray(int n, int m, int **arr);
//void transposedMatrix(int n, int m, int **arr);
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
//	transposedMatrix(n, m, arr);
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
//void transposedMatrix(int n, int m, int **arr)
//{
//	cout << "Transposed Matrix:" << endl;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cout << arr[j][i] << " ";
//
//		}
//		cout << endl;
//	}
//}