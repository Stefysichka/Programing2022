#include <iostream>
#include <math.h>
using namespace std;
/* Визначити тип чотирикутник за координатами чотирьох його
вершин. Крім необхідних методів (конструкторів, введення-виведення,
...) визначити метод знаходження його периметру, метод перевірки,
чи є заданий чотирикутник прямокутником, квадратом, оператор < 
- порівняння двох чотирикутників за периметром. Ввести дані про 10 
чотирикутників. Посортувати їх (використовуючи оператор<) у порядку 
спадання периметрів. Видрукувати список тих чотирикутників, що є квадратами 
і окремо тих, що є прямокутниками.*/
struct Point {
	int x, y;
	friend istream& operator>>(istream& is, Point point) {
		cout << "Enter x " << endl;
		is >> point.x;
		cout << "Enter y " << endl;
		is >> point.y;
		return is;
	}
	friend ostream& operator<<(ostream& os, Point& point)
	{
		os <<"x: "<<point.x << endl;
		os<< "y: "<<point.y << endl;
		return os;
	}
};
class Quadrangle {
private:
	Point a, b, c, d;
public:
	Quadrangle() :a(), b(), c(), d(){}
	Quadrangle(const Quadrangle& quad) :a(quad.a), b(quad.b), c(quad.c), d(quad.d) {}
	friend istream& operator>>(istream& is, Quadrangle& quad) {
		cout << "Enter a " << endl;
		is >> quad.a;
		cout << "Enter b " << endl;
		is >> quad.b; 
		cout << "Enter c " << endl;
		is >> quad.c; 
		cout << "Enter d " << endl;
		is >> quad.d;
		return is;
	}
	friend ostream& operator<<(ostream& os, Quadrangle& quad) {
		os << "a: " << quad.a << endl;
		os << "b: " << quad.b << endl;
		os << "c: " << quad.c << endl;
		os << "d: " << quad.d << endl;
		return os;
	}
	 double length1() const
	{
		double length1 = sqrt(pow((a.x - b.x), 2)/*x, першої сторони*/ + pow((a.y - b.y), 2));
		return length1;
	}
	double length2() const
	{
		double length2 = sqrt(pow((c.x - b.x), 2) + pow((c.y - b.y), 2));
		return length2;
	}
	double length3() const
	{
		double length3= sqrt(pow((c.x - d.x), 2) + pow((c.y - d.y), 2));
		return length3;
	}
	 double length4() const 
	 {
		double length4 = sqrt(pow((d.x - a.x), 2) + pow((d.y - a.y), 2));
		return length4;
	}
	double perimeter() const {
		double perimeter = length1() + length2() + length3() + length4();
		return perimeter;
	}
	bool isRectangle() {
		if (length1() == length3() && length2() == length4()) {
			return true;
		}
	}
	bool isSquare() {
		if (length1() == length2() && length2() == length3() && length3() == length4()) {
			return true;
		}
	}
	bool operator<(const Quadrangle& quadrangle) {
		return perimeter() < quadrangle.perimeter();
	}
}; 
void Sort(Quadrangle* array);
int main() {
	const int n = 10;
	Quadrangle* array = new Quadrangle[n];
	for (int i = 0; i < n; ++i) {
		cout << "Quadrangles " << i << endl;
		cin >> array[i];
	}
	/*1.*/ 
	Sort(array);
	/*2.*/ 
	for (int i = 0; i < n; ++i) {
		cout << array[i].perimeter() << endl;
	}
	cout << "Quadrangles are squares: " << endl;
	for (int i = 0; i < n; ++i) {
		if (array[i].isSquare() == true) {
			cout << "Quadrangle " << i << " : " << endl;
			cout << array[i] << endl;
		}
	}
	/*3*/
	cout << "Quadrangles are rectanglues: " << endl;
	for (int i = 0; i < n; ++i) {
		if (array[i].isRectangle() == true) {
			cout << "Quadrangle " << i << " : " << endl;
			cout << array[i];
		}
	}
	return 0;
}
/*Посортувати їх (використовуючи оператор<) у порядку
спадання периметрів.*/
void Sort(Quadrangle* array) {
	for (int i = 0; i < 10; ++i) {
		for (int j = i + 1; j < 10; ++j) {
			if (array[i].perimeter() < array[j].perimeter()) {
				Quadrangle temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}