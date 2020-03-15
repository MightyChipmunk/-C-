#include <iostream>
using namespace std;

typedef struct __Point {
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2);

int main() {
	Point *pnt1 = new Point;
	Point *pnt2 = new Point;
	pnt1->xpos = 10;
	pnt1->ypos = 20;
	pnt2->xpos = 30;
	pnt2->ypos = 40;
	Point &pnt = PntAdder(*pnt1, *pnt2); //PntAdder의 반환이 참조자인거에 맞춰 참조자 &pnt선언
	cout << pnt.xpos << ' ' << pnt.ypos << endl;

	delete pnt1;
	delete pnt2;
	delete &pnt;

	return 0;
}

Point& PntAdder(const Point &p1, const Point &p2) {
	Point *pnt = new Point; //구조체 동적할당
	pnt->xpos = p1.xpos + p2.xpos;
	pnt->ypos = p1.ypos + p2.ypos;
	return *pnt;
}