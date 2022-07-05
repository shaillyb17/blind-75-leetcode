#include <iostream>
#include <vector>
using namespace std;

int getSum(int a, int b) {
    unsigned int c;
    while(b != 0) {
        c = a & b;  // calculates carry
        a = a ^ b;  // addition
        b = c << 1; // adds carry for next iter
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << getSum(a, b);
    return 0;
}