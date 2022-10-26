#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	const int m = 4;
	const int n = 4;
	double matrix[m][n];
	double min_values[m];
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> matrix[i][j];
		}
	}//1.Ввести матрицю дійсних чисел розміром mxn та идрукувати всі елементи в фоматі матриці
	/*
		for (int i = 0; i < m; ++i)
	{

		for (int j = 0; j < n; ++j)
		{

			cout << matrix[i][j] << ' ';

		}

		cout << endl;

	}*/

	//2.видрукувати стовпчики матриці з непарними номерами
	/*for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> matrix[i][j];
		}
	}
	cout << "odd columns" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j += 2) {
			cout << matrix[i][j];
		}
	}*/
	//3.знайти і видрукувати найменший елемент в кожному рядку
	
	/*for (int i = 0; i < m; ++i) {
		min_values[i] = matrix[i][0];
		for (int j = 0; j < n; ++j) {
			if (matrix[i][j] < min_values[i]) {
				min_values[i] = matrix[i][j];
			}
			}
		cout << min_values[i] << endl;
	}*/
	//4.поміняти місцями значення k-ого та l-ого рядка (k,l вводимо)
	/*int k, l;
	cout << "enter row numbers" << endl;
	cin >> k >> l;
	double row_k[n];
	double row_l[n];
	for (int i = 0; i < n; ++i) {
		row_k[i] = matrix[k - 1][i];
		row_l[i] = matrix[l - 1][i];
		matrix[l - 1][i] = row_k[i];
		matrix[k - 1][i] = row_l[i];
	}*/
	//5.видрукувати всі діагональні елементи
	if (m == n) {
		cout << "diagonal" << endl;
		for (int i = 0; i < m; ++i) {
			cout << matrix[i][i];
		}
		cout<<endl;
	}
	else {
		cout << "can't get diagonal, not square matrix" << endl;
	}
	
}