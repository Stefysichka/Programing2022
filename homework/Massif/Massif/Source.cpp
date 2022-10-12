#include <iostream>
#include <string>
#include <math.h>
using namespace std;
 int main()
{
	/* 1.double a[100];
	int n;
	cout << "Enter n";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

	}
	double S=a[0];
	double b[100];
	for (int i= 0; i < n; i++)
	{
		b[i] = a[i] / (1 + S * S);
		S = S + a[i + 1];
		cout << "b=" << b[i] << endl;

	}*/
	 /* 2.Ввести натуральне число k. Знайти всі його натуральні дільники
	 cout << "Enter k" << endl;
	 int k;
	 cin >> k;
	 //%остача,==присвоєння
	 for (int i = 1; i < k; i++) {
		 if (k % i == 0)
		 {
			 cout <<i<<endl;
		 }
			 */
	 /*	 3.Перевірити чи утворюють спадну послідовність введені m дійсних чисел.
	 double a[100];
	 cout<<"Enter n";
	 int n;
	 cin >> n;
	 for(int i=0;i< n;i++){
		 cin >> a[i];
	 
	 }
	 bool s = true;
	  
		 for (int i = 0; i < n; i++) {
			 if (a[i] < a[i + 1]) {
			  cout << "Non-decreasing" << endl;
			  break; s = false;
			 }

		 }
		 if (s == true)
			 cout << "Decreasing" << endl;*/
	 // 4.Ввести натуральне число n і масив з n дійсних чисел. Знайти і видрукувати значення і позицію в масиві найменшого додатного числа
	 int n;
	 cout << "Enter n";
	 cin >> n;
	 int array[100];
	 for (int i = 0; i < n; i++) {
		 cout << "enter x" << i << endl;
		 cin >> array[i];
	 }
	 int min[] = { array[0],0 };
		 int index = 0;
		 for (int i = 0; i < n; i++) {
			 if (array[i] < min[0]) {
		 min[0] = array[i];
		 min[1] = i;
			 }
	 }

	
	
return 0;

}
