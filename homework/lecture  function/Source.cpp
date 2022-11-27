#include <iostream>
using namespace std;
/*1.void greet(string name)
{
	cout << "Hello world" << name;
}
int main()
{
	string n = "Ira";
	greet(n);
	cout << "Bye";
}*/
/*2. void displayNum(int n1, float n2)
{
	cout << "the int number is " << endl<<n1;
	cout << "the double number is " <<endl<< n2;

}
int main()
{
	int n1 = 5;
	double n2 = 5.5;
	displayNum(n1, n2);
	return 0;
}*/
/*3. int sum(int x, int y)
{
	x += y;
		return x;
}
void main() {
	int a = 9, b = 5;
	cout << "sum(" << a << ',' << b << ")=" << sum(a, b) << endl;
	cout << a;
}*/
/*4. void main()
{
	double a, b;
	cin >> a >> b;
	double rez;
	rez = abs(max(a, b));
	cout << "|Max|=" << rez;
}*/
/*5. double min(double x, double y)
{
	if (x < y) return x;
	else return y;
}
void main()
{
	double a, b;
	cin >> a >> b;
	float rez;
	rez = min(a + 12, b);
	cout << "min=" << rez;
}*/
/*6. double sum(const double* arr, int size)
{
	double r = 0;
	for (int i = 0; i < size; i++)
		r += arr[i];
	return r;
}
void input(double* arr, int size)
{
	cout << "input" << size << "elements";
	for (int i = 0; i < size; i++)
		cin >> arr[i];
}
void main()
{
	double mas[5] = { 1,2,3,4,5 };
	double rez = 0;
	rez = sum(mas, 5);
	cout << rez;
	double* vec = new double[7];
	input(vec, 7);
	cout << sum(vec, 7);
	delete[] vec;

}*/
