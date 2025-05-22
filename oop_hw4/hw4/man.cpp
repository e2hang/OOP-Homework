#include <iostream>
#include "woman.h"
#include "man.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

	man::man() {
		name = "";
		married = false;
		w = NULL;
	}
	man::man(string n, bool m, woman* x) {
		name = n;
		married = m;
		w = x;
	}
	void man::marry(woman* x) {
		w = x;
		married = true;
	}
	void man::devorce(woman* x) {
		w = NULL;
		married = false;
	}
	string man::display() {
		return name;
	}
	woman* man::show() {
		return w;
	}
