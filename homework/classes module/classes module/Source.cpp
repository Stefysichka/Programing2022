#include <iostream>
#include <string>
#include <math.h>
using namespace std;
/*Визначити тип пряма на площині  за трьома дійсними числами.
Крім необхідних методів (конструкторів, введення-виведення,...) 
визначити метод знаходження точки перетину двох прямих, метод знаходження 
кута перетину двох прямих, методи перевірки, чи належить точка заданій прямій, 
чи прямі паралельні. Ввести дані про 10 прямих. Визначити 1) для кожної прямої 
список прямих, що з нею перетинаються та координати точок перетину 2) скільки з 
них паралельні осі ОХ і скільки з них перетинаються з нею під прямим кутом.*/
//ax+by+c=0
struct Point {
double x, y;
	};
class Line {
private:
	double a, b, c;
public:
	Line() :a(0), b(0), c(0) {}
	Line(const Line& p/*з неї робимо копію*/) :a(p.a), b(p.b), c(p.c) {}
	friend istream& operator>>(istream& is, Line& line) {
		is >> line.a >> line.b >> line.c;
		return is;
	}
	friend ostream& operator<<(ostream& os, Line& line) {
		os << line.a << 'x' << '+' << line.b << 'y' << '+' << line.c << '=' << '0';

			return os;
	}
	Line(double a1,double b1,double c1):a(a1),b(b1),c(c1){}
	
	Point getInterception(Line& line) /*перевіряєм чи перетинаються*/ {
		double bottom/*знаменник, внизу у формулі,коли шукаєм перетин прямих*/ = a * line.b - line.a * b;
		double x = (b * line.c - line.b * c) / bottom;
		double y = (c * line.a - line.c * a) * bottom;
		//line.шось координати 2 прямої
		Point p;
		p.x = x;
		p.y = y;
		return p;

		
	}
	bool isIntersept(Line& line)/*чи знаменник дорівнює 0*/ {
		double bottom = a * line.b - line.a * b;
		if (bottom == 0) {
			return false;
		}
		else {
			return true;
		}
	}
	//кут перетину
	double getAngle(Line& line) {
		double angle = (line.a * a + line.b * b) / (sqrt(line.a * line.a + line.b * line.b)*sqrt(a*a+b*b));
		return angle;
	}
	//чи належить точка прямій
	bool isOnALine(Point& p) {
		if (a*p.x + b*p.y + c == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	
};
int main() {
	const int n = 10;
	Line *array = new Line[n];
	for (int i = 0; i < n; ++i) {
		cin >> array[i];
	}
	//для кожної прямої список прямих, що з нею перетинаються та координати точок перетину
	//перевіряєм чи іта пряма перетинається з jтою
	for (int i = 0; i < n-1; ++i) {
		for (int j = i+1; j < n - 1; ++j) {
			if (array[i].isIntersept(array[j])) {
				cout << "line" << array[i] << "intersepts" << array[j] << endl;
				cout << "point of interseption is " << array[i].getInterception(array[j]).x<<',' << array[i].getInterception(array[j]).y << endl;
			}
		}
	}
	//скільки з них паралельні осі ОХ і скільки з них перетинаються з нею під прямим кутом
	Line Ox(0, 1, 0);
	int c1, c2 = 0;
	for (int i = 0; i < n; ++i) {
		if (!array[i].isIntersept(Ox)) {
			c1++;
		}
		else {
			// test
		}
	}

}
