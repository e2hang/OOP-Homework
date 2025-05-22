#include <iostream>
#include "print_this.h"
#include "print_that.h"
extern int print_count;

int main() {
#ifdef DO_THIS
    print_this("Hello");
#else
    print_that("Hello");
#endif
    std :: cout << "Print called " << print_count << " times." << std::endl;
    return 0;
}