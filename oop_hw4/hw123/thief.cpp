#include <iostream>
#include "thief.h"
#include "walker.h"
#include "police.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;

thief::thief() {
		name = "";
		money = -1;
		caught = false;
	}
thief::thief(string n, double m, bool c = false) {
		name = n;
		money = m;
		caught = c;
	}
thief& thief::steal(walker& x) {
		money += x.money_print();
		x.zero();
		caught = true;
		return *this;
}
thief& thief::becaught() {
	money = 0;
	caught = false;
	return *this;
}
void thief::display() {
	cout << name << " " << money << " " << "If caught :" << caught << endl;
}
