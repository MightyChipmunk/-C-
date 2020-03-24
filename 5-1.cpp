#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

namespace COMP_POS {
	enum { CLERK = 1, SENIOR, ASSIST, MANAGER };

	void ShowGradeInfo(int Grade) {
		if (Grade == 1) {
			cout << "직급: 사원" << endl << endl;
		}
		else if (Grade == 2) {
			cout << "직급: 주임" << endl << endl;
		}
		else if (Grade == 3) {
			cout << "직급: 대리" << endl << endl;
		}
		else if (Grade == 4) {
			cout << "직급: 과장" << endl << endl;
		}
		else;
	}
}

class NameCard {
	char* Name;
	char* Comp;
	char* Call;
	int Grade;
public:
	NameCard(char* name, char* comp, char* call, int grade) : Grade(grade) {
		Name = new char[MAX];
		Comp = new char[MAX];
		Call = new char[MAX];
		strcpy_s(Name, MAX, name);
		strcpy_s(Comp, MAX, comp);
		strcpy_s(Call, MAX, call);
	}
	NameCard(const NameCard &copy) : Grade(copy.Grade) {
		Name = new char[strlen(copy.Name) + 1];
		Comp = new char[strlen(copy.Comp) + 1];
		Call = new char[strlen(copy.Call) + 1];
		strcpy_s(Name, strlen(copy.Name) + 1, copy.Name);
		strcpy_s(Comp, strlen(copy.Comp) + 1, copy.Comp);
		strcpy_s(Call, strlen(copy.Call) + 1, copy.Call);
	}
	void ShowNameCardInfo() const {
		cout << "이름: " << Name << endl;
		cout << "회사: " << Comp << endl;
		cout << "전화번호: " << Call << endl;
		COMP_POS::ShowGradeInfo(Grade);
	}
	~NameCard() {
		delete[] Name;
		delete[] Comp;
		delete[] Call;
	}
};

int main(void) {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSenior;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	
	return 0;
}