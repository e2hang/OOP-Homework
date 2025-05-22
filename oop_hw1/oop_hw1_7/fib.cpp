#include <iostream>
long& smaller(long& a, long& b) { return (a < b) ? a : b; }
long& bigger(long& a, long& b) { return (a >= b) ? a : b; }

void fibe(int count) {
    long a = 1, b = 1;
    for (int i = 0; i < count; i++) {
        long& min = smaller(a, b);
        long& max = bigger(a, b);
        min = a + b;
        std::cout << max << " ";
    }
    std::cout << std::endl;
}