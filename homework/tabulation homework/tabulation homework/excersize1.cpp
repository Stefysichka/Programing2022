#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;
string Modified(double(*f)(double), double* a, int size) {
	stringstream ss;
	ss << setw(8) << "i" << setw(15) << "a[i]" << setw(20) << "modified a[i]" << endl;
	for (int i = 0; i < size; i++) {
		double modified = f(a[i]);
		ss << setw(8) << i << fixed << setprecision(2)/*two digits after the comma*/ << setw(15) << a[i] << setw(20) << modified << endl;
		a[i] = modified;/*модифікуємо масив*/
	}
	return ss.str();
}
//1.кожен елемент замінити на його квадрат
double f1(double x) {
	return x * x;
}
//2.кожен елемент a[i] замінити на sin(a[i])+cos(a[i])-tg(a[i])
double f2(double x) {
	return sin(x) + cos(x) - tan(x);
}
//3. кожен елемент замінити на найближче ціле число
double f3(double x) {
	return round(x);
}
int main() {
	double* a;
	int n;
	cout << "Enter n: " << endl;
	cin >> n;
	a= new double[n];
	cout << "Enter " << n << " numbers"<<endl;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	string st1 = Modified(f1, a, n);
	cout << "Modified using f1(x):" << endl;
	cout << st1<<endl;
	double* b = new double[n];//для того щоб функція працювала з умовою, а не результатом
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
	string st2 = Modified(f2, b, n);
	cout << "Modified using f2(x):" << endl;
	cout << st2 << endl;
	double* c = new double[n];
	for (int i = 0; i < n; i++) {
		c[i] = a[i];
	}
	string st3 = Modified(f3, c, n);
	cout << "Modified using f3(x):" << endl;
	cout << st3 << endl;
	ofstream file("result.txt");
	if (!file.is_open()) {
		cout << "Error!";
		return 1;
	}
	file << st1<<st2<<st3;
	file.close();
	delete[] a;
	delete[] b;
	delete[] c;
	return 0;
}