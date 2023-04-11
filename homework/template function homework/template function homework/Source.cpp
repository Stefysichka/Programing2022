#include <iostream>
#include <string>
using namespace std;
template <typename T>
void sort(T a[], int n, int i) {
    if (n < i) {
        throw "Insufficient elements in the array for sorting!";//недостатньо елементів для масиву
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
    const int n = 5;
    double a1[n]= {3.2, 4.4, 3, 5.1, 48.3};
    string a2[n] = { "hello","Stefik","Name","cat","dog" };
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
    }
    return 0;
}
