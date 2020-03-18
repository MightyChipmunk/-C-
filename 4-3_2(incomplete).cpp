#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

namespace COMP_POS {
	enum {CLERK = 1, SENIOR, ASSIST, MANAGER};
	
	void ShowGradeInfo(int Grade) {
		if (Grade == 1) {
			cout<<"직급: 사원"<<endl<<endl;
		}
		else if (Grade == 2) {
			cout<<"직급: 주임"<<endl<<endl;
		}
		else if (Grade == 3) {
			cout<<"직급: 대리"<<endl<<endl;
		}
		else if (Grade == 4) {
			cout<<"직급: 과장"<<endl<<endl;
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
		strcpy(Name, name);
		strcpy(Comp, comp);
		strcpy(Call, call);
	}
	void ShowNameCardInfo() {
		cout<<"이름: "<<Name<<endl;
		cout<<"회사: "<<Comp<<endl;
		cout<<"전화번호: "<<Call<<endl;
		COMP_POS::ShowGradeInfo(Grade);
	}
	~NameCard() {
		delete[] Name;
		delete[] Comp;
		delete[] Call;
	}
};

int main (void) {
	//NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	//manClerk.ShowNameCardInfo();
	manSenior.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	
	return 0;
}
