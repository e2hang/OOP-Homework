#pragma once
#include <iostream>
#include "woman.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

class woman;

class man {
private:
	string name;
	bool married;
	woman* w;
public:
	man();
	man(string n, bool m, woman* x);
	void marry(woman* x);
	void devorce(woman* x);
	string display();
	woman* show();
};