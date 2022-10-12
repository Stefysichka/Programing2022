#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main() {
	int number;
	int sum = 0;
	cout << "Enter a number.";
	cin >> number;
	while (number >= 0) 
	{
		sum += number;
		cout << "enter a number.";
		cin >> number;

	}

	cout << "The sum is" << sum << endl;
	return 0;
}