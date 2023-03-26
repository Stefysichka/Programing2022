#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*Розробити ієрархію класів для ромбовидного наслідування:
транспортний засіб(об’єм двигуна, назва) 1) водний засіб (тип водойми, 
max швидкість у воді), 2)наземний транспорт (max швидкість, кількість 
місць). Від 1) і 2) наслідується трансорт-амфібія (max кількість годин у воді 
і на суші).Ввести дані про 10 різних транспортних засобів: водні, наземні 
і амфібії (човен, підводний човен, вантажівка, всюдихід,…) в один масив, 
видрукувати дані про всі транспортні засоби. Посортувати їх за назвою. 
Знайти засіб з найбільшим і найменшим об’ємом двигуна. Видрукувати окремо
водний транспорт, і окремо транспорт-амфібію*/
class Transport {
protected:
	double engine_volume;
	string name;
public:
	Transport(double e, string n): engine_volume(e), name(n){}
	virtual void PrintInfo() {
		cout << "Name: " << name << endl;
		cout << "Enging volume: " << engine_volume << endl;
	}
	double GetEngineVolume() {
		return engine_volume;
	}
	string GetName() {
		return name;
	}
};
class WaterTransport : virtual public Transport {
protected:
	string water_type;
	double max_water_speed;
public:
	WaterTransport(double e, string n, string w, double m):Transport(e,n), water_type(w), max_water_speed(m){}
};
class LandTransport : virtual public Transport {
protected:
	double max_speed;
	int seats_number;
public:
	LandTransport(double e, string n, double m, int s):Transport(e,n), max_speed(m), seats_number(s){}
};
class AmphibiousTransport : public WaterTransport, public LandTransport {
private:
	double max_hours_on_water_and_land;
public:
	AmphibiousTransport(double e, string n, string w, double m, double ms, int sn, double h) : Transport(e, n), WaterTransport(e, n, w, m), LandTransport(e, n, ms, sn), max_hours_on_water_and_land(h) {}
	void PrintInfo() {
	Transport:PrintInfo();
		cout << "Water type: " << water_type << endl;
		cout << "Max water speed: " << max_water_speed << endl;
		cout << "Max land speed: " << max_speed << endl;
		cout << "Seats number: " << seats_number << endl;
		cout << "Max hours on water and land: " << max_hours_on_water_and_land << endl;
	}
};
bool CompareByName( Transport* t1,  Transport* t2) {
	return t1 -> GetName() < t2 -> GetName();
}
int main() {
	vector<Transport*> transports;
	WaterTransport* boat = new WaterTransport(2.0, "Boat", "Lake", 10.0);
	WaterTransport* submarine = new WaterTransport(3.0, "Submarine", "Ocean", 20.0);
	transports.push_back(boat);
	transports.push_back(submarine);
    LandTransport* truck = new LandTransport(4.0, "Truck", 60.0, 2);
    LandTransport* suv = new LandTransport(3.5, "SUV", 80.0, 5);
    transports.push_back(truck);
    transports.push_back(suv);
	cout << "All transports:" << endl;
	for (Transport* t : transports) {
		t->PrintInfo();
		cout << endl;
	}
	/*1.сортування за іменем*/
	sort(transports.begin(), transports.end(), CompareByName);
	cout << "Sorted by name: " << endl;
	for (Transport* t : transports) {
		t->PrintInfo();
		cout << endl;
	}
	/*2. Знайти засіб з найбільшим і найменшим об’ємом двигуна*/
	Transport* smallest_engine = transports[0];
	Transport* largest_engine = transports[0];
	for (int i = 1; i < transports.size(); ++i) {
		if (transports[i]->GetEngineVolume() < smallest_engine->GetEngineVolume()) {
			smallest_engine = transports[i];
		}
		if (transports[i]->GetEngineVolume() > largest_engine->GetEngineVolume()) {
			largest_engine = transports[i];
		}
	}
	cout << "Transport with the smallest engine volume: " << endl;
	smallest_engine->PrintInfo();
	cout << endl;
	cout << "Transport with the largest engine volume: " << endl;
	largest_engine->PrintInfo();
	/*3.Видрукувати окремо водний транспорт, і окремо транспорт-амфібію*/
	cout << "Water transports: " << endl;
	for (Transport* t : transports) {
		WaterTransport* wt = dynamic_cast<WaterTransport*>(t);
		if (wt != nullptr) {
			t->PrintInfo();
			cout << endl;
		}
	}
	cout << "Amphibious transports: " << endl;
	for (Transport* t : transports) {
		AmphibiousTransport* at = dynamic_cast<AmphibiousTransport*>(t);
		if (at != nullptr) {
			t->PrintInfo();
			cout << endl;
		}
	}
	/*чистка пам'яті*/
	for (Transport* t : transports) {
		delete t;
	}
	return 0;
}