#include <iostream>
#include <cstring>
using namespace std;

class Gun {

private:
	int bullet; //������ �Ѿ��� ��
public:
	Gun(int bnum) :bullet(bnum)	{}
	void Shot()	{
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police {
private:
	int handcuffs; //������ ������ ��
	Gun *pistol; //�����ϰ� �ִ� ����
public:
	Police(int bnum, int bcuff) :handcuffs(bcuff) {
		if (bnum > 0) //���� ������ �޸� Gun Ŭ������ ����ϴ� ���� �ƴ϶�, �����ڿ��� Gun ��ü�� �����ؼ� �̸� �����ϰ� �ִ�
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