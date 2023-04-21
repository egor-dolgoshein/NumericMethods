#define _USE_MATH_DEFINES
#include<iostream>

using namespace std;


long double Sum_original(int N)
{
	long double sum = 0;
	for (int i = 1; i < N + 1; ++i)
		sum += 1 / (0.5 * i * i + 2.8 * i + 0.2);
	return sum;
}

long double Sum_first_increased(int N)
{
	long double sum = 0;
	for (int i = 1; i < N + 1; ++i)
		sum -= (0.4 + 5.6 * i) / (i * i * (0.5 * i * i + 2.8 * i + 0.2));
	return sum + M_PI* M_PI / 3;
}

long double Sum_second_increased(int N)
{
	long double sum = 0;
	for (int i = 1; i < N + 1; ++i)
		sum += (154.8 * i + 11.2) / (5 * i * i * i * (0.5 * i * i + 2.8 * i + 0.2));
	return sum - 56 * 1.2020569 / 5 +M_PI * M_PI / 3;
}

long double Sum_third_increased(int N)
{
	long double sum = 0;
	for (int i = 1; i < N + 1; ++i)
		sum -= (855.68 * i + 61.92) / (5 * i * i * i * i * (0.5 * i * i + 2.8 * i + 0.2));
	return sum + 61.92 * M_PI * M_PI * M_PI * M_PI / 90 - 56 * 1.2020569 / 5 + M_PI * M_PI / 3;
}
/*

int main()
{
	cout << "Original sum with 20 members is " << Sum_original(20) << endl;
	cout << "Original sum with 100 members is " << Sum_original(100) << endl;
	cout << "Original sum with 1000 members is " << Sum_original(1000) << endl;
	cout << "First increased sum with 20 members is " << Sum_first_increased(20) << endl;
	cout << "First increased sum with 100 members is " << Sum_first_increased(100) << endl;
	cout << "First increased sum with 1000 members is " << Sum_first_increased(1000) << endl;
	cout << "Second increased sum with 20 members is " << Sum_second_increased(20) << endl;
	cout << "Second increased sum with 100 members is " << Sum_second_increased(100) << endl;
	cout << "Second increased sum with 1000 members is " << Sum_second_increased(1000) << endl;
	cout << "Third increased sum with 20 members is " << Sum_third_increased(20) << endl;
	cout << "Third increased sum with 100 members is " << Sum_third_increased(100) << endl;
	cout << "Third increased sum with 1000 members is " << Sum_third_increased(1000) << endl;
	cout << "Original sum with given accuracy is " << Sum_original(40000) << endl;
	cout << "First increased sum with given accuracy is " << Sum_first_increased(1894) << endl;
	cout << "Second increased sum with given accuracy is " << Sum_second_increased(196) << endl;
	cout << "Third increased sum with given accuracy is " << Sum_third_increased(87) << endl;
	return 1;
}*/