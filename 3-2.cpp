#include <iostream>
#include "3-2.h"
using namespace std;

void Calculator::Init() {
	Addnum = 0;
	Minnum = 0;
	Divnum = 0;
	Mulnum = 0;
}

void Calculator::ShowOpCount() {
	cout << "µ¡¼À: " << Addnum << " »¬¼À: " << Minnum << " °ö¼À: " << Mulnum << " ³ª´°¼À: " << Divnum << endl;
}

double Calculator:: Add(double a, double b) {
	Addnum++;
	return a + b;
}
double Calculator::Div(double a, double b) {
	Divnum++;
	return a / b;
}
double Calculator::Min(double a, double b) {
	Minnum++;
	return a - b;
}
double Calculator::Mul(double a, double b) {
	Mulnum++;
	return a * b;
}