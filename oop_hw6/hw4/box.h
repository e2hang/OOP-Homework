#pragma once
#include <iostream>
#include "fruit.h"


class Box {
private:
	void* fruit[8]{};
	int num = 0;
	int TotalDate = 0;
	int lossTotal = 0;
public:
	int returnDate();
	Box& inBox(Fruit& x);
	int numApple();
	int numOrange();
	int WeightLoss();
	int totalWeight();
	void UPDATE_ALL();
	friend Fruit;
};