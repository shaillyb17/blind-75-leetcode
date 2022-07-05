#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubarray(vector<int>& nums) {   
    int lr = 1, rl = 1, maxP = nums[0], n = nums.size();
    for(int i = 0; i < n; i++) {
        lr = (lr ? lr : 1) * nums[i];
        rl = (rl ? rl : 1) * nums[n - 1 - i];
        maxP = max(maxP, max(lr, rl));
    }
    return maxP;
}

int main(){
    int n;  cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)      cin >> arr[i];
    cout << maxSubarray(arr);
    return 0;
}