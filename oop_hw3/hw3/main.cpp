#include <iostream>
using namespace std;

template <class T>
void f(int m, int n) {
	T** p;
	p = new T* [m];
	for (int i = 0;i < m;i++) {
		p[i] = new T[n];
	}
	int cnt = 1;
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			p[i][j] = cnt;
			cout << cnt << " ";
			cnt++;
		}
		cout << endl;
	}
	if (p) {
		for (int i = 0;i < m;i++) {
			delete[] p[i];
		}
		delete[] p;
	}
}

int main() {
	int a, b;
	cin >> a >> b;
	f<int>(a, b);
	return 0;
}