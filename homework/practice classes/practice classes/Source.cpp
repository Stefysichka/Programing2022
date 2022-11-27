#include <iostream>
#include <string>
using namespace std;
//1.вибрати машину по різним параметрам
/*class Car {
private:
	int price;
	string name;
	string color;
public:
	Car():price(0),name(" "),color(" "){}
	Car(int p, string n,string c):price(p),name(n),color(c){}
	int GetPrice() {//поверне поле
		return price;
    }
	string GetName() {
		return name;
	}
	string GetColor() {
		return color;
	}
	void SetPrice(int new_price) {
		price = new_price;
	}
	void Input() {
		cout << "Enter price" << endl;
		cin >> price;
		cout << "Enter name" << endl;
		cin >> name;
		cout << "Enter color" << endl;
		cin >> color;
	}
	void Print() {
		cout << "price--" << price << endl;
		cout << "name--" << name << endl;
		cout << "color--" << name << endl;
	}
};
void main() {
	//стає таким ж типом як int
	Car car1;
	Car car2(1000, "Opel", "red");
	int n;
	cout << "Enter numbers of auto" << endl;
	cin >> n;
	Car* array = new Car[n];
	array[0] = car1;
	array[1] = car2; //заповнюємо гараж машинами
	for (int i = 2; i < n; ++i) {
		array[i].Input();
	}
	cout << "Enter color you want" << endl;
	string color;
	cin >> color;
	for (int i = 0; i < n; ++i) {
		if (array[i].GetColor() == color) {
			array[i].Print();
		}
	}
	for (int i = 0; i < n; ++i) {
		if (array[i].GetColor() == "gold") {
			array[i].SetPrice(array[i].GetPrice() * 0.9//на 10 % менше від ціни);
			array[i].Print();
		}
	}
}*/
//2.видрукувати студентів вказаної групи,видрукувати студентів з вказаним імям,змінити айді першого студента на айді введеного,видрукувати всіх студентівбпосортувати за айді
class students {
private:
	string name;
	string groupname;
	int ID;
public:
	students() :name(" "), groupname(" "), ID(0) {}
	students(string n, string g, int i) :name(n), groupname(g), ID(i) {}
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
void sort(students* arr, int size); 
int main() {
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
	/*1*/cout << "Enter name of student you want to see" << endl;
	string name1;
	cin >> name1;
	for (int i = 0; i < n; ++i) {
		if (array[i].GetName() == name1) {
			array[i].print();
		}
	}
	for (int i = 0; i < n; ++i) {
		if (array[i].GetName() == "Stefania") {
			array[i].SetID(array[i].GetID());
			array[i].print();
		}
	}
	/*2*/cout << "Enter groupname you want to see" << endl;
	string groupname;
	cin >> groupname;
	for (int i = 0; i < n; ++i) {
		if (array[i].GetGroupname() == groupname) {
			array[i].SetID(array[i].GetID());
			array[i].print();
		}
	}
	for (int i = 0; i < n; ++i) {
		if (array[i].GetGroupname() == "PMI11") {
			array[i].SetID(array[i].GetID());
			array[i].print();
		}
	}
	/*3*/int ID;
	cout << "Enter an anouther ID" << endl;
	cin >> ID;
	string name2;
	cout << "Enter a name,whose ID you want to change" << endl;
	cin >> name2;
	for (int i = 0; i < n; ++i) {
		if (array[i].GetName() == name2) {
			array[i].SetID(ID);
			array[i].print();
		}
	}
	/*4*/
	sort(array, n);
	
}
void sort(students* arr, int size)
{
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (arr[i].GetID() > arr[j].GetID()) {
				students temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < size; ++i) {
		arr[i].print();
	}
}