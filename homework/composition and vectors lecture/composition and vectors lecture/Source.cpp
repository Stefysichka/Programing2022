#include <iostream>
#include <math.h>
#include <string>
using namespace std;
/*1. class Point with const*/
class Point {
protected:
	int x;
	int y;
	const int z;/*ініціалізуєм тільки тут*/
public:
	Point():x(0),y(0),z(0)/*ініціалізація за замовчуванням*/{}
	Point(int xx, int yy, int zz = 0) :x(xx), y(yy), z(zz) {}
	Point(const Point& p) :x(p.x), y(p.y), z(p.z) {}
	Point& operator=(const Point& p);
	void print() const;
	double dist(const Point&)const;/*distination*/
	void move_x(int dx);
};
class Line/*приклад композиції класів*/ {
	Point fp;/*зберігаєм точки, як поля*/
	Point sp;
public:
	Line(const Line& l) :fp(l.fp), sp(l.sp) {
	cout << "lc" << endl; /*конструктор копіювання, з одної лінії робить іншу*/
	}
	Line(const Point& p1, const Point& p2) :fp(p1), sp(p2) {
		cout << "lpp" << endl;/*з 2 точок зробити лінію*/
	}
	/*з 4 чисел, спочатку точку з 2, потім лінію*/
	Line(int x1, int y1, int x2, int y2):fp(Point(x1,y1)),sp(Point(x2,y2)){}
	void print() const;/*конст вкінці стосується того, хто викликає цей метод, щоб він не змінив об'єкт */
	float length()const {
		return fp.dist(sp);
	}

};
/*2.vectors*/
class Vector {
private:
	int* array;
	unsigned size;
public:
	Vector() :array(0), size(0) {};/*конструктор за замовуванням*/
	Vector(int* a, unsigned s) : size(s) {
		array = new int[size];
		for (int i = 0; i < size; ++i)
			array[i] = a[i];
	};
	Vector(const Vector&);/*конструктор копіювання*/
	Vector& operator=(const Vector& v);/*оператор присвоєння*/
	void input();
	int& operator[](size_t pos);
	~Vector();/*деструктор*/
};
/*конструктор копіювання*/
Vector::Vector(const Vector& v)
{
	size = v.size;
	array = new int[size];
	for (int i = 0; i < size; i++)
		array[i] = v.array[i];
}
/*оператор введення*/
void Vector::input() {
	cin >> size;
	/*перевіряєм чи є масив*/
	if (array != 0) {
		delete[]array;/*видаляєм, бо до того створений масив може не підходити нам по розміру*/
	}
	array = new int[size];/*створюєм новий масив, якщо до того не був створений*/
	for (int i = 0; i < size; ++i)
		cin >> array[i];
}
void main() {
	Vector v1;/*порожній, нема прив'язаного масива*/
	v1.input();/*є масив*/
	int arr[3] = { 1,2,3 };
	Vector v2(arr, 3);/*перердаєм масив через назву*/
}
/*оператор присвоєння*/
Vector& Vector::operator=(const Vector& v) {
	{
		if (this != &v)/*чи не дорівнює сам собі*/ {
			if (array != 0) {
				delete[]array;
			}
			array = new int[size = v.size];
			for (int i = 0; i < size; ++i) {
				array[i] = v.array[i];
			}
		}
		return*this;
	}
}
/*декструктор*/
Vector::~Vector() {
	if (array != 0) {
		delete[] array;
	}
}
/*3.оператори введення, виведення*/
class Vector {
private:
	int* array;
	unsigned size;
public:
	friend istream& operator>>(istream& is, Vector& x);
	friend ostream& operator<<(ostream& os, const Vector& x);

};
istream& operator>>(istream& is, Vector& x) {
	if (x.array != 0) {
		delete[]x.array;
	}
	x.array = new int[x.size];
	for (int i = 0; i < x.size; ++i) {
		is >> x.array[i];
	}
	return is;
}
/*4.синтаксис оератора індексування[]*/
//якщо внутрішня структура масив, то найпростіший індекс size_t, нам потрібни об'єкт за номером
const X& operator[](size_t)const;
X& operator[](size_t);
//з пар об'єктів типів X, Y, то індексом може бути Y, шукаєм конкретний об'єкт
const X& operator[](const Y&)const;
X& operator[](, const Y&);
/*приклад*/
int& Vector::operator[size_t pos]{
	if (pos < size) {/*перевіряєм чи номер не виходить за розмір масиву*/
		return array[pos];
    }
	else {
		cout << "error: out of range";
    }
}