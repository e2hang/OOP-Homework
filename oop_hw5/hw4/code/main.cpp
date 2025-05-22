#pragma once
#include <iostream>
#include <cstring>

using std::cin;
using std::cout;
using std::endl;

class A
{
public:
    A(int num) :data1(num) {}
    virtual ~A() {
        cout << " Destory A" << endl;
    }
    void f() const {
        cout << " Excute A::f() ";
        cout << " Data1=" << data1 << endl;
    }
    void g()
    {
        cout << " Excute A::g() " << endl;
    }
    A& operator=(A& x) {
        data1 = x.data1;
        return *this;
    }
protected:
    int data1;
};

class B : public A
{
public:
    B(int num1, int num2) :A(num1), data2(num2) {}
    virtual ~B() {
        cout << " Destory B" << endl;
    }
    void f() const {
        cout << " Excute B::f() ";
        cout << " Data1=" << data1;
        cout << " Data2=" << data2 << endl;
    }
    void f(int n) const {
        cout << " Excute B::f(int) ";
        cout << " n=" << n;
        cout << " Data1=" << data1;
        cout << " Data2=" << data2 << endl;
    }
    void h() {
        cout << " Excute B::h() " << endl;
    }
    B& operator=(B& x) {
        data2 = x.data2;
        //data1 = x.data1;
        this->A::operator=(x);
        return *this;
    }
private:
    int data2;
};

int main() {
        B b(1, 2);
        A* p = new B(1, 2);
        b.f();
        b.g();
        b.f(3);
        b.h();
        delete p;
    return 0;
}