#include <iostream>
#include <string>
#include <cstring>//для С
using namespace std;
//1.знайти скільки кожного з символів у введеному тексту
/*bool isintext(string text, char a, int k) {
	for (int i = 0; i <=k; i++) {
		if (text[i] == a) {
			return true;
		}
		return false;
	}
}
int countch(string text, char a, int l) {
	int s = 0;
	for (int i = l; i < text.size(); ++i) {
		if (text[i] = a) {
			s++;
			return s;
		}
	}
	
}
void main() {
	cout << "Enter text" << endl;
	string text;
	getline(cin, text);
	for (int i = 0; i < text.size(); ++i) {
		if (!isintext(text, text[i], i - 1)) {
			cout << text[i] << '-' << countch(text, text[i], i);
		}
	}
}*/
//2. Ввести текст, що містить записи цілих чисел, розділених комою, в кінці тексту – крапка (напр.: 123,45,67,234,-34.).  Порахувати суму цих чисел, попередньо перевівши послідовність символів, що представляють число у ціле число.
void main(){
	// 1)через пропуск 
	/*string text[10];
	cout << "enter text" << endl;
	for (int i = 0; i < 10; ++i) {
		cin >> text[i];
	}
	int mas[10];
	for (int i = 0; i < 10; ++i) {
		mas[i] = stoi(text[i]);//переведення тексту в числа
	}
	int sum = 0;
	for (int j = 0; j < 10; j++) {
		sum += mas[10];
	}
	cout << "the sum is " << sum << endl;*/
	// 2)через кому
	string text[10];
	cout << "enter text" << endl;
	string fulltext;
	getline(cin, fulltext);
	int i = 0;
	int j = 0;
	text[0] = ' ';
	while (fulltext[i] != '.') {
		if (fulltext[i] != ',') {
			text[j] += fulltext[i];
		}
		else {
			j++; text[j] = " ";
		}
		i++;
		int n = j;
	}
	int mas[10];
	for (int i = 0; i < 10; ++i) {
		mas[i] = stoi(text[i]);//переведення тексту в числа
	}
	int sum = 0;
	for (int j = 0; j < 10; j++) {
		sum += mas[10];
	}
	cout << "the sum is " << sum << endl; 
		//якщо від символа числа відняти нуль, то буде ціле число

	}

//РЯДКИ В СТИЛІ С
// strlen() повертає довжину масиву символів 
int main() {
	char name[20] = "Marko";
	cout << "My name is:" << name << '\n';
	cout << name << "has" << strlen(name) << "letters.\n";//кількість букв в слові
	cout << name << "has" << sizeof(name) << "characters in the array.\n";//розмір масиву
	return 0;
}