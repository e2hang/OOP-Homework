#include <iostream>
#include <cstring>
#include "man.h"
#include "woman.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;


int main() {
	man m1("Zhang", false , NULL), m2("Wang", false , NULL), m3("Li", true , NULL), m4("Zhao", true , NULL);
	woman w1("Wan", false, NULL), w2("Wu", false, NULL), w3("Xu", true, NULL), w4("Zhou", true, NULL);
	m1.marry(&w1);
	m2.marry(&w2);
	m3.marry(&w3);
	m4.marry(&w4);
	cout << "Set" << endl;
	m1.show() == NULL ? cout << "Devorced" << endl : cout << m1.show()->display() << endl;
	m2.show() == NULL ? cout << "Devorced" << endl : cout << m2.show()->display() << endl;
	m3.show() == NULL ? cout << "Devorced" << endl : cout << m3.show()->display() << endl;
	m4.show() == NULL ? cout << "Devorced" << endl : cout << m4.show()->display() << endl;
	cout << "Arrange" << endl;
	m2.devorce(&w2);
	m4.devorce(&w4);
	m1.show() == NULL ? cout << "Devorced" << endl : cout << m1.show()->display() << endl;
	m2.show() == NULL ? cout << "Devorced" << endl : cout << m2.show()->display() << endl;
	m3.show() == NULL ? cout << "Devorced" << endl : cout << m3.show()->display() << endl;
	m4.show() == NULL ? cout << "Devorced" << endl : cout << m4.show()->display() << endl;
	
	return 0;
}