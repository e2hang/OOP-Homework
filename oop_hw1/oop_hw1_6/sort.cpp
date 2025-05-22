#include <algorithm>
void sort_two(int& a, int& b) {
    if (a < b) std::swap(a, b);
}
void sort_three(int& a, int& b, int& c) {
    if (a < b) std::swap(a, b);
    if (a < c) std::swap(a, c);
    if (b < c) std::swap(b, c);
}