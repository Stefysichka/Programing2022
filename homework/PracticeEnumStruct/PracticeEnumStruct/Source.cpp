#include <iostream>
#include <ctime>
#include <string>
using namespace std;
/*Визначити перелічення для зберігання порід собак DogBreeds.
Написати функцію, яка в  масив з n елементів рандомно генерує 
дані типу DogBreeds. В програмі користуючись цим масивом,
в циклі  просити користувача ввести породу собаки, якщо такої породи в масиві 
нема – вивести відповідне повідомлення і продовжити вводити доти, доки не 
знайдеться така порода в масиві*/
enum DogBreeds {
	SHPIC,
	HASKY,
	TAKSA,
	NOBREED=-1
};
void add_elem(DogBreeds* array, int n) {
	for (int i = 0; i < n; ++i) {
		array[i] = DogBreeds(rand() % 3)/*обмеження в 3 елемента*/;
	}
}
void print_breeds(DogBreeds* array_1, int n) {
	for (int i = 0; i < n; ++i) {
		switch (array_1[i]) {
		case 0:
			cout << "Breed--" << "Shpic" << endl;
			break;
		case 1:
			cout << "Breed--" << "Hasky" << endl;
			break;
		case 2:
			cout << "Breed--" << "Taksa" << endl;
			break;

		}
	}
}
DogBreeds str_to_dogbreeds(string a) {
	for (int i = 0; i < a.size(); ++i) {
		a[i] = tolower(a[i]);//переведення з тексту догбрідс
	}
	if (a == "Shpic") {
		return SHPIC;
	}
	else if (a == "Hasky") {
		return HASKY;
	}
	else  if (a == "Taksa") {
		return TAKSA;
	}
	else {
		return NOBREED;
	}
}
int main() {
	int n;
	cout << "enter n" << endl;
	cin >> n;
	bool res = false;
	DogBreeds result;
	string breed;
	DogBreeds* array_breeds = new DogBreeds[n];
	add_elem(array_breeds, n);
	//print_breeds(array_breeds, n);
	while(res==false){
	cout << "Enter a breed" << endl;
	cin>>breed;
	result = str_to_dogbreeds(breed);
	for (int i = 0; i < n; ++i) {
		if (result == array_breeds[i]) {
			cout << "Breed is found" << endl;
			res = true;
			break;
		}
		if (res = false) {
			cout << "Try again" << endl;


		}
	}
		return 0;
	}
