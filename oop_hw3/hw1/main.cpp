#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
class MyString {
private:
	char* mpData;
public:
	MyString(const char* pData = nullptr) {
			if (pData == nullptr) {
				mpData = new char[1];
				mpData[0] = '\0';
			}
			else {
				int len = strlen(pData);
				mpData = new char[len + 1];
				strcpy(mpData, pData);
		}

	}
	MyString(const MyString& x) {
		int len = strlen(x.mpData);
		mpData = new char[len + 1];
		strcpy(mpData, x.mpData);
	}
	~MyString() {
		delete[] mpData;
	}
	MyString& operator=(const MyString& x) {
		if (this == &x) return *this;  
		delete[] mpData;               
		int len = strlen(x.mpData);
		mpData = new char[len + 1];   
		strcpy(mpData, x.mpData);     
		return *this;                 
	}
	MyString& operator+=(const MyString& x) {
		int len = strlen(mpData) + strlen(x.mpData);
		char* tmp = new char[len + 1];
		strcpy(tmp, mpData);         
		strcat(tmp, x.mpData);       
		delete[] mpData;             
		mpData = tmp;                
		return *this;
	}
	friend const MyString operator+(const MyString& x, const MyString& y) {
		int len = strlen(x.mpData) + strlen(y.mpData);
		char* tmp = new char[len + 1];
		strcpy(tmp, x.mpData);
		strcat(tmp, y.mpData);
		MyString r(tmp);
		delete[] tmp;
 		return r;
	}
	friend ostream& operator<<(ostream& os, const MyString& x) {
		os << x.mpData;
		return os;
	}
};

int main() {
	char p[] = "Hello, world!";
	char q[] = "What are you doing?";
	char r[] = "How are you!";
	MyString a(p), b, c;
	b = MyString(q);
	c = b;
	MyString d;
	d = a + b;
	cout << d << endl;
	

	return 0;
}