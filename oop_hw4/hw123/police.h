#pragma once
#include <iostream>
#include "thief.h"
#include "walker.h"

class thief;

using std::string;
using std::cout;
using std::cin;

class police {
private:
	string name;
	double money;
	int respect;
public:
	police();
	police(string n, double m, int r);
	police& caught(thief& x);
	void display();
};