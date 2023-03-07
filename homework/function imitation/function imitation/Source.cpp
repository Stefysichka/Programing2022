#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
/*Ввести всі дані в один динамічний масив, порахувати загальні виплати
(зарплати + стипендії), вивести список опитаних, посортованих по імені
Для розвʼязування задачі створити три класи - Person, Student, Worker,
де Person - базовий клас для Student та Worker. В класах визначити потрібні
для розвʼязування задачі поля та методи, а також методи для
введення-виведення інформації про обʼєкти класів*/
class Person {
protected:
	string name;
	int age;
public:
	virtual void input(istream& is) {
		is >> age >> name;//для поліморфізму
	}
	friend istream& operator>>(istream& is, Person& data) {
		data.input(is);//це необов'язково
		return is;
	}
	virtual void output(ostream& os) {
		os << "Name: " << name << "\n Age: " << age;
	}
	//для сортування
	bool operator<(Person& p) {
		return name < p.name;
	}
	virtual int GetIncome() = 0;//чиста віртуальна функція, після чого клас стає абстрактним і ми не зможем зробити в майні новий об'єкт персона
};
class Student :public Person {
private:
	string group;
	int schoolarship;
public:
	void input(istream& is) {

		Person::input(is);
		is >> group >> schoolarship;
	}
	void output(ostream& os) {
		Person::output(os);
		os << "Group name: " << group << "\n Schoolarship is: " << schoolarship;
	}
	int GetIncome() {
		return schoolarship;
	}

};
class Worker :public Person {
private:
	int income;
public:
	void input(istream& is) {
		is >> income;
	}
	void output(ostream& os) {
		os << "Income is: " << income;
	}
	int GetIncome() {
		return income;
	}
};
int main() {
	vector<Person*>list;// коли створюєм він є порожнім
	ifstream file("data.txt");//вхідний потік
	int size = 0;
	while (!file.eof()) {
		int num;
		Person* temp;
		file >> num;
		if (num == 1) {
			temp = new Student();
		}
		if (num == 2) {
			temp = new Worker();
		}
		temp->input(file);
		list.push_back(temp);
		size++;
	}
	for (int i = 0; i != list.size(); i++) {
		list[i]->output(cout);//*list[i].output() це те саме
	}
	int total_income = 0;
	for (int i = 0; i != list.size(); ++i) {
		total_income += list[i]->GetIncome();
	}
	cout << "Total income is " << total_income;
	sort(list.begin(), list.end());
	for (int i = 0; i < list.size(); ++i) {
		list[i]->output(cout);
	}
}