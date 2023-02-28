#include <iostream>
#include <vector>
/*Створити клас Університет, та класи Студент та Курс. Клас університету повинен 
мати поля назва університету та місце розташування, а також масив студентів та 
масив курсів. Клас Студент повинен мати поля для імені студента, ідентифікаційного
номера та спеціальності. Клас Курс повинен мати поля для назви курсу, номера
курсу, спеціальність, для якої цей курс проводиться. В класі Університет додати 
методи для додавання-видалення студентів та курсів, а також метод для формування 
за вказаним курсом списку студентів, які мали б цей курс прослухати і метод 
формування списку курсів, які би мав цей студент прослухати, метод виведення 
всіх студентів та метод виведення всіх курсів. Ввести дані про університет,
надати меню для додавання-видалення курсів та студентів, а також формування 
списку студентів за вказаним курсом та список курсів для вказаного студента*/
using namespace std;
class Student {
private:
	string name;
	int ID;
	string speciality;
public:
	Student(string n, int i, string s) :name(n), ID(i), speciality(s) {}
	string GetName() {
		return name;
	}
	int GetID() {
		return ID;
	}
	string GetSpeciality() {
		return speciality;
	}
};
class Course {
private:
	string name;
	int number;
	string speciality;
public:
	Course(string n, int num, string s) :name(n), number(num), speciality(s) {}
	string GetName() {
		return name;
	}
	int GetNumber() {
		return number;
	}
	string GetSpeciality(){
		return speciality;
	}
};
class University {
private:
	string name;
	string location;
	vector <Student> students;
	vector <Course> courses;
public:
	University(string n, string l):name(n),location(l){}
	//метод додавання студентів
	void AddStudents(Student s) {
		students.push_back(s);
	}
	//метод видалення студентів
    void RemoveStudents(Student s) {
		for (int i = 0; i < students.size(); i++) {
			if (students[i].GetID() == s.GetID()) {
				students.erase(students.begin() + i);/*erase який приймає ітератор, що вказує
				на елемент, який потрібно видалити, і видаляє цей елемент з вектора*/
				break;
			}
		}
	}
	void AddCourse(Course c) {
		courses.push_back(c);
	  }
	void RemoveCourse(Course c) {
		for (int i = 0; i < courses.size(); i++) {
			if (courses[i].GetNumber() == c.GetNumber()) {
				courses.erase(courses.begin() + i);
				break;
			}
		}
	}
	//метод для формування за вказаним курсом списку студентів
	vector<Student> GetStudentInCourse(Course c) {
		vector<Student> result;
		for (int i = 0; i < students.size(); ++i) {
			if (students[i].GetSpeciality() == c.GetSpeciality()) {
				result.push_back(students[i]);
			}
		}
		return result;
	}
	//метод формування списку курсів, які би мав цей студент прослухати
	vector<Course> GetCoursesForStudents(Student s) {
		vector<Course> result;
		for (int i = 0; i < courses.size(); i++) {
			if (courses[i].GetSpeciality() == s.GetSpeciality()) {
				result.push_back(courses[i]);
			}
		}
		return result;
	}
	//метод виведення всіх студентів
	void PrintStudents() {
		cout << "Students in " << name << ":" << endl;
		for (int i = 0; i < students.size(); ++i) {
			cout << students[i].GetName() << ",ID: " << students[i].GetID() << ", Speciality: " << students[i].GetSpeciality() << endl;
		}
		cout << endl;
	}
	//метод виведення всіх курсів
	void PrintCourses() {
		cout << "Courses in " << name << ":" << endl;
		for (int i = 0; i < courses.size(); ++i) {
			cout << courses[i].GetName() << ",Number: " << courses[i].GetNumber() << "<Speciality: " << courses[i].GetSpeciality() << endl;
		}
		cout << endl;
	}
};
int main() {
	University u("Example University", "Example Location");
	bool exit = false;
	while (!exit) {
		cout << "1. Add student" << endl;
		cout << "2. Remove student" << endl;
		cout << "3. Add course" << endl;
		cout << "4. Remove course" << endl;
		cout << "5. Get students in course" << endl;
		cout << "6. Get courses for student" << endl;
		cout << "7. Print all students" << endl;
		cout << "8. Print all courses" << endl;
		cout << "9. Exit" << endl;
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: {
			string name, speciality;
			int id;
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter ID: ";
			cin >> id;
			cout << "Enter speciality: ";
			cin >> speciality;
			Student s(name, id, speciality);
			u.AddStudents(s);
			break;
		}
		case 2: {
			int id;
			cout << "Enter ID of student you want to remove: ";
			cin >> id;
			Student s("", id, "");
			u.RemoveStudents(s);
			break;
		}
		case 3: {
			string name, specialty;
			int number;
			cout << "Enter name: ";
			cin >> name;
			cout << "Enter number: ";
			cin >> number;
			cout << "Enter specialty: ";
			cin >> specialty;
			Course c(name, number, specialty);
			u.AddCourse(c);
			break;
		}
		case 4: {
			int number;
			cout << "Enter number of course you want to remove: ";
			cin >> number;
			Course c("", number, "");
			u.RemoveCourse(c);
			break;
		}
		case 5: {
			int number;
			cout << "Enter number of course: ";
			cin >> number;
			Course c("", number, "");
			vector<Student> students = u.GetStudentInCourse(c);
			cout << "Students in course " << number << ":" << endl;
			for (int i = 0; i < students.size(); i++) {
				cout << students[i].GetName() << ", ID: " << students[i].GetID() << ", Specialty: " << students[i].GetSpeciality() << endl;
			}
			cout << endl;
			break;
		}
		case 6: {
			int id;
			cout << "Enter ID of student: ";
			cin >> id;
			Student s("", id, "");
			vector<Course> courses = u.GetCoursesForStudents(s);
			cout << "Courses for student " << id << ":" << endl;
			for (int i = 0; i < courses.size(); i++) {
				cout << courses[i].GetName() << ", Number: " << courses[i].GetNumber() << ", Specialty: " << courses[i].GetSpeciality() << endl;
			}
			cout << endl;
			break;
		}
		case 7: {
			u.PrintStudents();
			break;
		}
		case 8: {
			u.PrintCourses();
			break;
		}
		case 9: {
			exit = true;
			break;
		}
		default: {
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
		}
	}
	return 0;
}
	