#include <iostream>
#include "person.h"

using std::cout;
using std::endl;
using std::string;

int main() {
	Employee a[5];
	Executive b[5];
	a[0] = Employee(20, "Zhang", 1, 1001);
	a[1] = Employee(21, "Wang", 1, 1002);
	a[2] = Employee(19, "Zhao", 0, 1003);
	a[3] = Employee(22, "Li", 1, 1004);
	a[4] = Employee(28, "Zh", 0, 1145);
	a[0].display();
	a[1].display();
	a[2].display();
	a[3].display();
	a[4].display();
	return 0;
}