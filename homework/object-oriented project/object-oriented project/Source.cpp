#include <iostream>
using namespace std;
/*Розробити програму для кошика електронного магазину,
яка дозволить користувачам додавати товари в кошик для подальшої покупки. 
Програма має забезпечувати додавання товарів до кошика, видалення товарів
з кошика, відображення списку товарів у кошику, а також обчислення сумарної 
вартості кошика. Товар має назву, ціну за одиницю. У кошик можна додавати 
товар і вказувати його кількість, так само з видаленням.*/
class Product {
	/*1. Товар має назву, ціну за одиницю*/
private:
	int price;
	string name;
	int code;
public:
	Product(int c = 0) :code(c), price(0), name("Stefik") {}
	int getPrice() {
		return price;
	}
	string getName() {
		return name;
	}
	int getCode() {
		return code;
	}
	friend istream& operator>>(istream& is, Product& product) {
		cout << "Enter product's name" << endl;
		is >> product.name;
		cout << "Enter price" << endl;
		is >> product.price;
		cout << "Enter code" << endl;
		is >> product.code;
		return is;
	}
	friend ostream& operator<<(ostream& os, Product& product) {
		os << "the name is: " << product.name;
		os << "price is: " << product.price;
		os << "code is: " << product.code;
		return os;
	}
	bool operator==(const Product& product2)
	{
		return code == product2.code;
	}

};
class Basket {
private: /*динамічні масиви*/
	Product* products;
	int* quantity;
	int current=0;//додали 2 елементи, кількість 2 і ціна 2 додалась
public:
	/*2. додавання товарів*/
	Basket(){ 
		products = new Product[100]; quantity = new int[100]; 
	}
	Basket(int size) {
		products = new Product[size]; quantity = new int[size];
	}
	int total_price()
	{
		int sum = 0;
		for (int i = 0; i < current; i++)
		{
			sum +=products[i].getPrice() * quantity[i];
		}
		return sum;
	}
	void addProducts(Product items, int quant) {
		products[current] = items;
		quantity[current] = quant;
		current++;
	};
	/*3. видалення товарів*/
	void removeProducts(Product items) {
		/*перевіряєм кожний продукт до шуканого, потім всіх, що йдуть після нього ми зсуваєм, перерприсвоюєм */
		int i = 0;
		for (int i = 0; i < current; ++i) {
			if (products[i] == items) {
				if (quantity[i] >= 1) {
					quantity[i]--;
				}
				else
				{
					for (int j = i; j < current; ++j) {
						products[j] = products[j + 1];
					}
					current--;
				}
				break;
			}
		}
	}
	int GetCurrent()
	{
		return current;
	}
	friend ostream& operator<<(ostream& os, Basket& basket) {
		for (int i = 0; i < basket.current; ++i) {
			if (basket.quantity[i] == 0) {/*якщо чогось нема, щоб ми це минали*/
				i++;
			}
			os << "products list: " << basket.products[i] << endl;
			os << "quantity: " << basket.quantity[i] << endl;
		}
		os << "total price is: " << basket.total_price() << endl;
		return os;
	}

};
int main() {
	string answer;
	Basket basket;
	do {
		cout << "Do you want to add or remove product?"<<"\n Or did you fifnsh?"<<endl;
		cin >> answer;
		if (answer == "add" || "Add" || "ADD") {
			Product prod1;
			cin >> prod1;
			cout << "Enter quantity" << endl;
			int quantity;
			cin >> quantity;
			basket.addProducts(prod1, quantity);
		}
		if (answer == "remove" || answer == "Remove" || answer == "REMOVE") {
			if (basket.GetCurrent() == 0) {
				cout << "There are no that products " << endl;
			}
			else {
				cout << basket << endl;
				cout << "what product would you like to delete? Please enter item's code" << endl;
				Product product_code;
				cin >> product_code;
				basket.removeProducts(product_code);
				cout << basket << endl;
			}
		}
	} while (answer != "finished");


}