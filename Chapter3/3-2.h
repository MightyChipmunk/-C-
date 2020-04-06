#pragma once

class Calculator {
private :
	int Addnum;
	int Divnum;
	int Minnum;
	int Mulnum;
public :
	void Init();
	void ShowOpCount();
	double Add(double a, double b);
	double Div(double a, double b);
	double Min(double a, double b);
	double Mul(double a, double b);
};
