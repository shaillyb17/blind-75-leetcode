#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {   
    int cp = INT_MAX, profit = 0;
    for(int i = 0; i < prices.size(); i++) {
        if(cp > prices[i])
            cp = prices[i];
        else if(profit < prices[i] - cp)
            profit = prices[i] - cp;
    }
    return profit;
}

int main(){
    int n;  cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)      cin >> arr[i];
    cout << maxProfit(arr);
    return 0;
}