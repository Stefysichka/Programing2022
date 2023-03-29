/*#include <iostream>
#include <vector>
using namespace std;
template<typename T>
void sort(vector<T>& a) {
int n = a.size();//проходимося по масиву зліва направо та порівнюємо кожну пару сусідніх елементів
for (int i = 0; i < n - 1; ++i) {
	for (int j = 0; j < n - i - 1; j++) {
		if (a[j] > a[j + 1]) {
			T temp = a[j];
			a[j] = a[j + 1];
			a[j + 1] = temp;
		}
	}
}
}
int main() {
	//1.
	vector<int> int_a{ 3,2,1,4,5 };
	sort(int_a);
	for (const auto& x : int_a) {
		cout << x << " ";
	}
	cout << endl;
	//2.
	vector<string> string_a{ "c","a","b","e","d" };
	sort(string_a);
	for (const auto& x : string_a) {
		cout << x << " ";
	}
	cout << endl;
}*/