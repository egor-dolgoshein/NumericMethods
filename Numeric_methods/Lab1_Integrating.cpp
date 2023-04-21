#include<iostream>
#include<cmath>


using namespace std;

double f(double x)
{
	return cos(x) / log(x + 1);
}


double integrate_lrect(double h, double a = 1.4, double b = 3.7)
{
	int n = (int)((b - a) / h);
	double I = 0;
	for (int i = 0; i < n; ++i)
		I += f(a + i * h);
	return h * I;
}


double integrate_Gregory(double h, double a = 1.4, double b = 3.7)
{
	int n = (int)((b - a) / h);
	double sum = 0;
	double f0 = f(a);
	double f1 = f(a + h);
	double f2 = f(a + 2 * h);
	double fn = f(b);
	double fpn = f(b - h);
	double fppn = f(b - 2 * h);

	for (int i = 1; i < n; ++i)
		sum += f(a + i * h);
	return h * ((f0 + fn) / 2 + sum) + h / 24. * (-3 * f0 + 4 * f1 - f2 - 3 * fn + 4 * fpn - fppn);
}


double Gauss_integratig_three_dot()
{
	return 23. / 20. *( 8. / 9 * f(51. / 20) + 5. / 9 * f((-sqrt(0.6) * 23 + 51) / 20) + 5. / 9 * f((sqrt(0.6) * 23 + 51) / 20));
}


double accuracy(int p, double I_h, double I_halfh)
{
	int power = pow(2, p);
	return power * (I_halfh - I_h) / (power - 1);
}




int main()
{
	double h[3] = {0.1, 0.05, 0.025};
	cout << "Counting with left rectangle formula:\n\n";
	for (int i = 0; i < 3; ++i)
	{
		double I = integrate_lrect(h[i]);
		double I_hh = integrate_lrect(h[i] / 2.);
		cout << "With " << h[i] << " step integral equals " << I << endl;
		cout << "With " << accuracy(1, I, I_hh) << " accuracy" << endl;
	}
	cout << "\nCounting with Gregory formula:\n\n";
	for (int i = 0; i < 3; ++i)
	{
		double I = integrate_Gregory(h[i]);
		double I_hh = integrate_Gregory(h[i] / 2.);
		cout << "With " << h[i] << " step integral equals ";
		cout.precision(10);
		cout << I << endl;
		cout << "With " << accuracy(4, I, I_hh) << " accuracy" << endl;
	}


	cout << "\nCounting with the highest accuracy Gauss formula:\n" << Gauss_integratig_three_dot();


}