#include <iostream>  
#include <string>  
using namespace std;

class Advertising {
/*1*/private:
    string text;
    double price;
    int repetition;

public:
    Advertising() : text(" "), price(0.0), repetition(0) {}
    Advertising(string t, double p, int r) : text(t), price(p), repetition(r) {}
    Advertising(const Advertising& advertising) : text(advertising.text), price(advertising.price), repetition(advertising.repetition) {}
    friend ostream& operator<<(ostream& os, Advertising& advertising) {
        os << advertising.text << " \n Price of advertising is : " << advertising.price << endl;

        return os;
    }
    friend istream& operator>>(istream& is, Advertising& advertising) {
        cout << "Enter text of advertising" << endl;
        getline(cin, advertising.text);
        cout << "Enter price of advertising" << endl;
        is >> advertising.price;
        cout << "Enter repetition of those advertising" << endl;
        is >> advertising.repetition;
        return is;
    }
    bool operator<(Advertising advertising) {
        if (price < advertising.price) {
            return true;
        }
        return false;
    }
    string getText() {
        return text;
    }
    double getPrice() {
        return price;
    }
    double getRepetition() {
        return repetition;
    }

};
void sort(Advertising* array, int n);
void theMostExpensiveAdvertising(Advertising* array, int n);
void theLongestText(Advertising* array, int n);
void theShortestText(Advertising* array, int n);
int main() {
    /*2*/  int n = 6;
    Advertising* array = new Advertising[n];

    for (int i = 0; i < 3; i++) {
        cin >> array[i];
    }
    Advertising a1;
    Advertising a2("Hello world", 100, 3);
    Advertising a3(array[0]);
    array[3] = a1;
    array[4] = a2;
    array[5] = a3;
    sort(array, n);
    for (int i = 0; i < n; ++i) {
        cout << array[i];
    }
    /*3*/
    theMostExpensiveAdvertising(array, n);
    theLongestText(array, n);
    theShortestText(array, n);



}
void sort(Advertising* array, int n) {
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
            if (array[i].getPrice() < array[j].getPrice()) {
                Advertising temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
    }
}
void theMostExpensiveAdvertising(Advertising* array, int n) {
    double* max_values = new double[n];
    for (int i = 0; i < n; ++i)
    {
        max_values[i] = array[0].getPrice();
        if (array[i].getPrice() > max_values[i])
        {
            max_values[i] = array[i].getPrice();
            for (int j = 0; j < array[i].getRepetition(); ++j)
            {
                cout << max_values[j] << endl;

            }
        }

    }
}
void theLongestText(Advertising* array, int n) {
    string* max = new string[n];
    for (int i = 0; i < n; ++i)
    {
        max[i] = array[0].getText();
        if (array[i].getText() > max[i])
        {
            max[i] = array[i].getText();
            cout << max[i] << endl;
        }

    }
}
void theShortestText(Advertising* array, int n) {
    string* min = new string[n];
        for (int i = 0; i < n; ++i) {
            min[i] = array[0].getText();
            if (array[i].getText() < min[i]) {
                min[i] = array[i].getText();
                cout << min[i];
            }
        }
}