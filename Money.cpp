#include "Money.h"
#include <limits>

Money::Money() { // конструктор без параметров
	rubles = 100;
	kopecks = 0;
}

Money::Money(long rubles, int kopecks) { // конструктор с параметрами
	SetRubles(rubles);
	SetKopecks(kopecks);
}

Money::Money(const Money& other) { // конструктор копировани€
	this->rubles = other.rubles;
	this->kopecks = other.kopecks;
}

Money::~Money() {
	//std::cout << "ƒеструктор вызван" << "\n"; //деструктор
}

long Money::GetRubles() const { // гетер дл€ рублей
	return rubles;
}

int Money::GetKopecks() const { // гетер дл€ копеек
	return kopecks;
}

void Money::SetRubles(long rubles) { //сетер дл€ рублей
	if (rubles >= 0) {
		this->rubles = rubles;
	}
	else {
		std::cout << " ол-во рублей не может быть меньше 0\n";
	}
}

void Money::SetKopecks(long kopecks) { // сетер дл€ копеек
	if (kopecks < 0)
		std::cout << " ол-во копеек не может быть меньше 0\n";
	else if (kopecks >= 0 && kopecks < 100)
		this->kopecks = kopecks;
	else {
		this->rubles += kopecks / 100;
		this->kopecks = kopecks % 100;
	}
}
Money& Money::operator = (const Money& other) {
	if (this == &other)
		return *this;
	rubles = other.rubles;
	kopecks = other.kopecks;
	return *this;
}

std::ostream& operator << (std::ostream& os, const Money& money) { //перегрузка вывода
	os << money.rubles << "," << money.kopecks << "\n";
	return os;
}

std::istream& operator >> (std::istream& in, Money& money) { //перегрузка ввода
	long r;
	int k;
	in >> r >> k;  // Ѕез циклов и проверок!
	money.SetRubles(r);
	money.SetKopecks(k);
	return in;
}

std::fstream& operator >> (fstream& fin, Money& money) {
	char comma;
	fin >> money.rubles >>comma >>  money.kopecks;
	return fin;
}

std::fstream& operator << (fstream& fout, const Money& money) {
	fout << money.rubles << "," << money.kopecks << "\n";
	return fout;
}

bool Money::operator == (const Money& other) {
	return (this->rubles == other.rubles && this->kopecks == other.kopecks);
}

double Money::operator / (const Money& other) const {

	long thisKopecks = this->kopecks + this->rubles * 100;
	long otherKopecks = other.kopecks + other.rubles * 100;

	if (otherKopecks != 0) {
		return static_cast<double> (thisKopecks) / otherKopecks;
	}
	std::cout << "ќшибка делени€ на ноль!\n";
	return 0.0;
}


Money Money::operator*(const double number) const {
	long thisKopecks = this->kopecks + this->rubles * 100;

	long answer = static_cast<long>(std::round(thisKopecks * number));

	Money result;
	result.SetRubles(0);
	result.SetKopecks(answer);
	return result;
}