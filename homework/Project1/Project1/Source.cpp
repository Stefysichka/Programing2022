#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
	float radius;
	cout << "write the radius of the circle" << endl;
	cin >> radius;
	float area;
	area = radius * radius * 3.14;
	cout << "area=" << area << endl;
	float length;
	length = 2 * 3.14 * radius;
	cout << "length=" << length << endl;
	float volume;
	volume = static_cast<double>(4) / 3 * 3.14 * radius * radius * radius;
	cout << "volume=" << volume << endl;
	cout << " write your 2 most favourite numbers" << endl;
	int number1;
	cin >> number1;
	int number2;
	cin >> number2;
	int arithmeticmean;
	arithmeticmean = (number1 + number2) / 2;
	cout << "arithmetic mean=" << arithmeticmean << endl;
	int geometricmean;
	geometricmean = sqrt(number1 * number2);
	cout << "geometric mean=" << geometricmean << endl;







}