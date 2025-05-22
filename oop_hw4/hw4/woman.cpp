#include <iostream>
#include "man.h"
#include "woman.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;


	woman::woman() {
		name = "";
		married = false;
		w = NULL;
	}
	woman::woman(string n, bool m, man* x) {
		name = n;
		married = m;
		w = x;
	}
	void woman::marry(man* x) {
		w = x;
		married = true;
	}
	void woman::devorce(man* x) {
		w = NULL;
		married = false;
	}
	string woman::display() {
		return name;
	}
	man* woman::show() {
		return w;
	}
