#include "Date.h"
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

Date::Date()
{
	setFirst(0);
	setSecond(0);
	setThird(0);
}

Date::Date(int f, int s, int t)
{
	if (Init(f, s, t))
		cout << "successful initialization" << endl;
	else cerr << "wrong arguments!" << endl;
}

Date::Date(const Date& d)
{
	int f = d.getFirst();
	int s = d.getSecond();
	int t = d.getThird();
	if (Init(f, s, t))
		cout << "successful initialization" << endl;
	else cerr << "wrong arguments!" << endl;

}

bool Date::Init(int d, int m, int y)
{
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
		if (d > 0 && d <= 31) {
			setFirst(d);
			setSecond(m);
			setThird(y);
			return true;
		}
	}

	if (m == 4 || m == 6 || m == 9 || m == 11) {
		if (d > 0 && d <= 30) {
			setFirst(d);
			setSecond(m);
			setThird(y);
			return true;
		}
	}
	if (m == 2) {
		if (y % 4 == 0 || y % 100 == 0 || y % 400 == 0) {
			if (d > 0 && d <= 29)
				setFirst(d);
			setSecond(m);
			setThird(y);
			return true;
		}
		else {
			if (d > 0 && d <= 28)
				setFirst(d);
			setSecond(m);
			setThird(y);
			return true;
		}

	}
	else
		return false;
}

void Date::Read()
{
	int d = 0, m = 0, y = 0;

	do {
		cout << "enter day " << endl;
		cin >> d;
		cout << "enter mounth " << endl;
		cin >> m;
		cout << "enter year " << endl;
		cin >> y;
	} while (!Init(d, m, y));
}

void Date::Display()
{
	cout << endl;

	if (getFirst() < 10 && getSecond() >= 10)
		cout << "date is : " << "0" << getFirst() << "." << getSecond() << "." << getThird() << endl;

	if (getFirst() < 10 && getSecond() < 10)
		cout << "date is : " << "0" << getFirst() << "." << "0" << getSecond() << "." << getThird() << endl;

	if (getFirst() >= 10 && getSecond() >= 10)
		cout << "date is : " << getFirst() << "." << getSecond() << "." << getThird() << endl;

	if (getFirst() >= 10 && getSecond() < 10)
		cout << "date is : " << getFirst() << "." << "0" << getSecond() << "." << getThird() << endl;

	cout << endl;
}

void Date::PlusFirst()
{
	PlusFirst();
	Check();
}

void Date::PlusSecond()
{
	PlusSecond();
	Check();
}

void Date::PlusThird()
{
	PlusThird();
	Check();
}

void Date::ChangeDays(int value)
{
	setFirst(getFirst() + value);
	Check();
}

void Date::Check()
{
	int d = getFirst();
	int m = getSecond();
	int y = getThird();

	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
		int count = 31;
		if (d > count)
			MounthChanger(count);
	}

	if (m == 4 || m == 6 || m == 9 || m == 11) {
		int count = 30;
		if (d > count)
			MounthChanger(count);
	}

	if (m == 2) {
		if (y % 4 == 0 || y % 100 == 0 || y % 400 == 0) {
			int count = 29;
			if (d > count)
				MounthChanger(count);
		}
		else {
			int count = 28;
			if (d > count)
				MounthChanger(count);
		}
	}

}

void Date::MounthChanger(int value)
{
	setFirst(getFirst() - value);
	setSecond(getSecond() + 1);
	YearCheck();
	return Check();
}

void Date::YearCheck()
{
	if (getSecond() > 12) {
		setThird(getThird() + 1);
		setSecond(getSecond() - 12);
	}
}

string Date::toString() const
{
	stringstream sout;

	if (getFirst() < 10 && getSecond() >= 10)
		sout << "0" << getFirst() << "." << getSecond() << "." << getThird() << endl;

	if (getFirst() < 10 && getSecond() < 10)
		sout << "0" << getFirst() << "." << "0" << getSecond() << "." << getThird() << endl;

	if (getFirst() >= 10 && getSecond() >= 10)
		sout << getFirst() << "." << getSecond() << "." << getThird() << endl;

	if (getFirst() >= 10 && getSecond() < 10)
		sout << getFirst() << "." << "0" << getSecond() << "." << getThird() << endl;

	return sout.str();
}

Date::operator string() const
{
	stringstream sout;

	if (getFirst() < 10 && getSecond() >= 10)
		sout << "0" << getFirst() << "." << getSecond() << "." << getThird() << endl;

	if (getFirst() < 10 && getSecond() < 10)
		sout << "0" << getFirst() << "." << "0" << getSecond() << "." << getThird() << endl;

	if (getFirst() >= 10 && getSecond() >= 10)
		sout << getFirst() << "." << getSecond() << "." << getThird() << endl;

	if (getFirst() >= 10 && getSecond() < 10)
		sout << getFirst() << "." << "0" << getSecond() << "." << getThird() << endl;
	return sout.str();
}

ostream& operator<<(ostream& out, Date& t)
{
	out << string(t);
	return out;
}

istream& operator>>(istream& in, Date& t)
{
	int d, m, y;
	cout << "enter day " << endl;
	in >> d;
	cout << "enter mounth " << endl;
	in >> m;
	cout << "enter year " << endl;
	in >> y;

	t.setFirst(d);
	t.setSecond(m);
	t.setThird(y);

	return in;
}
