#include <bits/stdc++.h>

class Demo {
private:
    int mNum;
    static Demo* instance;
    Demo() : mNum(0) {}
public:
    static Demo* GetInstance() {
        if (!instance) instance = new Demo();
        return instance;
    }
    void AddValue(int value) { mNum += value; }
    void ShowValue() const { std::cout << "Value=" << mNum << std::endl; }
};
Demo* Demo::instance = NULL;

void Test() {
    Demo::GetInstance()->AddValue(10);
    Demo::GetInstance()->AddValue(5);
    Demo::GetInstance()->ShowValue();
}

int main(){
	Test(); 
	return 0;
}
