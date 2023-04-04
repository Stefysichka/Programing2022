#include <iostream>
#include <string>
#include <fstream>
using namespace std;
string UkrainianTranslator(string name) {
	return "З днем народження, " + name + "!";
}
string GermanTranslator(string name) {
	return "Alles Gute zum Geburtstag, " + name + "!";
}
string KoreanTranslator(string name) {
	return name + "씨, 생일 축하합니다!";
}
//функція, яка вітає іменинника за допомогою вибраної мови
string greeting(string(*translator)(string), string name) {
	return translator(name);
}
int main() {
	string name;
	int language;
	cout << "Enter name" << endl;
	cin >> name;
	cout << "choose the greeting language:" << endl;
	cout << "1.ukranian" << endl;
	cout << "2. german" << endl;
	cout << "3. korean" << endl;
	cout << "your choice: ";
	cin >> language;
	string(*translator)(string);
	switch (language) {
	case 1:
		translator = UkrainianTranslator;
		break;
	case 2:
		translator = GermanTranslator;
		break;
	case 3:
		translator = KoreanTranslator;
		break;
	default:
		cout << "Error";
		return 1;
	}
	string massage = greeting(translator, name);
	ofstream file("greetings.txt");
	if (!file.is_open()) {
		cout << "error" << endl;
		return 1;
	}
	file << massage << endl;
	file.close();


}