#include <iostream>
using namespace std;

class MyFriendInfo {
private:
	char* name;
	int age;
public:
	MyFriendInfo(char* name, int myage) : age(myage) {
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}
	void ShowMyFriendinfo() {
		cout << "ÀÌ¸§: " << name << endl;
		cout << "³ªÀÌ: " << age << endl;
	}
	~MyFriendInfo() {
		delete []name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo{
private:
	char *addr;
	char *phone;
public:
	MyFriendDetailInfo(char* name, char* addr, char *phone, int age) : MyFriendInfo(name, age) {
		this->addr = new char[strlen(addr) + 1];
		strcpy_s(this->addr, strlen(addr) + 1, addr);
		this->phone = new char[strlen(phone) + 1];
		strcpy_s(this->phone, strlen(phone) + 1, phone);
	}
	void ShowMyFriendDetailInfo() {
		ShowMyFriendinfo();
		cout << "ÁÖ¼Ò: " << addr << endl;
		cout << "ÀüÈ­: " << phone << endl << endl;
	}
	~MyFriendDetailInfo() {
		delete []addr;
		delete []phone;
	}
};

int main(void) {
	MyFriendDetailInfo info("asdf", "1234", "010", 20);
	info.ShowMyFriendDetailInfo();

	return 0;
}
