#include <iostream>
#include "sort.h"

using namespace std;
int main() {
	int d, e;
	cin >> d >> e;
	sort_two(d, e);
	int a, b, c;
	cin >> a >> b >> c;
	sort_three(a, b, c);
	cout << "������������������" << endl;
	cout << d << e <<endl;
	cout << a << b << c;
	return 0;
}