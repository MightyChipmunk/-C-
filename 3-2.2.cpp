#include <iostream>
#include <string>
using namespace std;

class Printer {
private:
	string String;
public:
	void SetString(string str);
	void ShowString();
};

void Printer::SetString(string str) {
	String = str;
}

void Printer::ShowString() {
	cout << String << endl;
}

int main(void) {
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();

	return 0;
}
