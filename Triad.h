#pragma once
#include <string>
using namespace std;

class Triad
{
private:
	int first;
	int second;
	int third;
public:
	Triad();
	Triad(int f, int s, int t);
	Triad(const Triad& t);


	int getFirst()const { return first; }
	int getSecond()const { return second; }
	int getThird()const { return third; }
	void setFirst(int value);
	void setSecond(int value);
	void setThird(int value);
	void Init(int f, int s, int t);
	void Read();
	void Display()const;
	void PlusFirst();
	void PlusSecond();
	void PlusThird();

	operator string() const;
	Triad& operator =(Triad& v);
	friend ostream& operator << (ostream& out, Triad& t);
	friend istream& operator >> (istream& in, Triad& t);

	Triad& operator ++();
	Triad& operator --();
	Triad operator ++(int);
	Triad operator --(int);

};

