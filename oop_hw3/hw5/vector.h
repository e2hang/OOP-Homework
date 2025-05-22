#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

template<class T>
class Vector {
private:
	T** p;
	int hang;
	int lie;
public:
	Vector();
	Vector(int m, int n);
	Vector& operator=(const Vector& x);
	T* operator[](int x);
	void AlterElement(int m, int n, T x);
	~Vector();
};

template<class T>
Vector<T>::Vector() {
	p = nullptr;
	hang = 0;
	lie = 0;
}

template<class T>
Vector<T>::Vector(int m, int n) {
	hang = m;
	lie = n;
	p = new T * [m];
	for (int i = 0;i < m;i++) {
		p[i] = new T[n];
	}
}

template<class T>
Vector<T>::~Vector() {
	if (p) {
		for (int i = 0; i < hang; i++) {
			delete[] p[i];
		}
		delete[] p;
	}
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector& x) {
	if (p) {
		for (int i = 0; i < hang; i++) {
			delete[] p[i];
		}
		delete[] p;
	}
	hang = x.hang;
	lie = x.lie;
	p = new T * [hang];
	for (int i = 0; i < hang; i++) {
		p[i] = new T[lie];
		for (int j = 0; j < lie; j++) {
			p[i][j] = x.p[i][j];
		}
	}
	return *this;
}

template<class T>
T* Vector<T>::operator[](int x)
{
	return p[x];
}

template<class T>
inline void Vector<T>::AlterElement(int m, int n, T x)
{
	p[m][n] = x;
}



#endif // !VECTOR_H
