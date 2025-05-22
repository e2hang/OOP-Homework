#pragma once
#include <iostream>

class Monster {
private:
	double hp;
	double damage;
	double defence;
public:
	Monster() : hp(0), damage(0), defence(0) {};
	Monster(double h, double dam, double den) : hp(h), damage(dam), defence(den) {};
	virtual void attack(Monster& a) = 0;
	static void fight(Monster& a,Monster& b);
	double& show_hp();
	double& show_damage();
	double& show_defence();
	virtual ~Monster();
};

class Wolf : public Monster{
public:
	Wolf() : Monster(0,0,0){};
	Wolf(double h, double dam, double den) : Monster(h, dam, den) {};
	void attack(Monster& a) override;
	
};

class Snake : public Monster {
public:
	Snake() : Monster(0, 0, 0) {};
	Snake(double h, double dam, double den) : Monster(h, dam, den) {};
	void attack(Monster& a) override;

};