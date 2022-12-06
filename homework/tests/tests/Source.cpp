#include <iostream>
#include <string>
#include <tchar.h>
using namespace std;
class A {
private:
	int a;
public:
	A() :a(0) { cout << '1' << a; }
	A(int y) :a(y) { cout << '2' << a; }
	A(const A& x) :a(x.a) { cout << '3' << a; }
};
void Test() {
	A a(1);
	A b(4);
	A c(b);
}