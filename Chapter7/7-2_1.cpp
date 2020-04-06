#include <iostream>
#include <cstring>
using namespace std;

class Rectangle {
private:
	int x, y;
public:
	Rectangle(int _x, int _y) : x(_x), y(_y) {};
	void ShowAreaInfo() {
		cout<<"면적: "<<x*y<<endl;
	}
};

class Square : public Rectangle {
public:
	Square(int _x) : Rectangle(_x, _x) {};
};

int main(void) {
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();
	
	Square sqr(7);
	sqr.ShowAreaInfo();

	return 0;
}
