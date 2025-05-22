#pragma once
#include <iostream>

class Fruit {
private:
	int weight;
	int loss;
	int DatePassed = 0;
	bool Dry = false;
public:
	Fruit();
	Fruit(int w, int l);
	int& checkWeight();
	int checkLoss();
	void upDate();
	void Dryed();
	bool isDryed();
	virtual void losewater() = 0;
};

class Apple : public Fruit {
private:
	
public:
	Apple() : Fruit(50, 4) {};
	//Apple(int, int) = delete;
	Apple(const Apple& x) = delete;
	void losewater();
};

class Orange : public Fruit {
private:

public:
	Orange() : Fruit(30, 3) {};
	//Orange(int, int) = delete;
	Orange(const Apple& x) = delete;
	void losewater();
};