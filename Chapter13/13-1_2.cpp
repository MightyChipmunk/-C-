#include <iostream>
#include <cstdlib>
using namespace std;

template <class T> 
T SumArray(T arr[], T len) {
	T sum = 0;
	for (int i = 0; i < len; i++)
		sum += arr[i];
	return sum;
}
int main(void) {
	int arr1[5] = { 1, 2, 3, 4, 5 };
	double arr2[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 }; 
	cout << SumArray<int>(arr1, 5) << endl;
	cout << SumArray<double>(arr2, 5) << endl;
	
	return 0;
}