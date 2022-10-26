#include <iostream>;
#include <math.h>;
using namespace std;
int main() {
	double a[30], b[30], c[30];
	double x, y, z;
	double sum1 = 0;
	double sum2 = 0;
	double sum3 = 0;
	cout << "enter x " << " enter y " << " enter z " << endl;
	cin >> x >> y >> z;
	for (int i = 0; i <=30; i++) {
		cout << "enter massif a[]" << endl;
		cin >> a[i];
		double sum1 = 0;
		for (int j= 30; j>0; j--) {
			sum1 += a[i] * pow(x, j);
		}
	}
	for (int l = 0; l <=30; l++) {
		cout << "enter massif b[]" << endl;
		cin >> b[l];
		double sum2 = 0;
		for (int m = 30; m >0; m--) {
			sum2 += b[l] * pow(y, m);
		}
	}
	for (int r = 0; r <=30; r++) {
		cout << "enter massif c[]" << endl;
		cin >> c[r];
		double sum3 = 0;
		for (int k = 30; k>0; k--) {
			sum3 += c[r] * pow((x+z), k);
		}
	}
	double sum;
	sum = (sum1 - sum2) / sum3;
	cout << "the result is" << sum << endl;
	return 0;
}