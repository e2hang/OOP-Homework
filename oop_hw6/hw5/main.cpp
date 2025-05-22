#include <iostream>
using namespace std;
class CallBackObject;
class Server
{
public:
    Server(int size) :len(size)
    {
        data = new int [len];//1
        for (int i = 0;i < len;++i)
            data[i] = i + 1;
    }
    ~Server() { delete[] data; }//2
    int Total(CallBackObject& obj);
private:
    int  len;
    int* data;
};

class CallBackObject
{
public:
    virtual ~CallBackObject() {}
    virtual int CallBackFunc(int val) = 0;//4
};

class ClientA :public CallBackObject
{
public:
    virtual ~ClientA() {}
    virtual int CallBackFunc(int val)
    {
        return val;
    }
    void RequestA(Server& srv)
    {
        cout << srv.Total(*this) << endl;//5
    }
};
int Server::Total(CallBackObject& obj)
{
    int sum = 0;
    for (int i = 0; i < len; ++i) {
        sum += obj.CallBackFunc(data[i]);//3
    }
    return sum;
}

class ClientB :public CallBackObject
{
public:
    virtual ~ClientB() {}
    virtual int CallBackFunc(int val)
    {
        return val * val;//6
    }
    void RequestB(Server& srv) {
        cout << "平方和=" << srv.Total(*this) << endl;//7
    }
};

//主函数1	
int main()
{
    Server   srv2(2), srv5(5);
    ClientA  a;
    a.RequestA(srv2);  //输出3 
    a.RequestA(srv5);  //输出15
//主函数2	 
    Server   ssrv3(3);
    ClientB  b;
    b.RequestB(srv2);
    b.RequestB(srv3);
    return 0;
}

/*
1)请分别给出空格1 - 5中正确的代码，使得主函数1的输出为3和15.
2)请分别给出空格6 - 7中正确的代码，使得主函数2的输出为：
平方和 = 5
平方和 = 14
3)请重新实现ClientB中的相关函数，使得主函数2的输出为：
1  2  的立方和 = 9
1  2  3  的立方和 = 36

*/