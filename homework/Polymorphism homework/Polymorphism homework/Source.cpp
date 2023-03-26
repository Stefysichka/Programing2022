#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
/*Визначити абстрактний тип «телефон» (назва, фірма, ціна).
Визначити 2 похідні від нього типи: «мобільний телефон» (колір,
об’єм пам’яті ), «радіотелефон» (радіус дії, наявність 
автовідповідача ).У двох текстових файлах задано дані про телефони
двох різних фірм. Зчитати ці дані в один масив  і вивести у 
текстовий файл: 1)всі телефони, посортовані за ціною із зазначенням 
загальної суми; 2) радіотелефони з автовідповідачем */
class Phone {
protected:
	string name;
	string company;
	double price;
public:
	virtual void input(istream& is) {
		is >> name >> company >> price;
	}
	virtual void output(ostream& os) {
		os << "Name: " << name << "\n Company: " << company;
	}
	virtual double GetPrice() const {
		return price;
	}
	bool operator < (const Phone& other) const {
		return price < other.GetPrice();
	}
};
class MobilePhone: public Phone {
private:
	string colour;
	int memory;
public:
	void input(istream& is) {
		Phone::input(is);
		is >> colour >> memory;
	}
	void output(ostream& os) {
		Phone::output(os);
		os << "\n Colour: " << colour << "\n Memory: " << memory;
	}
	double GetPrice() const override/*Перевизначити функцію GetPrice(), щоб повернути ціну об’єкта MobilePhone*/ {
		return price;
	}
};
class RadioPhone: public Phone {
private:
	double radius_of_action;
	bool answering_machine;
public:
	void input(istream& is) {
		Phone::input(is);
		is >> radius_of_action >> answering_machine;
	}
	void output(ostream& os) {
		Phone::output(os);
		os << "\n Radius of Action: " << radius_of_action << "\n Answering machine: " << answering_machine;
	}
	double GetPrice() const override {
		return price;
	}
	bool GetAnsweringMachine() const {
		return answering_machine;
	}

};
int main() {
	vector<Phone*>list;
	ifstream file1("Text1.txt");//зчиитує з файлу
	ifstream file2("Text2.txt");
	string name, company;
	double price;
	while (file1 >> name >> company >> price) {
		MobilePhone* mp = new MobilePhone();
		mp->input(file1);
		list.push_back(mp);
	}
	while (file2 >> name >> company >> price) {
		RadioPhone* rp = new RadioPhone();
		rp->input(file2);
		list.push_back(rp);
	}
	double total_price = 0;
	for (int i = 0; i!=list.size();i++) {
			total_price += list[i]->GetPrice();
	}
	ofstream outfile3("Text3.txt"); // відкриваємо файл для запису
	cout << "Total income is " << total_price << endl;
	//сортування за ціною
	sort(list.begin(), list.end(), [](Phone* a, Phone* b) {
		return a->GetPrice() < b->GetPrice();
		});
	//радіотелефони з автовідповідачем
	for (int i = 0; i < list.size(); ++i) {
		if (RadioPhone* rp = dynamic_cast<RadioPhone*>(list[i]))/*переводить в тип радіотелефон*/ {
			if (rp->GetAnsweringMachine()) {
				rp->output(outfile3);
				outfile3 << endl;
			}
		}
	}
	file1.close();
	file2.close();
	return 0;
}