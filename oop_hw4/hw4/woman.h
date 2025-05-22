#pragma once
#include <iostream>
#include "man.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

class man;

class woman {
private:
	string name;
	bool married;
	man* w;
public:
	woman();
	woman(string n, bool m, man* x);
	void marry(man* x);
	void devorce(man* x);
	string display();
	man* show();
};