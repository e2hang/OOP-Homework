
#pragma once
#include <iostream>
#include <cstring>

class Animal {
private:
	std::string name;
	int weight;
public:
	Animal();
	Animal(std::string n, int w);
	std::string show_name();
	int show_weight();
	void change_name(std::string cn);
	void change_weight(int cw);
	virtual void who();
protected:
	
};

class Lion : public Animal {
public:
	Lion();
	Lion(std::string n, int w);
	void who();
};

class Aardvark : public Animal {
public:
	Aardvark();
	Aardvark(std::string n, int w);
	void who();
};