#include <iostream>
#include <math.h>
using namespace std;
/*1*/
int past(int h, int m, int s) {
	if (h >= 0 && h <= 23 && m >= 0 && m <= 60 && s >= 0 && s <= 60) {
		h *= 36000;
		m *= 60000;
		s *= 1000;
	}
	else {
		cout << "Try entering again" << endl;
	}
	return h + m + s;
}
/*2*/
#include <vector>

std::vector<int> invert(std::vector<int> values)
{
	for (int i = 0; i < values.size(); i++)
		values[i] *= -1;
	return values;
}
/*3*/
bool is_even(double n)
{
	long long x = (long long)n;//перевід в цілі числа
	if (x != n)
		return false;
	return (x % 2 == 0);
}
/*4*/
int cockroach_speed(double s)
{
	return (s * 100000 / 3600);
}
/*5*/
int area_or_perimeter(int l, int w) {
	int area = l * w;
	int perimeter = (l + w) * 2;
	if (l == w)
		return area;
	else
		return perimeter;
	return 0;
}
/*6*/
/*auto при ініціалізації змінної може
використовуватися замість типу змінної,щоб
повідомити компілятор, що він повинен присвоїти 
тип змінної виходячи з значення, що ініціалізується.*/
#include <string>
std::string fakeBin(std::string str) {
	for (auto& x : str) {
		if (x < '5') x = '0';
		else x = '1';
	}
}
/*7*/
bool isDivisible(int n, int x, int y) {
	if (n % x != 0 || n % y != 0)
		return false;
	else
		return true;

}
/*8*/
std::string get_planet_name(int id)
{
	std::string planets[] = { "","Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune" };
	return planets[id]; //перевести планету в її порядковий номер
}
/*9*/
/*toupper перетворює малу літеру на велику*/
std::string abbrevName(std::string name)
{
	std::string first, last;
	first = toupper(name[0]);
	int pass = name.find(" ");
	last = toupper(name[pass + 1]);
	std::cout << first << "." << last << std::endl;
	return first + "." + last;
}
/*10*/
//чи все caps
bool is_uppercase(const std::string& s) {
	for (int i = 0; i < s.length(); ++i)
		if (std::islower(s[i]))
			return false;
	return true;
}