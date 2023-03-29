#include <iostream>
#include <vector>
#include <string>
using namespace std;
template<typename T>
/*Визначити шаблонний клас Товар, для зберігання даних про
деякий об’єкт Т, дату його виготовлення та термін придатності 
(в днях). В класі визначити оператори<< і >>, метод, який 
повертає дату кінцевого терміну придатності. Також визначити
структуру Молоко з полями назва та жирність, оператори<< і >>.
Створити два масиви Товарів з шаблонними параметрами string
та Молоко. Ввести дані про декілька таких об’єктів і видрукувати
для кожного кінцевий термін придатності.*/
class Product {
private:
	T name;
	T date_of_manufacture;
	T expiration_date;
public:
	Product(T n, T d, T e):name(n), date_of_manufacture(d), expiration_date(e){}
	friend ostream& operator<<(ostream& os, Product& product) {
		os << "Name: " << product.name << "\n Date of manufacture: " << product.date_of_manufacture << "\n Expiration date: " << product.expiration_date<<endl;
		return os;
	}
	friend istream& operator>>(istream& is, Product& product) {
		is >> product.name;
		is >> product.date_of_manufacture;
		is >> product.expiration_date;
		return is;
	}
	T GetExpirationDate() {
		return expiration_date;
	}
};
struct Milk: public Product<string> {
private:
	string name;
	double fat_content;
public:
	Milk(string n, double f, string d, string e):Product<string>(n,d,e), fat_content(f) {}
	friend ostream& operator<<(ostream& os, Milk& milk) {
		os << "Name: " << milk.name << "\n Fat content: " <<milk.fat_content <<endl;
		return os;
	}
	friend istream& operator>>(istream& is, Milk& milk) {
		is >> milk.name;
		is >> milk.fat_content;
		return is;
	}
};
int main() {
	vector<Product<string>> string_products;
	vector<Milk> milk_products;
	/*введення даних про об'єкти*/
	string_products.push_back(Product<string>("Chocolate", "2023-01-01", "2023-06-01"));
	string_products.push_back(Product<string>("Chips", "2023-03-05", "2023-09-05"));
	milk_products.push_back(Milk("Danone", 1.0, "2023-03-01", "2023-04-01"));
	milk_products.push_back(Milk("Milkiland", 2.0, "2023-02-14", "2023-03-14"));
	for (auto& p : string_products) {
		cout << "Expiration date: " << p.GetExpirationDate() << endl;
	}
	for (auto& m : milk_products) {
		cout << "Expiration date: " << m.GetExpirationDate() << endl;
	}
	return 0;
}