#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
	string input;
	cout << "Enter a string" << endl;
	getline(cin, input);
	int quantity = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == ' ') {
			quantity++;
		}
		
	}
	cout << "The number of words in the the string is:" << quantity + 1 << endl;
	return 0;


}