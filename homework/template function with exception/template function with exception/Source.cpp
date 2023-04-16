#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
template <typename T>
void sort(T a[], int n, int i) {
    if (n < i) {
        throw "Insufficient elements in the array for sorting!";
    }
    for (int j = 0; j < i; j++) {
        for (int k = j + i; k < i; k++) {
            if (a[j] > a[k]) {
                T temp = a[j];
                a[j] = a[k];
                a[k] = temp;
            }
        }
    }
}
int main() {
    int n;
    cout << "Enter numbers of array" << endl;
    cin >> n;
    double*a1 =  new double [n];
    string* a2 = new string[n];
    cout << "Enter double elements" << endl;
    try {
        for (int i = 0; i < n; i++) {
            cin >> a1[i];
            if (cin.fail()) {
                throw invalid_argument("Invalid input: expected double but got string!");
            }
        }
    }
    catch (const invalid_argument& e) {
        cout << e.what() << endl;
        return 1;
    }
    cout << "Enter string elements" << endl;
        for (int i = 0; i < n; i++) {
            cin >> a2[i];
        }
    try {
        sort(a1, n, 3);
        for (int i = 0; i < n; ++i) {
            cout << a1[i] << " ";
        }
        cout << endl;
        sort(a2, n, 2);
        for (int i = 0; i < n; i++) {
            cout << a2[i] << " ";
        }
        cout << endl;
    }
    catch (const char* e) {
        cout << e << endl;
        return 1;
    }
    delete[]a1;
    delete[]a2;
    return 0;
}