#include "animal.h"
#include <iostream>
#include <cstring>

Animal::Animal() {
	name = "#UNDEFINED";
	weight = -1;
}
Animal::Animal(std::string n, int w) {
	name = n;
	weight = w;
}
std::string Animal::show_name()
{
	return name;
}
int Animal::show_weight()
{
	return weight;
}
void Animal::who() {
	std::cout << "This is an Animal" << std::endl;
	std::cout << "Name : " << name << std::endl
		<< "Weight : " << weight << std::endl;
}
Lion::Lion() {
	this->change_name("#UNDEFINED_LION_NAME");
	this->change_weight(-1);
}
Lion::Lion(std::string n,int w) {
	this->change_name(n);
	this->change_weight(w);
}
void Lion::who() {
	std::cout << "This is a Lion" << std::endl;
	std::cout << "Name : " << this->show_name() << std::endl
		<< "Weight : " << this->show_weight() << std::endl;
}
Aardvark::Aardvark() {
	this->change_name("#UNDEFINED_LION_NAME");
	this->change_weight(-1);
}
Aardvark::Aardvark(std::string n, int w) {
	this->change_name(n);
	this->change_weight(w);
}
void Aardvark::who() {
	std::cout << "This is a Aardvark" << std::endl;
	std::cout << "Name : " << this->show_name() << std::endl
		<< "Weight : " << this->show_weight() << std::endl;
}
void Animal::change_name(std::string cn) {
	name = cn;
}
void Animal::change_weight(int cw) {
	weight = cw;
}