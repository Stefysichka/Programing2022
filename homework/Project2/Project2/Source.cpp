#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
	int x, y;
	int sum = 0;
	cout <<"Enter any three-digit number"<< endl;
	cin >> x;
	for (; x > 0;) {
		y = x % 10;
		sum += y;
		x /= 10;
	}
	cout << sum << endl;
	\\18. Знайти суму  цифр введеного трьохзначного числа
	return 0;
}
