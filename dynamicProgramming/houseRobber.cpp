#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = nums[0];
    for(int i = 2; i <= n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }
    return dp[n];
}

int main(){
    int n;	cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)  cin >> arr[i];
    cout << rob(arr);
    return 0;
}