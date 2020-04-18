#include <iostream>
#include <cstdlib>
using namespace std;

template <class T>
class SmartPtr {
private:
	T* tptr;
public:
	SmartPtr(T *ptr) : tptr(ptr) {}
	T& operator*() const { return *tptr; }
	T* operator->() const { return tptr; }
	SmartPtr() { delete tptr; }
};

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void SetPos(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void ShowPosition() const { cout << '[' << xpos << ", " << ypos << ']' << endl; }
};

int main(void) {
	SmartPtr<Point> sptr1(new Point(1, 2));
	SmartPtr<Point> sptr2(new Point(2, 3));
	sptr1->ShowPosition();
	sptr2->ShowPosition();

	return 0;
}