#include <iostream>
using namespace std;

class Point {
	int xpos, ypos;
public:
	void Init(int x, int y) {
		xpos = x;
		ypos = y;
	}	
	void ShowPointInfo() const {
		cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
	}
};

class Circle {
	Point point;
	int radius;
public:
	void Init(int x, int y, int rad) {
		point.Init(x, y);
		radius = rad;
	}
	void ShowCircleInfo() const {
		cout<<"radius: "<<radius<<endl;
		point.ShowPointInfo();
	}
};

class Ring {
	Circle Innercircle;
	Circle Outtercircle;
public:
	void Init(int ix, int iy, int ira, int ox, int oy, int ora) {
		Innercircle.Init(ix, iy, ira);
		Outtercircle.Init(ox, oy, ora);
	}
	void ShowRinginfo() const {
		cout<<"Inner Circle info..."<<endl;
		Innercircle.ShowCircleInfo();
		cout<<"Outter Circle info..."<<endl;
		Outtercircle.ShowCircleInfo();
	}
};

int main (void) {
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRinginfo();
	
	return 0;
}