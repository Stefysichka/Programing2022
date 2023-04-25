#include <iostream>
#include <string>
#include <list>
using namespace std;
int main() {
	list<char> List;
	string input;
	cout << "Enter a sequence of characters: " << endl;
	getline(cin, input);
	for (char c : input) {
		List.push_back(c);
	}
//1.Видалити всі коми, що йдуть перед першою крапкою
	bool found = false;
	for (auto it = List.begin(); it != List.end(); ++it) {
		if (*it == '.') {
			found = true;
		}
		if (!found && *it == ',') {
			auto erase_it = it;
			--it;
			List.erase(erase_it);
		}
	}

//2.Замінити всі цифри 3, що йдуть після першої крапки, на знак "+"
	found = false;
	for (auto it = List.begin(); it != List.end(); it++) {
		if (*it == '.') {
			found = true;
		}
		if (found && isdigit(*it) && *it == '3') {
			*it = '+';
		}
	}
	for (char c : List) {
		cout << c;
	}
	cout << endl;
	return 0;
}