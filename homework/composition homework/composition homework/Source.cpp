#include <iostream>
#include <string>
/*Створіть клас для банківського рахунку та  клас Клієнт. Клас 
Банківський рахунок повинен мати поля Клієн, номера рахунку та баланс, 
повинен містити методи для додавання грошей на рахунок і знімання, показ 
балансу та загальної інформації. Клас Клієнт повинен мати поля імʼяі клієнта,
адреса та номер телефону. Ввести дані про 10 банківських рахунків, надати 
можливість пошуку рахунку за іменем клієнта та за адресою клієнта, надати
меню для додавання чи зняття грошей з вибраного рахунку*/
using namespace std;
class Client
{
private:
	string name;
	string adress;
	int phone_number;
public:
	string GetName()
	{
		return name;
	}
	string GetAdress()
	{
		return adress;
	}
	friend ostream& operator<<(ostream& os, Client& client)
	{
		os << "Client name is: " << client.name;
		os << "Adress is: " << client.adress;
	    os<< "Phone number is: "<< client.phone_number << endl;
		return os;
	}
	friend istream& operator>>(istream& is, Client& client)
	{
		cout << "Enter name:";
		is >> client.name;
		cout << "Enter your adress:";
		is >> client.adress;
		cout << "Enter your phone number:";
		is >> client.phone_number;
		return is;
	}
};
class BankAccount
{
private:
	Client client;
	int account_number;
	float balance;
public:
	float Deposit(float sum)
	{
		balance +=sum;
		return balance;
	}
	float Withdraw(float sum)
	{
		balance -= sum;
		return balance;
	}
	float ShowBalance()
	{
		return balance;
	}
	friend ostream& operator<<(ostream& os, BankAccount& bank)
	{
		os << bank.client << endl;
		os << "account number is: " << bank.account_number << endl;
		os << "balance is: " << bank.balance << endl;
		return os;
	}
	friend istream& operator>>(istream& is, BankAccount& bank)
	{
		is >> bank.client;
		cout << "enter account number: " << endl;
		is >> bank.account_number;
		cout << "enter balance: " << endl;
		is >> bank.balance;
		return is;
	}
	string GetName()
	{
		return client.GetName();
	}
	string GetAdress()
	{
		return client.GetAdress();
	}
	bool operator==(const BankAccount& bank)
	{
		return account_number == bank.account_number;
	}
};
BankAccount FindClientbyName(BankAccount* client, string name, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (client[i].GetName() == name)
		{
			return client[i];
		}
	}
	return BankAccount();
}
BankAccount FindClientbyAdress(BankAccount* client, string adress, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (client[i].GetAdress() == adress)
		{
			return client[i];
		}
	}
	return BankAccount();
}
int main()
{
	const int size = 10;
	BankAccount client[size];
	cout << "Please enter information about 10 accounts" << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> client[i];
	}
	string answer;

	do
	{
		cout << "Do you want to find account by name or adress?" << endl;
		cin >> answer;
		BankAccount FoundAccount;
		if (answer == "name")
		{
			string name;
			cout << "Enter your name:" << endl;
			cin >> name;
			FoundAccount = FindClientbyName(client, name, size);
		}
		if (answer == "adress")
		{
			string adress;
			cout << "Enter your adress:" << endl;
			cin >> adress;
			FoundAccount = FindClientbyAdress(client, adress, size);
		}
		if (FoundAccount == BankAccount())
		{
			cout << "not found";
			continue;
		}
		int ans;
		do
		{
			cout << "1) Show balance" << endl;
			cout << "2) Withdraw money" << endl;
			cout << "3) Get money" << endl;
			cout << "4) Exit" << endl;
			cin >> ans;
			switch (ans)
			{
			case 1: cout << FoundAccount.ShowBalance();
				break;
			case 2: cout << "How much money do you want to withdraw?";
				int sum;
				cin >> sum;
				cout << "your balance now is: " << FoundAccount.Withdraw(sum);
				break;
			case 3: cout << "How much money do you want to put?";
				cin >> sum;
				cout << "your balance now:" << FoundAccount.Deposit(sum);
				break;
			default:
				break;
			}
		} while (ans <=4);
	} while (answer != "exit");

	return 0;
}