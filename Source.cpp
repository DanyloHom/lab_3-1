#include<iostream>
#include "Date.h"
using namespace std;

int main()
{
	int f;
	int s;
	int t;
	int d;

	cout << "enter day " << endl;
	cin >> f;
	cout << "enter mounth " << endl;
	cin >> s;
	cout << "enter year" << endl;
	cin >> t;

	Date a(f, s, t);
	cout << a << endl;

	cout << "b = a" << endl;
	Date b = a;
	cout << b << endl;

	cout << "enter amount of days + b " << endl;
	cin >> d;

	b.ChangeDays(d);
	cout << b << endl;

	cout << "b++" << endl;
	b++;
	cout << b << endl;

	cout << "b--" << endl;
	b--;
	cout << b << endl;

	cout << "++b" << endl;
	++b;
	cout << b << endl;

	cout << "--b" << endl;
	--b;
	cout << b << endl;


}