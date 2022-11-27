#include <iostream>
#include <ctime>
using namespace std;
//рекурсивні функції, ті які викликають самі себе
//1. факторіал числа
/*long factorial(long a) {
	if (a > 1)
		return(a * factorial(a - 1));
	else
		return (1);
}
int main() {
	long number;
	cout << "Please type a number";
	cin >> number;
	cout << number << "!= " << factorial(number);
	return 0;
}*/
//2. сортування вибором
int min_element(const int* arr, size_t size/*розмір*/, size_t& offset /*звідки починаєм*/) {
	offset = 0;
	int min_element = arr[0];
	for (size_t i = 1; i < size; ++i) {
		if (arr[i] < min_element) {
			min_element = arr[i];
				offset = i;
		}
	}
	return min_element;
}
void sort(int* arr, size_t size) {
	int temp;
	size_t offset;
	for (size_t i = 0; i < size - 1; ++i) {
		temp = min_element(arr + i/*вказує на 1 елемент*/, size - 1, offset/*є мінімальним*/);
		/*шукаєм мінімальний від 1потім від 2*/
		if (offset > 0) {
			arr[ offset] = arr[i];
			arr[i] = temp;
		}
	}
}
// 3. двовимірний масив
// виділення памяті під двовимірний масив з радків та стовпців
int** new_array(size_t rows, size_t columns) {
	int** d = new int* [rows]/*створити масив, для кожного рядка свій масив,елементи матриці*/;
	for (size_t i = 0; i < rows; ++i)
		d[i] = new int[columns];
	return d;
}
//заповнення двохвимірного масиву випадковими числами
void random_array(int** array, size_t rows, size_t columns) {
	srand(time(0));
	rand();
	int RANGE_MAX = 100;//рандомні числа до 100
	for (size_t i = 0; i < rows; ++i)
		for (size_t j = 0; j < columns; j++)
			array[i][j] = rand() % RANGE_MAX;
}
//виведення в потік елементів двохвимірного масиву
void print_array(int** array, size_t rows, size_t columns) {
	cout << "Array:" << endl;
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < columns; ++j) {
			cout << "\tarr[" << i << "][" << j << "]==" << array[i][j];
			cout << endl;
	}
		cout << endl;
}
	//звільнення памяті, виділеної під двовимірний масив
	void delete_array(int ** d, size_t rows); {
		for (size_t i = 0; i < rows; ++i) 
			delete [] d[i];
	
		delete [] d;

	}
	int main() {
		size_t rows = 4;
		size_t columns = 3;
		int** d = new_array(rows, columns);//створення масиву
		random_array(d/*адреса масиву*/, rows, columns);
		print_array(d, rows, columns);
		delete_array(d, rows);
		return 0;
	}
