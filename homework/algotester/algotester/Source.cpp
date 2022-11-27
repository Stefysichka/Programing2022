#include <iostream>;
#include <math.h>;
using namespace std;
int main() {
	int n;
	cout << "enter the number of numbers in the array" << endl;
	cin >> n;
	int* a = new int[n];
	for (size_t i = 0; i < n; ++i) {
		cout << "enter a[i]" << endl;
		cin >> a[i];

	}
	int max_line = 0;
	int el = 0;
	for (int j = 0; j < n; j++) {
		int min_a = a[0];
		if (a[j] < min_a) {
			a[j] = min_a;
		}
		int element = min_a;
		if (a[j] > element) {
			a[j] = element;
			el++;
		}
		max_line = max(el,max_line);
	}
	cout << "max_line=" << max_line << endl;
	delete[]a;
	return 0;
}