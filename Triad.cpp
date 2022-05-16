#include "Triad.h"
#include <iostream>
#include <sstream>

using namespace std;

Triad::Triad()
{
	first = second = third = 0;
}

Triad::Triad(int f, int s, int t)
{
	first = f;
	second = s;
	third = t;
}

Triad::Triad(const Triad& t)
{
	first = t.first;
	second = t.second;
	third = t.third;
}

void Triad::setFirst(int value)
{
	first = value;
}

void Triad::setSecond(int value)
{
	second = value;

}

void Triad::setThird(int value)
{
	third = value;
}

void Triad::Init(int f, int s, int t)
{
	setFirst(f);
	setSecond(s);
	setThird(t);
}

void Triad::Read()
{
	int f, s, t;
	cout << "enter first " << endl;
	cin >> f;
	cout << "enter second " << endl;
	cin >> s;
	cout << "enter third " << endl;
	cin >> t;
	Init(f, s, t);
}

void Triad::Display() const
{
	cout << "first = " << first << endl;
	cout << "second = " << second << endl;
	cout << "third = " << third << endl;
}

void Triad::PlusFirst()
{
	first++;
}

void Triad::PlusSecond()
{
	second++;
}

void Triad::PlusThird()
{
	third++;
}


Triad::operator string() const
{
	stringstream ss;

	ss << "first = " << first << "second = " << second << "third = " << third;

	return ss.str();

}

Triad& Triad::operator=(Triad& t)
{
	first = t.first;
	second = t.second;
	third = t.third;

	return *this;
}

Triad& Triad::operator++()
{
	++first;
	++second;
	++third;

	return *this;
}

Triad& Triad::operator--()
{
	--first;
	--second;
	--third;

	return *this;
}

Triad Triad::operator++(int)
{
	Triad tmp(*this);
	first++;
	second++;
	third++;

	return tmp;
}

Triad Triad::operator--(int)
{
	Triad tmp(*this);
	first--;
	second--;
	third--;

	return tmp;
}

ostream& operator<<(ostream& out, Triad& t)
{
	out << string(t);
	return out;
}

istream& operator>>(istream& in, Triad& t)
{
	cout << "enter first " << endl;
	in >> t.first;
	cout << "enter second " << endl;
	in >> t.second;
	cout << "enter third " << endl;
	in >> t.third;

	return in;
}
