#include <iostream>
using namespace std;

class A {
public:
	A() {
		data = -1;
	}
	A(int n) :data(n) {

	}
	int& Data(){
		return data;
	}
private:
	int data;
};

auto g = [](int n) {
	A* p = new A[n];
	for (int i = 0;i < n;i++) {
		p[i].Data() = i + 1;
	}
	for (int i = n-1;i >= 0;i--) {
		cout << p[i].Data() << " ";
	}
	cout << endl;
	delete[] p;
};

int main() {
	int a;
	cin >> a;
	g(a);
	return 0;
}
