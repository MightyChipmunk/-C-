#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{

	}
	void ShowPosition() const
	{
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
	friend istream& operator>>(istream& is, Point& pos);
	friend ostream& operator<<(ostream& os, const Point& pos);
};

istream& operator>>(istream& is, Point& pos) {
	is >> pos.xpos >> pos.ypos;
	return is;
}

ostream& operator<<(ostream& os, const Point& pos) {
	os << '[' << pos.xpos << "," << pos.ypos << ']' << endl;
	return os;
}

int main()
{
	Point pos1;
	cin >> pos1;
	cout << pos1;
	return 0;
}