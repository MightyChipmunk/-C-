#include <iostream>
using namespace std;

class FruitSeller {
private:
	int APPLE_PRICE;
	int numOfApples;
	int mymoney;
	
public:
	void InitMembers(int price, int num, int money) {
		APPLE_PRICE = price;
		numOfApples = num;
		mymoney = money;
	}
	int SaleApples(int money) {
		if(money < 0) {
			cout<<"0이상의 돈을 받아야 합니다."<<endl;
			return 0;
		}
		int num= money/APPLE_PRICE;
		numOfApples -= num;
		mymoney += money;
		return num;
	}
	void ShowSalesResult() const {
		cout<<"남은 사과: "<<numOfApples<<endl;
		cout<<"판매 수익: "<<mymoney<<endl<<endl;
	}
};

class FruitBuyer {
private:
	int mymoney;
	int numOfApples;
	
public:
	void InitMembers(int money) {
		mymoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller &seller, int money) {
		if (money < 0) {
			cout << "0이상의 돈을 전달해야 합니다." <<endl;
			return;
		}
		else {
			numOfApples+=seller.SaleApples(money);
			mymoney -= money;
		}
	}
	void ShowBuyResult() const {
		cout<<"현재 잔액: "<<mymoney<<endl;
		cout<<"사과 개수: "<<numOfApples<<endl<<endl;
	}
};

int main (void) {
	FruitSeller seller;
	seller.InitMembers(1000,20,0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);
	
	cout<<"과일 판매자의 현황"<<endl;
	seller.ShowSalesResult();
	cout<<"과일 구매자의 현황"<<endl;
	buyer.ShowBuyResult();
	return 0;
}