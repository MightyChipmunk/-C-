#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
	char* title;
	char* isbn;
	int price;
public:
	Book(char* title, char* isbn, int _price) : price(_price) {
		int tlen = strlen(title) + 1;
		this->title = new char[tlen];
		strcpy(this->title, title);
		
		int ilen = strlen(title) + 1;
		this->isbn = new char[ilen];
		strcpy(this->isbn, isbn);
	}
	void ShowBookInfo() {
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
	~Book() {
		delete []title;
		delete []isbn;
	}
};

class EBook : public Book {
private:
	char* DRMKey;
public:
	EBook(char* _title, char* _isbn, int _price, char* DRMKey) : Book(_title, _isbn, _price) {
		int len = strlen(DRMKey) + 1;
		this->DRMKey = new char[len];
		strcpy(this->DRMKey, DRMKey);	
	}
	void ShowEBookInfo() {
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}
	~EBook() {
		delete []DRMKey;
	}
};

int main(void) {
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	
	cout<<endl;
	
	EBook ebook("좋은 c++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	
	return 0;
}
