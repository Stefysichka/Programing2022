#include <iostream>
using namespace std;
int main() {
	//є 2 динамічні масиви потрібно вивести 3 щоб його значення були з значень 1 та 2 масивів і зростали
	int N;
	cout << "Enter number of elements in array a: " << endl;
	cin >> N;
	int* a = new int[N];

	for (int i = 0; i < N; i++)
	{
		cout << "Enter element " << i + 1 << endl;
		cin >> a[i];
	}

	int M;
	cout << "Enter number of elements in array b: " << endl;
	cin >> M;
	int* b = new int[M];
	for (int j = 0; j < M; j++)
	{
		cout << "Enter element " << j + 1 << endl;

		cin >> b[j];
	}
	int *c = new int[N + M];
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < N || j < M) 
		if (a[i] > b[j]) {
			c[k] = b[j];
			k++;
			j++;
		}
		else {
			c[k] = a[i];
			k++;
			i++;
		}

		if (j == M) {
			for (; i < M; i++) {
				c[k] = a[i];
				k++;
				i++;
			}
		}
		else {
			c[k] = b[j];
			k++;
			j++;
		}
		for (int k = 0; k < N + M; k++) {
			cout << c[k] << endl;
		}
	
		return 0;
}