#include <iostream>
#include "monster.h"
using namespace std;
int main(){
	Wolf A(100, 10, 3);
	Snake B(50, 15, 5);
	Monster::fight(A,B);
	return 0;
}