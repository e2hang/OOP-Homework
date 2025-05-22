#pragma once
#include <iostream>
#include "thief.h"
#include "police.h"

using std::string;
using std::cout;
using std::cin;

class walker {
private:
	string name;
	double money;
	bool stolen;
public:
	walker();
	walker(string n, double m, bool c);
	double money_print();
	walker& zero();
	void display();
};