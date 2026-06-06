#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class Money {
private:
	long rubles;
	int kopecks;
public:
	Money();
	Money(long rubles, int kopecks);
	Money(const Money& other);
	~Money();

	long GetRubles() const;
	int GetKopecks() const;

	void SetRubles(long rubles);
	void SetKopecks(long kopecks);

	Money& operator = (const Money& other);
	bool operator == (const Money& other);

	friend std::ostream& operator << (std::ostream& os, const Money& money);
	friend std::istream& operator >> (std::istream& is, Money& money);

	friend fstream& operator >> (fstream& fin, Money& money);
	friend fstream& operator << (fstream& fout, const Money& money);

	double operator/(const Money& other) const;
	Money operator *(const double number) const;
};
std::ostream& operator << (std::ostream& os, const Money& money);
std::istream& operator >> (std::istream& is, Money& money);
