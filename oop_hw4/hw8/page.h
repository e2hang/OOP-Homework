#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Paginate {
private:
	int page_total;
	int page_now;
public:
	Paginate();
	Paginate(int n);
	Paginate& setPage(int n);
	void show();
	Paginate& next();
	Paginate& prev();
	Paginate& nextN();
	Paginate& prevN();
};