#include <iostream>
#include <string>
using namespace std;
class students {
private:
	string name;
	string groupname;
	int ID;
public:
	students():name(" "),groupname (" "),ID(0){}
	students(string n,string g,int i):name(n),groupmate(g),ID(i){}
	string GetName() {
		return name;
	}
	string GetGroupname() {
		return groupname;
	}
	int GetID() {
		return ID;
	}
	void SetID(int new_ID) {
		ID = new_ID;
	}
	void input() {
		cout << "Enter name" << endl;
		cin >> name;
		cout << "Enter groupname" << endl;
		cin >> groupname;
		cout << "Enter ID" << endl;
		cin >> ID;
	}
	void print() {
		cout << "Name--" << name << endl;
		cout << "Groupname--" << groupname << endl;
		cout << "ID--" << ID << endl;
	}
};
void main() {
	students student1;
	students student2("Stefania", "PMI11", 215367);
	int n;
	cout << "Enter numbers of students" << endl;
	cin >> n;
	students* array = new students[n];
	array[0] = student1;
	array[1] = student2;
	for (int i = 2; i < n; ++i) {
		array[i].input();
	}
	cout << "Enter name of students you want to see" << endl;
	string name;
	cin >> name;
	for (int i = 0; i < n; ++i) {
		if (array[i].GetName() == name) {
			array[i].print();
		}
	}
	for (int i = 0; i < n; ++i) {
		if (array[i].GetName() == "Stefania") {
			array[i].SetID(array[1].GetID());
			array[i].print();
		}
	}
}
