#include <iostream>

#include <cstdlib>

using namespace std;



class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	friend ostream& operator<<(ostream &os, const Point& pos);
	friend ostream& operator<<(ostream &os, const Point* pos);
};

ostream& operator<<(ostream& os, const Point& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

ostream& operator<<(ostream& os, const Point* pos) {
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

	POINT_PTR operator[](int idx) const {
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

	arr[0] = new Point(3, 4);

	arr[1] = new Point(5, 6);

	arr[2] = new Point(7, 8);

	for (int i = 0; i < arr.GetArrLen(); i++)
		cout << arr[i];

	delete arr[0];

	delete arr[1];

	delete arr[2];

	return 0;

}