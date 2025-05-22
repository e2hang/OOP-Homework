#include <iostream>
#include "check_num.h"

using namespace std;
int main()
{
	char ch;
	for (int i = 0;i < 10;i++) {
		cin >> ch;
		cout << is_digit(ch)<<endl;
	}
	return 0;
}