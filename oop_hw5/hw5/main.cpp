#include <iostream>
using namespace std;

class A {
public:
    A(int num) : data(num) {
        cout << "A constructed with data = " << data << endl;
    }
    void AFuncs() {
        cout << "This is A's public function!" << endl;
    }
    A(const A& other) : data(other.data) {
        cout << "A copy constructor called." << endl;
    }
    A& operator=(const A& other) {
        if (this != &other) {
            data = other.data;
        }
        return *this;
    }
    ~A() {
        cout << "A destructor called." << endl;
    }

protected:
    int data;
};

class B {
public:
    B(int num) : value(num) {
        cout << "B constructed with value = " << value << endl;
    }
    void BFuncs() {
        cout << "This is B's public function!" << endl;
    }
    B(const B& other) : value(other.value) {
        cout << "B copy constructor called." << endl;
    }
    B& operator=(const B& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }
    ~B() {
        cout << "B destructor called." << endl;
    }

protected:
    int value;
};

// === 原始多继承版本 ===
class C1 : public A, private B {
public:
    C1(int num1, int num2, int y) : A(num1), B(num2), yyy(y) {
        cout << "C1 constructed with yyy = " << yyy << endl;
    }
    void MyFuncs() {
        BFuncs();
        cout << "This function calls B::BFuncs() !" << endl;
    }

private:
    int yyy;
};

// === 单继承 + 组合版本 ===
class C2 : public A {
public:
    C2(int num1, int num2, int y)
        : A(num1), b(num2), yyy(y) {
        cout << "C2 constructed with yyy = " << yyy << endl;
    }

    C2(const C2& other)
        : A(other), b(other.b), yyy(other.yyy) {
        cout << "C2 copy constructor called." << endl;
    }

    C2& operator=(const C2& other) {
        if (this != &other) {
            A::operator=(other);
            b = other.b;
            yyy = other.yyy;
        }
        cout << "C2 assignment operator called." << endl;
        return *this;
    }

    ~C2() {
        cout << "C2 destructor called." << endl;
    }

    void MyFuncs() {
        b.BFuncs();
        cout << "This function calls B::BFuncs() !" << endl;
    }

private:
    B b;
    int yyy;
};

// === 主函数 ===
int main() {
    cout << "=== 多继承测试 ===" << endl;
    C1 obj1(10, 20, 30);
    obj1.AFuncs();
    obj1.MyFuncs();
    cout << endl;

    cout << "=== 单继承 + 组合测试 ===" << endl;
    C2 obj2(100, 200, 300);
    obj2.AFuncs();
    obj2.MyFuncs();

    cout << "--- 拷贝构造 ---" << endl;
    C2 obj3 = obj2;

    cout << "--- 赋值运算 ---" << endl;
    C2 obj4(1, 2, 3);
    obj4 = obj3;

    cout << "--- 析构顺序开始 ---" << endl;
    return 0;
}
