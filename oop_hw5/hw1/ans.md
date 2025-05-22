## **1）第一段代码分析：递归构造与输出**

```cpp
class A {
public:
    A(int n):val(n){}
protected:
    int val;
};

class B : public A {
public:
    B(int n) :A(n)
    {
        pB = (n > 0 ? new B(n-1) : 0);
    }

    ~B() { delete pB; }

    void Display()
    {
        cout << val << endl;
        if (pB != 0)
            pB->Display();
    }

private:
    B* pB;
};
```

### 📌 构造逻辑：

* `B(4)` 被创建时，会递归构造 `B(3) → B(2) → B(1) → B(0) → B(-1)` 停止（因 `n == 0` 时 `pB = 0`）
* 每一层的 `val` 都是当前 `n`

### 📌 输出逻辑：

`b.Display()` 调用后会：

```cpp
cout << 4
  -> Display() on B(3)
    cout << 3
      -> Display() on B(2)
        cout << 2
          -> Display() on B(1)
            cout << 1
              -> Display() on B(0)
                cout << 0
```

所以最终输出是：

```
4
3
2
1
0
```

### ✅ **运行结果1**：

```
4
3
2
1
0
```

---

## **2）第二段代码分析：构造顺序与拷贝构造**

```cpp
class A {
public:
    A(int n):num(n) { Out(); }
    A(const A& rhs):num(rhs.num) { Out(); }
    void Out() { cout << num << endl; }
private:
    int num;
};

class B : public A {
public:
    B(A& a) : obj(a), A(1) { }
    void Out() { obj.Out(); }

private:
    A obj;
};
```

### 📌 构造顺序注意：

在 `B(A& a) : obj(a), A(1)` 中，尽管初始化顺序写的是先 `obj`，再 `A`，**但实际构造顺序是：**

1. 先构造基类 A（即 `A(1)`）
2. 再构造成员对象 `obj(a)`（调用拷贝构造函数）

### 📌 main 函数：

```cpp
A a(8);      // 输出：8
B b1(a);     // 顺序：
             // A(1) → 输出：1
             // obj(a) 拷贝构造 → 输出：8
B b2(b1);    // 和上面类似，只是复制的是 b1 对象的成员 obj
             // A(1) → 输出：1
             // obj(b1.obj) 拷贝构造 → 输出：8

b2.Out();    // 调用 obj.Out() → 输出：8
```

### ✅ **运行结果2**：

```
8
1
8
1
8
8
```

---

## ✅ 两段程序的输出分别是：

### **程序1 输出：**

```
4
3
2
1
0
```

### **程序2 输出：**

```
8
1
8
1
8
8
```
