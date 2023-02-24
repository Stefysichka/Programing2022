#include <iostream> 

#include <string> 

using namespace std;

class Street {

private:

    string nameb;

    int buildings;

public:

    Street(string n, int b) :nameb(n), buildings(b) {}
    Street() :buildings(0), nameb("Stefik") {}
    string GetNameb() {

        return nameb;

    }

    string SetNameb(string new_name) {

        nameb = new_name;

    }

    int GetBuildings() {

        return buildings;

    }

    int SetBuildings(int new_buildings) {

        buildings = new_buildings;

    }

    friend istream& operator>>(istream& is,Street& street) {

        cout << "Enter street name" << endl;

        is >> street.nameb;

        cout << "Enter number of buildings" << endl;

        is >> street.buildings;

        return is;

    }

    friend ostream& operator<<(ostream& os, const Street& street) {

        os << "Street name is: " << street.nameb << endl;

        os << "Nuber of buildings is: " << street.buildings << endl;
        return os;
    }

};

class City {

private:

    Street* streets;

    int quantity;

    string names;

public:

    City(Street* streets, int quantity, string name) :streets(streets), quantity(quantity), names(names) {}
    City(int quantity, string names) {
        streets = new Street[quantity];
    }
    //конструктор копіювання 

    City(const City& c) :streets(streets), quantity(c.quantity), names(c.names) {

        if (c.streets != streets) {

            streets = new Street[quantity];

            for (int i = 0; i < quantity; ++i) {

                streets[i] = c.streets[i];

            }

        }

    }

    City& operator=(const City& city) {
        if (this != &city) {
            delete[] streets;
            quantity = city.quantity;
            names = city.names;
            streets = new Street[quantity];
            for (int i = 0; i < quantity; ++i) {
                streets[i] = city.streets[i];
            }
        }
        return *this;
    }

    ~City() {
delete[] streets;
}
string GetName() const {
    return names; }
void SetName(string new_name) {
    names = new_name; }
int GetQuantity() const {
    return quantity; }
Street* GetStreets() const {
    return streets; }
friend istream& operator>>(istream& is, City& city) {
cout << "Enter city name:" << endl;
is >> city.names;
cout << "Enter quantity of streets:" << endl;
is >> city.quantity;
city.streets = new Street[city.quantity];
for (int i = 0; i < city.quantity; i++) {
cout << "Enter data for street " << i+1 << ":" << endl;
is >> city.streets[i];
}
return is;
}
friend ostream& operator<<(ostream& os, const City& city) {
os << "City name is: " << city.names << endl;
os << "Number of streets is: " << city.quantity << endl;
for (int i = 0; i < city.quantity; i++) {
os << "Data for street " << i+1 << ":" << endl;
os << city.streets[i];
}
return os;
}
int CountBuildings() const {
int sum = 0;
for (int i = 0; i < quantity; i++) {
sum += streets[i].GetBuildings();
}
return sum;
}
};

City CopyCityWithLeastStreets(City& c1, City& c2) {
if (c1.GetQuantity() < c2.GetQuantity()) {
return City(c1);
}
else {
return City(c2);
}
}

bool CompareCities(City& c1, City& c2) {
return c1.GetQuantity() > c2.GetQuantity();
}

Street GetLongestStreet(City& city) {
Street longest = city.GetStreets()[0];
for (int i = 1; i < city.GetQuantity(); i++) {
if (city.GetStreets()[i].GetNameb().length() > longest.GetNameb().length()) {
longest = city.GetStreets()[i];
}
}
return longest;
}

int main() {
City c1(3, "New York");
cin >> c1;
City c2(2, "San Francisco");
cin >> c2;
cout << "Cities sorted by number of streets:" << endl;
if (CompareCities(c1, c2)) {
    cout << c1 << c2;
}
else {
    cout << c2 << c1;
}

City c3 = CopyCityWithLeastStreets(c1, c2);
cout << "New city created by copying the city with the least streets:" << endl;
cout << c3;

cout << "Longest street in New York is:" << endl;
cout << GetLongestStreet(c1);
cout << "Longest street in San Francisco is:" << endl;
cout << GetLongestStreet(c2);

return 0;
};

