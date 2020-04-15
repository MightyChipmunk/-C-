#include <iostream>

#include <cstdlib>

using namespace std;



class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	friend ostream& operator<<(ostream &os, const Point &pos);
};



ostream& operator<<(ostream& os, Point* pos) {
	os << '[' << pos->xpos << ", " << pos->ypos << ']' << endl;
	return os;
}

typedef Point *POINT_PTR; //Point 포인터 형을 의미하는 POINT_PTR을 정의하였다. 저장의 대상, 또는 연산의 주 대상이 포인터인 경우, 이렇듯 별도의 자료형을 정의하는 것이 좋다

class BoundCheckPointPtrArray {
private:
	POINT_PTR *arr;
	int arrlen;
	BoundCheckPointPtrArray(const BoundCheckPointPtrArray &arr) {}
	BoundCheckPointPtrArray &operator=(const BoundCheckPointPtrArray &arr) {}
public:
	BoundCheckPointPtrArray(int len) :arrlen(len) {
		arr = new POINT_PTR[len]; //저장의 대상이 Point 객체의 주소 값이기 때문에 POINT_PTR 배열을 생성
	}

	POINT_PTR &operator[](int idx) {
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	POINT_PTR operator[](int idx) const	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}

	int GetArrLen() const {
		return arrlen;
	}

	~BoundCheckPointPtrArray() {
		delete[]arr;
	}
};



int main(void)

{

	BoundCheckPointPtrArray arr(3);
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
			strcpy_s(this->title, tlen, title);

			int ilen = strlen(isbn) + 1;
			this->isbn = new char[ilen];
			strcpy_s(this->isbn, ilen, isbn);
		}
		Book(const Book& copy) : price(copy.price) {
			int tlen = strlen(copy.title) + 1;
			this->title = new char[tlen];
			strcpy_s(this->title, tlen, copy.title);

			int ilen = strlen(copy.isbn) + 1;
			this->isbn = new char[ilen];
			strcpy_s(this->isbn, ilen, copy.isbn);
		}
		void ShowBookInfo() {
			cout << "제목: " << title << endl;
			cout << "ISBN: " << isbn << endl;
			cout << "가격: " << price << endl;
		}
		Book& operator=(const Book& copy) {
			delete[] title;
			delete[] isbn;

			int tlen = strlen(copy.title) + 1;
			this->title = new char[tlen];
			strcpy_s(this->title, tlen, copy.title);

			int ilen = strlen(copy.isbn) + 1;
			this->isbn = new char[ilen];
			strcpy_s(this->isbn, ilen, copy.isbn);

			price = copy.price;
			return *this;
		}
		~Book() {
			delete[] title;
			delete[] isbn;
		}
	};

	class EBook : public Book {
	private:
		char* DRMKey;
	public:
		EBook(char* _title, char* _isbn, int _price, char* DRMKey) : Book(_title, _isbn, _price) {
			int len = strlen(DRMKey) + 1;
			this->DRMKey = new char[len];
			strcpy_s(this->DRMKey, len, DRMKey);
		}
		EBook(const EBook& copy) : Book(copy) { //복사 생성자 호출, Book 참조자는 Book을 참조하는 EBook의 객체를 참조할 수 있다.
			int len = strlen(copy.DRMKey) + 1;
			this->DRMKey = new char[len];
			strcpy_s(this->DRMKey, len, copy.DRMKey);
		}
		void ShowEBookInfo() {
			ShowBookInfo();
			cout << "인증키: " << DRMKey << endl;
		}
		EBook& operator=(const EBook& copy) {
			Book::operator=(copy);
			delete[] DRMKey;

			int len = strlen(copy.DRMKey) + 1;
			this->DRMKey = new char[len];
			strcpy_s(this->DRMKey, len, copy.DRMKey);

			return *this;
		}
		~EBook() {
			delete[] DRMKey;
		}
	};

	int main(void) {
		Book book("좋은 C++", "555-12345-890-0", 20000);
		book.ShowBookInfo();

		cout << endl;

		EBook ebook("좋은 c++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
		ebook.ShowEBookInfo();

		return 0;
	}
	arr[0] = new Point(3, 4);

	arr[1] = new Point(5, 6);

	arr[2] = new Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++)
		cout << *(arr[i]);

	delete arr[0];

	delete arr[1];

	delete arr[2];

	return 0;

}