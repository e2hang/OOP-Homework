#include <iostream>
#include <cstring>
#include "animal.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
	Animal a("Animal!", 100);
	Lion b("Lion W", 200);
	Aardvark c("Aardvark", 300);
	a.who();
	b.who();
	c.who();
	return 0;
}