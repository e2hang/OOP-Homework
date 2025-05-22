#pragma once
#include <iostream>
#include "walker.h"
#include "police.h"

class walker;

using std::string;
using std::cout;
using std::cin;

class thief {
private:
	string name;
	double money;
	bool caught;
public:
	thief();
	thief(string n, double m, bool c);
	thief& steal(walker& x);
	void display();
	thief& becaught();

};