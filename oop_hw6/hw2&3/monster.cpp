#include "monster.h"
#include <iostream>
#include <typeinfo>
#include <cstring>


std::string demangle(const char* name) {
	std::string s = name;
	std::string prefix = "class ";
	if (s.find(prefix) == 0) {
		s = s.substr(prefix.length());
	}
	return s;
}

void Monster::fight(Monster& a, Monster& b)
{
	//aÏÈ¹¥»÷b
	while (a.hp > 0 && b.hp > 0) {
		a.attack(b);
		if (a.hp <= 0) break;
		b.attack(a);
	}
	//Ð´Ò»¸ötypeid()
	std::string x, y;
	x = demangle(typeid(a).name());
	y = demangle(typeid(b).name());
	a.hp > 0 ? std::cout << "Monster " << x <<  " wins" << std::endl : std::cout << "Monster "<< y << " wins" << std::endl;
}

double& Monster::show_hp()
{
	return this->hp;
}

double& Monster::show_damage()
{
	return this->damage;
}

double& Monster::show_defence()
{
	return this->defence;
}

void Wolf::attack(Monster& a)
{
	a.show_hp() -= this->show_damage() - a.show_defence();
	std::cout << "Attacked! (!Wolf) remains  ¡°" << a.show_hp() << "¡± HP" << std::endl;
}

void Snake::attack(Monster& a)
{
	a.show_hp() -= this->show_damage() - a.show_defence();
	std::cout << "Attacked! (!Snake) remains ¡°" << a.show_hp() << "¡± HP" << std::endl;
}
Monster::~Monster() {

}