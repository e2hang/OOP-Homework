#include <iostream>
#include "thief.h"
#include "walker.h"
#include "police.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
	thief t1("Dan", 100, false), t2("Trevor", 50.4, false), t3("Mike", 30.2, false);
	walker w1("Man", 1000, false), w2("Wan", 5000, false);
	t1.steal(w1);
	t2.steal(w2);
	t1.display();
	t2.display();
	w1.display();
	w2.display();
	police p1("Officer", 0, 0), p2("Reciffo", 1, 1), p3("fw", 0, 0);
	p1.caught(t1);
	p2.caught(t2);
	cout << "After Caught" << endl;
	p1.display();
	p2.display();
	t1.display();
	t2.display();
	return 0;
}