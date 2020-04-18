#include <iostream>
#include <cstdlib>
using namespace std;

template <class T> 
void SwapData(T& n1, T& n2) {
	T tmp;
	tmp = n1;
	n1 = n2;
	n2 = tmp;
}

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}
	void ShowPosition() const {
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
};

int main(void) {
	Point pnt1(1, 2);
	Point pnt2(2, 3);
	SwapData<Point>(pnt1, pnt2);
	pnt1.ShowPosition();
	pnt2.ShowPosition();
	
	return 0;
}