#include <iostream>
#include <string>
using namespace std;
/*1.*/
class Student {
private:
	string name;
	double markAvr;
public:
	Student(string n,double m): name(n),markAvr(m){}
	string getName() { return name; }
	//дружня функція
	friend void Inspector(Student& s);

};
//визначення дружньої функції за межами класу
void Inspector(Student& s) {
	if (s.markAvr < 4) 
		cout << "no scholarship";
	else
		cout << "scholarship";
	
}
int main() {
	Student st1("Ivanenko", 4.2);
	Student st2("Petrenko", 3.8);
	cout << "Student " << st1.getName() << endl;
	Inspector(st1);
	cout << "Student " << st2.getName() << endl;
	Inspector(st2);
}