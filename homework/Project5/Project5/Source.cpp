#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
	int number;
	cout << "Enter number" << endl;
	cin >> number;
	int d;
	d = number * number;
	if (number>0) cout << "F(x)="<<d<< endl;
	int c;
	c = 0 - number;
	if (number < 0) cout << "F(x)="<<c<<endl;
	\\За введеним дійсним числом x, обчислити y=f(x), де функція f(x) задана графіком (a)
	
	return 0;
}
