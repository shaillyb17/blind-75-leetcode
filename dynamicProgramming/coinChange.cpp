#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for(int i = 1; i < amount + 1; i++) {
        for(int j = 0; j < coins.size(); j++) {
            if(coins[j] <= i)
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int main(){
    int n;	cin >> n;
    vector<int> arr(n);	
    for(int i = 0; i < n; i++)  cin >> arr[i];
    int amount; cin >> amount;
    cout << coinChange(arr, amount);
    return 0;
}