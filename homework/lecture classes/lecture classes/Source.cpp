#include <iostream>
#include <string>
using namespace std;
/*1*//*class Room {
public:
	double length;
	double breadth;
	double height;
	double calculateArea() {
		return length * breadth;
	}
	double calculateVolume() {
		return length * breadth * height;
	}
};
int main() {
	Room room1;
	room1.length = 42.5;
	room1.breadth = 30.8;
	room1.height = 19.2;
	cout << "Area of Room" << room1.calculateArea();
	cout << "Volume of Room" << room1.calculateVolume();
	return 0;
}*/
/*aбо*/
/*class Room {
private:
	double length;
	double breadth;
	double height;
public:
	void setData(double len, double brth, double hgt) {
		length = len;
		breadth = brth;
		height = hgt;
	}
	double calculateArea() {
		return length * breadth;
	}
	double calculateVolume() {
		return length * breadth * height;
	}
};
int main() {
	Room room1;
	room1.setData(42.5, 30.8, 19.2);
	cout << room1.calculateArea();
	cout << room1.calculateVolume();
}*/
/*2*/
/*class Point {
private:
	int x;
	int y;
public:
	Point() { x = 0; y = 0; }//дефолтний
	Point(int xx,int yy):x(xx),y(yy){}
	Point(const Point& p): x(p.x), y(p.y){}
};
int main() {
	Point p1;//викд дефолтний
	Point p2(0, 0);//викл з параметром
	Point p3(p2);//копіювання
}*/
/*3*/
//Point.h
/*class Point {
protected:
	int x;
	int y;
public:
	Point() :x(0), y(0) {}
	Point(int xx,int yy):x(xx), y(yy){}
	Point(const Point& p) : x(p.x), y(p.y) {}
	void print()const {
		cout << "Point(" << x << ',' << y << ')';
	}
	double dist(const Point&)const;//відстань між 2 точками, передаєм 1 точку , бо 1 вже є 
	Point operator+(const Point& p)const {
		return Point(x + p.x, y + p.y);
	}//можна додати точку, аналогічно такому P1=p2+p3; p2.operator+(p3)
};
void main() {
...
}*/
class Values {
public:
	//оголошення статичних полів
	static int how_many;
	static const float pi;
	//ініціалізація статичних полів
	static const int size = 100;
	//збільшуєм лічильник при утворенні нового об'єкта 
	Values() { how_many++; };
};
void main() {
	//використання полів без об'єктів класу
	cout << "pi=" << Values::pi << endl;
	cout << "size=" << Values::size << endl;
	//утворюємо 4 об'єкта
	Values v1, v2, v3, v4;
	cout << "how_many=" << Values::how_many << endl;

}
