#include <iostream>
using namespace std;

void refadd(int &x) {
	x++;
}

void refrev(int &x) {
	x *= -1;
}

void SwapPointer(int *(&ptr1), int *(&ptr2)) {
	int* ptr = ptr1;
	ptr1 = ptr2;
	ptr2 = ptr;
}

void swap (int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main () {
	int num = 5;
	refadd(num);
	cout << num << endl;
	refrev(num);
	cout << num << endl;
		
	int num1 = 10, num2 = 20;
	int *ptr1 = &num1;
	int *ptr2 = &num2;
	SwapPointer(ptr1, ptr2);
	cout << *ptr1 << ' ' << *ptr2 << endl;
	
	return 0;
}

