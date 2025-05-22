#include <iostream>
double average(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) sum += arr[i];
    return (double)sum / size;
}
using namespace std;
int main() {
    int n;
    cin >> n;
    int * a = new int[n];
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }
    cout << average(a, n);
    return 0;
}