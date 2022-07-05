#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n) {
    if (n == 1)
        return 1;
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i < n + 1; i++)
        dp[i] = dp[i - 2] + dp[i - 1];
    return dp[n];
}


int main(){
    int n;	cin >> n;
    cout << climbStairs(n);
    return 0;
}