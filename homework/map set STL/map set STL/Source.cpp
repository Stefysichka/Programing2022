/*варіант 13*/
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*1.*/struct Book {
	string author;
	string title;
	int year;
};
struct Article {
	string author;
	string title;
	string journal;
	int year;
};
struct Catalog {
	int number;
	string type;
};
int getCatalogNumber(map<string, int>& catalog, string author) {
	if (catalog.count(author)) {
		return catalog[author];//номер каталогу
	}
	int newNumber = catalog.size() + 1;
	catalog[author] = newNumber;
	return newNumber;
}
bool compareCatalogeNumbers(Catalog c1, Catalog c2) {
	return c1.number < c2.number;
}
int main() {
	ifstream file("data.txt");
	if (!file.is_open()) {
		cout << "Error!";
	}
	map<string, int> catalog;
	vector<Book> books;
	vector<Article> articles;
	string line;
	/*2.*/while (getline(file, line)) {
		if (line == "BOOK") {
			Book book;
			getline(file, book.author);
			getline(file, book.title);
			file >> book.year;
			file.ignore();//пропуск
			int catalogNumber = getCatalogNumber(catalog, book.author);
			Catalog catalogEntry = { catalogNumber,"BOOK" };
			books.push_back(book);
		}
		else if (line == "ARTICLE") {
			Article article;
			getline(file, article.author);
			getline(file, article.title);
			getline(file, article.journal);
			file >> article.year;
			file.ignore();
			int catalogNumber = getCatalogNumber(catalog, article.author);
			Catalog catalogEntry = { catalogNumber,"Article" };
			articles.push_back(article);;
		}
	}
	/*3.*/ vector<Catalog> catalogEntries;
	for (auto& entry : catalog) {
		catalogEntries.push_back({ 
			entry.second,entry.first });//номер каталогу та автор,скорочений вигляд
	}
	sort(catalogEntries.begin(), catalogEntries.end(), compareCatalogeNumbers);
	ofstream file1("catalog.txt");
	for (auto& entry : catalogEntries) {
		file1 << entry.type << " " << entry.number << " " << endl;
	}
	/*4.*/
	ifstream file2("newdata.txt");
	while (getline(file2, line)) {
		if (line == "BOOK") {
			Book book;
			getline(file2, book.author);
			getline(file2, book.title);
			file2 >> book.year;
			file2.ignore();
			int catalogNumber = getCatalogNumber(catalog, book.author);
			Catalog catalogEntry = { catalogNumber, "BOOK" };
			books.push_back(book);
		}
		else if (line == "ARTICLE") {
			Article article;
			getline(file2, article.author);
			getline(file2, article.title);
			getline(file2, article.journal);
			file2 >> article.year;
			file2.ignore();
			int catalogNumber = getCatalogNumber(catalog, article.author);
			Catalog catalogEntry = { catalogNumber, "ARTICLE" };
			articles.push_back(article);
		}
	}
	int year = 1950;
	ofstream file3("newcatalog.txt");
	for (auto& book : books) {
		if (book.year ==year) {
			file3 << "BOOK" << endl;
			file3 << book.author << endl;
			file3 << book.year << endl;
		}
	}
	for (auto& article : articles) {
		if (article.year == year) {
			file3 << "ARTICLE" << endl;
			file3 << article.author << endl;
			file3 << article.title << endl;
			file3 << article.journal << endl;
			file3 << article.year << endl;
		}
	}
	file.close();
	file2.close();
	return 0;
}