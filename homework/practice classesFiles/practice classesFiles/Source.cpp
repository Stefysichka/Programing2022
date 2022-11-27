#include <iostream>
#include <fstream> /*щоб працювати з файлом*/
using namespace std;
struct Point {
	int x;
	int y;
	friend istream& operator>>(istream& is, Point& point) {
		//cout << "Enter x:" << endl;
		is >> point.x;
		//cout << "Enter y:" << endl;
		is >> point.y;
		return is;//параметр, який ми передаєм
	}
	friend ostream& operator<<(ostream& os, Point& point)/*виведення*/ {
		os << "x= " << point.x << endl;
		os << "y= " << point.y << endl;
		return os;
	}
};
class Circle {
private:
	Point center;
	int radius;
public:
	Circle() :center(), radius(0) {}
	Circle(Point _center, int _radius) :center(_center), radius(_radius) {}
	Circle(const Circle& circle) : center(circle.center), radius(circle.radius) {}
	friend istream& operator>>(istream& is, Circle& circle)/*глобальні дружні*/ {
		//cout << "Enter radius:" << endl;
		is >> circle.radius;
		//cout << "Enter center:" << endl;
		is >> circle.center;
		return is;
	} //оператор введення
	friend ostream& operator<<(ostream& os, Circle& circle)/*виведення*/ {
		os << "radius= " << circle.radius << endl;
		os << "center: " << circle.center << endl;
		return os;
	}
};
int main() {
	Circle circle;
	/*cout << "Enter information about circle:" << endl;
	cin >> circle;//operator>>(cin,center),шукає оператор ссуву вправо
	return 0;*/
	//працювати з файлом
	ifstream/*input file stream*/ ifs;
	ofstream ofs("result.txt");
	ifs.open("data.txt");//зв'язок з файлом
	ifs >> circle;
	ifs.close();
	ofs.close();
	ofs << circle;
	return 0;
}