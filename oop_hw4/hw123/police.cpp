#include <iostream>
#include "walker.h"
#include "police.h"
#include "thief.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;

police::police(){
	name = "";
	money = -1;
	respect = -1;
}
police::police(string n, double m, int r) {
	name =  n ;
	money = m ;
	respect = r ;
}
police& police::caught(thief& x) {
	money += 100;
	respect++;
	x.becaught();
	return *this;
}
void police::display() {
	cout << name << " " << money << " " << "Respect :" << respect << endl;
}