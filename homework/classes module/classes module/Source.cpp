#include <iostream>
#include <string>
using namespace std;
/*Визначити тип пряма на площині  за трьома дійсними числами.
Крім необхідних методів (конструкторів, введення-виведення,...) 
визначити метод знаходження точки перетину двох прямих, метод знаходження 
кута перетину двох прямих, методи перевірки, чи належить точка заданій прямій, 
чи прямі паралельні. Ввести дані про 10 прямих. Визначити 1) для кожної прямої 
список прямих, що з нею перетинаються та координати точок перетину 2) скільки з 
них паралельні осі ОХ і скільки з них перетинаються з нею під прямим кутом.*/
//ax+by+c=0
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
	struct Point {
		double x, y;
	};
	Point getInterception(Line& line) /*перевіряєм чи перетинаються*/ {
		double bottom/*знаменник, внизу у формулі,коли шукаєм перетин прямих*/ = a * line.b - line.a * b;
		double x = (b * line.c - line.b * c) / bottom;
		double y = (c * line.a - line.c * a) * bottom;
		//line.шось координати 2 прямої
		Point p;
		p.x = x;
		p.y = y;
		return p;

		bool isinteger(Line &line) {
			double bottom = a * line.b - line.a * b;
			if (bottom == 0) {
				return false;
			}
			else {
				return true;
			}
		}
	}
	
};
