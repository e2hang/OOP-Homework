#include "box.h"
#include <iostream>
#include <cstring>
#include <typeinfo>

std::string demangle(const std::string name) {
    std::string s = name;
    std::string prefix = "class ";
    if (s.find(prefix) == 0) {
        s = s.substr(prefix.length());
    }
    return s;
}

Box& Box::inBox(Fruit& x)
{
    fruit[num] = &x /*static_cast<int*> ()*/;
    num++;
    return *this;
    // TODO: 在此处插入 return 语句
}

int Box::numApple()
{
    int numA = 0;
    for (int i = 0;i < num;i++) {
        //std::string x = typeid(fruit[i]).name();
        //std::cout << demangle(x) << std::endl;
        Fruit* tmp = (Fruit*)fruit[i];
        if (tmp->checkLoss() == 4) numA++;
    }
    return numA;
}
int Box::numOrange()
{
    int numA = 0;
    for (int i = 0;i < num;i++) {
        Fruit* tmp = (Fruit*)fruit[i];
        if (tmp->checkLoss() == 3) numA++;
    }
    return numA;
}

int Box::WeightLoss()
{
    int WS = 0;
    for (int i = 0;i < num;i++) {
        if ( ((Fruit*)fruit[i])->isDryed() == false) {
            WS += ((Fruit*)fruit[i])->checkLoss();
        }
    }
    return WS;
}

int Box::totalWeight()
{
    int TotalW = 0;
    for (int i = 0;i < num;i++) {
        TotalW += ((Fruit*)fruit[i])->checkWeight();
    }
    return TotalW;
}

void Box::UPDATE_ALL()
{
    for (int i = 0;i < num;i++) {
        ((Fruit*)fruit[i])->upDate();
    }
}

