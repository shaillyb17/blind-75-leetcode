#include <iostream>
#include <vector>
using namespace std;

int hammingWeight(uint32_t n) {
    int cnt = 0;
    while(n) {
        n = n & n - 1;
        cnt++;
    }
    return cnt;
}

int main() {
    uint32_t n;
    cin >> n;
    cout<<hammingWeight(n);
    return 0;
}