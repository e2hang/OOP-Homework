#include <iostream>
#include "thief.h"
#include "walker.h"
#include "police.h"


using std::string;
using std::cout;
using std::cin;
using std::endl;

walker::walker() {
		name = "";
		money = -1;
		stolen = false;
	}
walker::walker(string n, double m, bool c = false) {
		name = n;
		money = m;
		stolen = c;
	}
	double walker::money_print() {
		return money;
	}
walker& walker::zero() {
		money = 0;
		stolen = true;
		return *this;
	}
void walker::display() {
	cout << name << " " << money << " " << "If stolen :" << stolen << endl;
}