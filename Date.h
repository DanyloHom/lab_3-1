#pragma once
#include "Triad.h"

//using namespace std;

class Date:
	public Triad
{
public:
	Date();
	Date(int f, int s, int t);
	Date(const Date& d);

	bool Init(int d, int m, int y);
	void Read();
	void Display();

	void PlusFirst();
	void PlusSecond();
	void PlusThird();

	void ChangeDays(int value);
	void Check();
	void MounthChanger(int value);
	void YearCheck();
	std::string toString()const;

	operator string() const;
	friend ostream& operator << (ostream& out, Date& t);
	friend istream& operator >> (istream& in, Date& t);
};

