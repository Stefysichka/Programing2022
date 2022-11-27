#include <iostream>
using namespace std;
//1.дані працівника
struct Employee
{
	short id;
	int age;
	double wage;
};
void printinformation(Employee employee) {
	std::cout << "ID:" << employee.id << "\n";
	std::cout << "Age:" << employee.age << "\n";
	std::cout << "Wage:" << employee.wage << "\n";
}
void main() {
	Employee Joe = { 14,32,24.15 };
	Employee Frank = { 15,28,18.27 };
	printinformation(Joe);
	printinformation(Frank);
}
//2. x,y,z
struct Point3d {
	double x;
	double y;
	double z;
};
Point3d getZeroPoint()
{
	Point3d temp = { 0.0,0.0,0.0 };
	return temp;
}
void main() {
	Point3d zero = getZeroPoint();
	if (zero.x == 0.0 && zero.y == 0.0 && zero.z == 0.0) {
		std::cout << "The point is zero\n";
	}
	else
	{
		std::cout << "The point is not zero\n";
	}
	}