#include <iostream>
#include "box.h"
#include "fruit.h"

using namespace std;
int main() {
	Apple A[8];
	Orange O[8];
	Box B;
	cout << "Day 1" << endl;
	B.inBox(A[0]);
	B.inBox(O[0]);
	cout << "Apple : " << B.numApple() << endl;
	cout << "Orange : " << B.numOrange() << endl;
	cout << "WeightLoss : " << B.WeightLoss() << endl;
	B.UPDATE_ALL();

	cout << "Day 2" << endl;
	B.inBox(A[1]);
	B.inBox(O[1]);
	cout << "Apple : " << B.numApple() << endl;
	cout << "Orange : " << B.numOrange() << endl;
	cout << "WeightLoss : " << B.WeightLoss() << endl;
	cout << "Total Weight : " << B.totalWeight() << endl;
	B.UPDATE_ALL();

	cout << "Day 3" << endl;
	B.inBox(A[2]);
	cout << "Apple : " << B.numApple() << endl;
	cout << "Orange : " << B.numOrange() << endl;
	cout << "WeightLoss : " << B.WeightLoss() << endl;
	cout << "Total Weight : " << B.totalWeight() << endl;

	B.UPDATE_ALL();

	cout << "Day 4" << endl;
	B.inBox(O[2]);
	cout << "Apple : " << B.numApple() << endl;
	cout << "Orange : " << B.numOrange() << endl;
	cout << "WeightLoss : " << B.WeightLoss() << endl;
	cout << "Total Weight : " << B.totalWeight() << endl;

	B.UPDATE_ALL();

	cout << "Day 5" << endl;
	B.inBox(A[3]);
	B.inBox(O[3]);
	cout << "Apple : " << B.numApple() << endl;
	cout << "Orange : " << B.numOrange() << endl;
	cout << "WeightLoss : " << B.WeightLoss() << endl;
	cout << "Total Weight : " << B.totalWeight() << endl;

	B.UPDATE_ALL();

	return 0;
}