#include "person.h"

Person::Person(int a, string n, bool g)
{
	age = a;
	name = n;
	gender = g;
}

void Person::change_age(int ca)
{
	age = ca;
}

void Person::change_name(string cn)
{
	name = cn;
}

void Person::change_gender(bool x)
{
	gender = x;
}

int Person::show_age()
{
	return age;
}

string Person::show_name()
{
	return name;
}

bool Person::show_gender()
{
	return gender;
}

void Person::display()
{
	cout << "This is a Person" << endl
		<< "Name : " << name << endl
		<< "Age : " << age << endl
		<< "Gender : ";
	gender == false ? cout << "Woman" << endl : cout << "Man" << endl;
}

void Employee::add_number(int n)
{
	number = n;
}

void Employee::display()
{
	cout << "This is an Employee" << endl
		<< "Name : " << this->show_name() << endl
		<< "Age : " << this->show_age() << endl
		<< "Gender : ";
	this->show_gender() == false ? cout << "Woman" << endl : cout << "Man" << endl;
	cout << "Number ID : " << number << endl;
}

void Executive::display()
{
	cout << "This is an Executive" << endl
		<< "Name : " << this->show_name() << endl
		<< "Age : " << this->show_age() << endl
		<< "Gender : ";
	this->show_gender() == false ? cout << "Woman" << endl : cout << "Man" << endl;
	//cout << "Number ID : " << number << endl;
}
