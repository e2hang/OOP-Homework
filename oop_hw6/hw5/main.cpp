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
        cout << "ƽ����=" << srv.Total(*this) << endl;//7
    }
};

//������1	
int main()
{
    Server   srv2(2), srv5(5);
    ClientA  a;
    a.RequestA(srv2);  //���3 
    a.RequestA(srv5);  //���15
//������2	 
    Server   ssrv3(3);
    ClientB  b;
    b.RequestB(srv2);
    b.RequestB(srv3);
    return 0;
}

/*
1)��ֱ�����ո�1 - 5����ȷ�Ĵ��룬ʹ��������1�����Ϊ3��15.
2)��ֱ�����ո�6 - 7����ȷ�Ĵ��룬ʹ��������2�����Ϊ��
ƽ���� = 5
ƽ���� = 14
3)������ʵ��ClientB�е���غ�����ʹ��������2�����Ϊ��
1  2  �������� = 9
1  2  3  �������� = 36

*/