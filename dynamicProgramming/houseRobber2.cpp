#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size(); 
    if(n == 0) return 0;
    if (n < 2) return nums[0];
    return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
}

int robber(vector<int>& nums, int l, int r) {
    int pre = 0, cur = 0;
    for (int i = l; i <= r; i++) {
        int temp = max(pre + nums[i], cur);
        pre = cur;
        cur = temp;
    }
    return cur;
}

int main(){
    int n;	cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)  cin >> arr[i];
    cout << rob(arr);
    return 0;
}