#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() {
	double x;
	cout << "Enter x" << endl;
	cin >> x;
    double sum = 0;
    int y;
    y = x;
    while (x > 0)
    {
        sum = sum + y % 10;
        y = x/ 10;
    }
	return 0;
}