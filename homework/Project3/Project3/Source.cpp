#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
	int number1;
	int number2;
	int number3;
	cout << "Enter 3 your favourite numbers to check whether these numbers form an arithmetic progression" << endl;
	cin >> number1;
	cin >> number2;
	cin >> number3;
	int difference1;
	difference1 = number2 - number1;
	int difference2;
	difference2 = number3 - number2;
	if (difference1 >> difference2) cout << "NO, It's not arithmetic progression";
	if (difference1 << difference2) cout << "NO, It's not arithmetic progression";
	if (difference1 = difference2) cout << "Yes, It's arithmetic progression";
	
	return 0;


}
