#include <iostream>
#include <iomanip>
#include "vector.h"

using namespace std;
int main() {
	Vector<int> test;
	Vector<string> stest;
	int m, n;
	cin >> m >> n;
	test = Vector<int>(m, n);
	stest = Vector<string>(m, n);
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			cin >> test[i][j];
		}
	}
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			cin >> stest[i][j];
		}
	}
	test[0][0] = -1;
	stest[0][0] = "Hello, world!";
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			cout << setw(4) << test[i][j];
		}
		cout << endl;
	}
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			cout << setw(20) << right << stest[i][j];
		}
		cout << endl;
	}

	return 0;
}