#include <iostream>
#include "page.h"

using std::cin;
using std::cout;
using std::endl;

void out(int n) {
	switch (n)
	{
	case 1:
		cout << "上页   1+    2    3    4    5   …   13 下页" << endl;
		break;
	case 2:
		cout << "上页   1    2+    3    4    5   …   13 下页" << endl;
		break;
	case 3:
		cout << "上页   1    2    3+    4    5   …   13 下页" << endl;
		break;
	case 4:
		cout << "上页   1    2    3    4+    5   …   13 下页" << endl;
		break;
	case 5:
		cout << "上页   1    2    3    4    5+   …   13 下页" << endl;
		break;
	case 6:
		cout << "上页    1   …   6+    7    8    9   10   …   13 下页" << endl;
		break;
	case 7:
		cout << "上页    1   …   6    7+    8    9   10   …   13 下页" << endl;
		break;
	case 8:
		cout << "上页    1   …   6    7    8+    9   10   …   13 下页" << endl;
		break;
	case 9:
		cout << "上页    1   …   6    7    8    9+   10   …   13 下页" << endl;
		break;
	case 10:
		cout << "上页    1   …    6    7    8   9   10+   …   13 下页" << endl;
		break;
	case 11:
		cout << "上页    1   …    9   10  11+   12   13 下页" << endl;
		break;
	case 12:
		cout << "上页    1   …    9   10  11   12+   13 下页" << endl;
		break;
	case 13:
		cout << "上页    1   …    9   10  11   12   13+ 下页" << endl;
		break;
	default:
		cout << "Fail!" << endl;
	break;
	}
}



Paginate::Paginate() {
	page_now = 0;
	page_total = 0;
}
Paginate::Paginate(int n) {
	page_total = n;
}
Paginate& Paginate::setPage(int n) {
	page_now = n;
	return *this;
}
Paginate& Paginate::next() {
	page_now += 1;
	return *this;
}
Paginate& Paginate::prev() {
	page_now -= 1;
	return *this;
}
Paginate& Paginate::nextN() {
	page_now += 5;
	return *this;
}
Paginate& Paginate::prevN() {
	page_now -= 5;
	return *this;
}
void Paginate::show() {
	out(this->page_now);
}
