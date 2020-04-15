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

typedef Point *POINT_PTR; //Point ������ ���� �ǹ��ϴ� POINT_PTR�� �����Ͽ���. ������ ���, �Ǵ� ������ �� ����� �������� ���, �̷��� ������ �ڷ����� �����ϴ� ���� ����

class BoundCheckPointPtrArray {
private:
	POINT_PTR *arr;
	int arrlen;
	BoundCheckPointPtrArray(const BoundCheckPointPtrArray &arr) {}
	BoundCheckPointPtrArray &operator=(const BoundCheckPointPtrArray &arr) {}
public:
	BoundCheckPointPtrArray(int len) :arrlen(len) {
		arr = new POINT_PTR[len]; //������ ����� Point ��ü�� �ּ� ���̱� ������ POINT_PTR �迭�� ����
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
			cout << "����: " << title << endl;
			cout << "ISBN: " << isbn << endl;
			cout << "����: " << price << endl;
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
		EBook(const EBook& copy) : Book(copy) { //���� ������ ȣ��, Book �����ڴ� Book�� �����ϴ� EBook�� ��ü�� ������ �� �ִ�.
			int len = strlen(copy.DRMKey) + 1;
			this->DRMKey = new char[len];
			strcpy_s(this->DRMKey, len, copy.DRMKey);
		}
		void ShowEBookInfo() {
			ShowBookInfo();
			cout << "����Ű: " << DRMKey << endl;
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
		Book book("���� C++", "555-12345-890-0", 20000);
		book.ShowBookInfo();

		cout << endl;

		EBook ebook("���� c++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
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