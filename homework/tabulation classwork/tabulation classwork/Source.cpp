#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
/*вказівник на функцію*/
using namespace std; /*виводимо значення в табличці*/
/*функція отримує ціле число і повертає ціле */
string Tab(double(*f)(double), double a, double b, int n) {
	ostringstream os;
	os << 'I' << setw(5)/*встановити ширину*/ << x << setw(5) << 'I' << setw(5) << "sinx" << setw(5) << 'I' << endl;
	int h = (b - a) / n;
	for (a; a < b; a + h) {
		os << 'I' << setw(5) << a << setw(5) << 'I' << setw(5) << f(a) << setw(5) << "I" << endl;
	}
	return os.str();
} /*f(x)=x^3+x^2-8x+9
  f(x)=sinx+8tgx-24x^2*/
double f1(double x) {
	double result;
	return result = pow(x, 3) + pow(x, 2) - 8 * x + 9;
}
int main() {
	double a, b;
	int n;
	cout << "Enter segment [a,b] and number of points" << endl;
	cin >> a >> b;
	string st;
	st = Tab(sin, a, b, n);
	ofstream file1("result.txt");
	file1 << "sinx+8tgx-24x^2" << endl << st;
	st = Tab(f1, a, b, n);
	file1 << "x^3+x^2-8x+9" << endl << st;
	st = Tab([](double x) {return sin(x) + 8 * tan(x) - 24 * pow(x, 2); }, 1, 3, 3);
	file1 << "sinx+8tgx-24x^2" << endl << st;
	file1.close();

}