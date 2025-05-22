#include <iostream>
#include "print.h"
int print_count = 0;
void print(const std::string& s) {
    ++print_count;
    std::cout << s << std::endl;
}