#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{

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
	\\Обчислити середнє арифметичне, середнє геометричне двох заданих натуральних чисел.

return 0;





}
