#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
	float x;
	cout << "Enter x" << endl;
	cin >> x;
	float y;
	y = pow((pow(8, x) + pow(x, 8)), (1 / 8));
	cout << "y=" << y << endl;
	\\5 Ввести x – дійсне число, обчислити значення виразу
	return 0;

	
}
