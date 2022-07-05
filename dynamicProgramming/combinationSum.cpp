#include <iostream>
#include <vector>
using namespace std;

int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> dp(target + 1, 0);
    for(int i = 1; i <= target; i++) {
        for(auto x: nums) {
            if(x == i)
                dp[i] += 1;
            else if (x < i)
                dp[i] += dp[i - x];
        }
    }
    return dp[target];
}

int main(){
    int n;	cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++)	cin >> arr[i];
    int target;
    cin >> target;
    cout << combinationSum4(arr, target);
    return 0;
}