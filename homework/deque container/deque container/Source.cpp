#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct GasBill {
	string surnname;
	int num_of_residents;
	double amount_paid;
};
struct WaterBill {
	string surnname;
	int last_matter_reading; //останні покази лічильника
	float water_volume;
	float amount_paid;
};
bool SortGasBills(GasBill& bill1, GasBill& bill2) {
	return bill1.num_of_residents > bill2.num_of_residents;
}
bool SortWaterBills1(WaterBill& bill1, WaterBill& bill2) {
	return bill1.surnname < bill2.surnname;
}
bool SortWaterBills2(WaterBill& bill1, WaterBill& bill2) {
	return bill1.amount_paid > bill2.amount_paid;
}
int main() {
	//1. зчитати дані з файлу та зберегти у відповідні контейнери
	ifstream file("bills.txt");
	vector<GasBill> gas_bills;//контейнери для зберігання даних
	vector<WaterBill> water_bills;
	string bill_type;
	while (file >> bill_type) {
		if (bill_type == "gas") {
			GasBill bill;
			file>>bill.surnname>>bill.num_of_residents >> bill.amount_paid;
			gas_bills.push_back(bill);
		}
		else if (bill_type == "water") {
			WaterBill bill;
			file >> bill.surnname >> bill.last_matter_reading >> bill.water_volume >> bill.amount_paid;
			water_bills.push_back(bill);
		}
	}
	sort(gas_bills.begin(), gas_bills.end(), SortGasBills);
	sort(water_bills.begin(), water_bills.end(), SortWaterBills1);
	//2. записати у відповідні файли
	ofstream file1("gas_bills.txt");
	for (const GasBill& bill : gas_bills) {
		cout << "Surname: " << bill.surnname << " | Num of residents: " << bill.num_of_residents << " | Amount paid: " << bill.amount_paid << endl;
		file1 << bill.surnname << " " << bill.num_of_residents << " " << bill.amount_paid << endl;
	}
	file1.close();
	ofstream file2("water_bills.txt");
	for (const WaterBill& bill : water_bills) {
		cout << "Surname: " << bill.surnname << " | Last matter reading: " << bill.last_matter_reading << " | Water volume: " << bill.water_volume << " | Amount paid: " << bill.amount_paid << endl;
		file2 << bill.surnname << " " << bill.last_matter_reading << " " << bill.water_volume << " " << bill.amount_paid << endl;
	}
	file2.close();
    //3. вивести у окремий файл 5 найбільших оплат за воду
	sort(water_bills.begin(), water_bills.end(), SortWaterBills2);
	ofstream file3("highest_paid_water_bills.txt");
	for (int i = 0; i < 5 && i < water_bills.size(); i++) {
		const WaterBill& bill = water_bills[i];
		cout << "Surname: " << bill.surnname << " | Amount paid: " << bill.amount_paid << endl;
		file3 << bill.surnname << " " << bill.amount_paid << endl;
	}
	file3.close();
	return 0;
}