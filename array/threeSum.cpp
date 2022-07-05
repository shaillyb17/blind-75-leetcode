#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        int target = -nums[i];
        if(target < 0)  break;
        int front = i + 1;
        int back = n - 1;
        while(front < back) {
            int sum = nums[front] + nums[back];
            if(sum < target) 
                front++;
            else if(sum > target)
                back--;
            else {
                int a = nums[i], b = nums[front], c = nums[back];
                res.push_back({a, b, c});
                while(front < back && nums[front] == b)
                    front++;
                while(front < back && nums[back] == c)
                    back--;
            }
        }
        while(i + 1 < n && nums[i] == nums[i+1])
            i++;
    }
    return res;
}

int main() {
    int n;  cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)  cin >> arr[i];
    vector<vector<int>> ans = threeSum(arr);
    for(auto x: ans)
        cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
    return 0;
}