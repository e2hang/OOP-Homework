#include <iostream>
#include "t_area.h"

using namespace std;

int main() {
	double a, b, c;
	cin >> a >> b >> c;
	cout << triangle_area(a,b,c) << endl;
	return 0;
}
