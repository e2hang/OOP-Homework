#pragma once
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class Person {
private:
	int age;
	string name;
	//enum string gender = { "Male","Female" }; 对不起，忘了怎么写了呜呜
	bool gender;//1 = Male , 0 = Female
public:
	Person() :age(-1), name("#UNDEFINED"), gender(true) {};
	Person(int a, string n, bool g);
	void change_age(int ca);
	void change_name(string cn);
	void change_gender(bool x);
	int show_age();
	string show_name();
	bool show_gender();
	virtual void display();
};

class Employee : public Person {
private:
	int number;
public:
	Employee() :Person(-1, "#UNDEFINED", true), number(-1) {};
	Employee(int a, string n, bool g, int num) : Person(a, n, g), number(num) {};
	void add_number(int n);
	void display();
};
class Executive : public Employee {
public:
	void display();
};

