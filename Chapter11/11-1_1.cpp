#include <iostream>
#include <cstring>
using namespace std;

class Gun {

private:
	int bullet; //장전된 총알의 수
public:
	Gun(int bnum) :bullet(bnum)	{}
	void Shot()	{
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police {
private:
	int handcuffs; //소유한 수갑의 수
	Gun *pistol; //소유하고 있는 권총
public:
	Police(int bnum, int bcuff) :handcuffs(bcuff) {
		if (bnum > 0) //이전 예제와 달리 Gun 클래스를 상속하는 것이 아니라, 생성자에서 Gun 객체를 생성해서 이를 참조하고 있다
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	Police(const Police& copy) : handcuffs(copy.handcuffs) {
		if (copy.pistol != NULL) {
			pistol = new Gun(*(copy.pistol));
		}
		else
			pistol = NULL;
	}
	void PutHandCuff() {
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot() {
		if (pistol == NULL)
			cout << "Hut BBANG!" << endl;
		else
			pistol->Shot();
	}
	Police& operator=(const Police& ref) {
		if (pistol != NULL)
			delete pistol;

		if (ref.pistol != NULL)
			pistol = new Gun(*(ref.pistol));
		else
			pistol = NULL;

		handcuffs = ref.handcuffs;
		return *this;
	}
	~Police() {
		if (pistol != NULL)
			delete pistol;
	}
};



int main(void) {
	Police pman1(5, 3);
	Police pman2 = pman1;
	Police pman3(6, 4);
	pman3 = pman2;
	pman1.Shot();
	pman2.Shot();
	pman3.Shot();

	return 0;
}