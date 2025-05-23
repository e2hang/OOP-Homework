#include <iostream>
#include <cmath>
#include <iomanip>
#define M_PI 3.14159265358979323846
using namespace std;
//连分数类
class Fraction {
private:
	int* p;
public:
	Fraction():p(nullptr){}
	//这里只能传大小为30的数组
	Fraction(int* x) {
		if (p) delete[] p;
		p = new int[30];
		for (int i = 0; i < 30 ;i++) {
			p[i] = x[i];
		}
	}
	Fraction(const Fraction& x) {
		if(p) delete[] p;
		p = new int[30];
		for (int i = 0; i < 30;i++) {
			p[i] = x.p[i];
		}
	}
	Fraction& operator=(const Fraction& x) {
		if(p) delete[] p;
		p = new int[30];
		for (int i = 0; i < 30;i++) {
			p[i] = x.p[i];
		}
	}
	friend ostream& operator<<(ostream& os, const Fraction& x) {
		for (int i = 0;i < 30;i++) {
			os << x.p[i] << " ";
		}
		return os;
	}
	~Fraction() {
		delete[] p;
	}
	void DuiYingFenshu(int x) {
		long long fenzi = 1, fenmu = 0;
		for (int i = x - 1; i >= 0; --i) {
			long long temp = fenzi;
			fenzi = p[i] * fenzi + fenmu;
			fenmu = temp;
		}
		double val = (double)fenzi / fenmu;
		double cha = M_PI - val;
		cout << setprecision(16);
		cout << "第" << x << "项对应的分数是：" << fenzi << "/" << fenmu << endl;
		cout << "第" << x << "项对应的小数是：" << val << endl;
		cout << "与 PI 相差：" << cha << endl;
	}
};
//把一个小数转化成连分式
int* out(double x) {
	double t = x;
	double temp;
	int* tmp;
	tmp = new int[30];
	tmp[0] = floor(t);
	t -= tmp[0];
	for (int i = 1;i < 30;i++) {
		temp = 1 / (t);
		tmp[i] = floor(temp);
		temp -= tmp[i];
		t = temp;
	}
	return tmp;
}

int main() {
	//测试out函数
	int* a;
	a = out(M_PI);
	for (int i = 0;i < 30;i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	//测试类
	Fraction test(a);
	for (int i = 1;i < 30;i++) {
		test.DuiYingFenshu(i);
		cout << endl;
	}
	return 0;
}