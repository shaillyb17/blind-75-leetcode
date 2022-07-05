#include <iostream>
#include <vector>
using namespace std;

vector<int> countBits(int n) {
    vector<int> res;
    for(int i = 0; i <= n; i++) {
        int c = 0, t = i;
        while(t) {
            t = t & (t-1);
            c++;
        }
        res.push_back(c);
    }
    return res;
}

int main() {
    uint32_t n;
    cin >> n;
    vector<int> ans = countBits(n);
    for(auto x: ans)    cout<<x<<" ";
    return 0;
}