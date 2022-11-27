#include <iostream>
#include <string>
using namespace std;
/*void QuickSort(double a[], unsigned int n, int l, int r) {
	//1.Ввести масив з n дійсних чисел. Посортувати і вивести його у порядку зростання, використовуючи  метод сортування «швидке сортування».
	int iter = l;
	int jter = r;
	int middle = (r + l) / 2;
	int x = a[middle];
	int w;
	do {
		while (a[iter] < x) {
			iter++;
		}
		while (x < a[jter]) {
			jter--;
		}
		if (iter <= jter) {
			w = a[iter];
			a[iter] = a[jter];
			a[jter] = w;
			iter++;
			jter--;
		}
	} while (iter < jter);
	if (l < jter) {
		QuickSort(a, n, l, jter);
	}
	if (iter < r) {
		QuickSort(a, n, iter, r);
	}
}
int main(int argc, char** argv) {
	int n;
	cout << "enter number of elements in array a:" << endl;
	cin >> n;
	double* a = new double[n];
	for (int i = 0; i < n; i++) {
		cout << "enter elements" << i + 1 << endl;
		cin >> a[i];
	}
	QuickSort(a, n, 0 початок,як l , n - 1 кінець,як r);
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";

	}
	cout << endl;
	return 0;
}*/


//2.Ввести елементи матриці розміру n x m. Видрукувати номери всіх стовпців, що містять тільки непарні числа
/* int main() {
	const int n = 3;
	const int m = 3;
	int matrix[n][m];
	int array[m];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> matrix[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (matrix[j][i] % 2 != 0)
			{
				array[m]=j;
				cout<<array[m];
			}
		}
	}
	cout<<endl;

}*/
// 3.Ввести текст, що складається зі слів, розділених пропусками і закінчується крапкою. Видрукувати лише ті слова, що складаються лише з цифр у порядку зростання чисел, що вони представляють.
void main() {
	string text[10];
	cout << "enter text" << endl;
	for (int i = 0; i < 10; ++i) {
		cin >> text[i];
	}
	string fulltext;
	getline(cin, fulltext);
	int i = 0;
	int j = 0;
	text[0] = ' ';
	while (fulltext[i] != '.') {
		if (fulltext[i] != ',') {
			text[j] += fulltext[i];
		}
		else {
			j++; text[j] = " ";
		}
		i++;
		int n = j;
	}
	int mas[10];
	for (int i = 0; i < 10; ++i) {
		mas[i] = stoi(text[i]);
	}
	int n = sizeof(mas) / sizeof(mas[0]);
	QuickSort(mas, n, 0, n - 1);
	for (int i = 0; i < n; ++i) {
		cout << mas[i] << " ";

	}
	cout << endl;
}
void QuickSort(int mas[], unsigned int n, int l, int r) {
	int iter = l;
	int jter = r;
	int middle = (r + l) / 2;
	int x = mas[middle];
	int w;
	do {
		while (mas[iter] < x) {
			iter++;
		}
		while (x < mas[jter]) {
			jter--;
		}
		if (iter <= jter) {
			w = mas[iter];
			mas[iter] = mas[jter];
			mas[jter] = w;;
			iter++;
			jter--;
		}
	} while (iter < jter);
	if (l < jter) {
		QuickSort(mas, n, l, jter);
	}
	if (iter < r) {
		QuickSort(mas, n, iter, r);
	}
}
