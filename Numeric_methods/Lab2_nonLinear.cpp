#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>

using namespace std;

const double PI = M_PI;

/*
double f(double x)
{
	return 1 / tan(x + 0.5) - x * x;
}


double root()
{
	double epsilon = 0.000005;

	double x0 = 0;
	double x1 = PI/2;
	double xn = 0;
	double count = 0;
	while (abs(f(xn)) > epsilon)
	{
		xn = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
		x0 = x1;
		x1 = xn;
		++count;
	}
	cout << count << endl;
	return xn;
}


double funk(double x)
{
	return 1 / (tan(x + 0.5)) - x * x;
}


double phi(double x)
{
	return sqrt(1 / tan(x + 0.5));
}

double MSI()
{
	int count = 0;
	double epsilon = 0.000005;
	double x0 = 3 * PI / 16;
	double xn = phi(x0);
	while (abs(funk(xn)) > epsilon)
	{
		x0 = xn;
		xn = phi(x0);
		++count;
	}
	cout << count << endl;
	return xn;
}



int main()
{
	cout << root() << endl;
	cout << MSI();
}*/