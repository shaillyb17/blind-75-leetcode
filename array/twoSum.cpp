#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> v(2);
    int n = nums.size();
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++) {
        if(mp.find(target - nums[i]) != mp.end()) {
            v[0] = i;
            v[1] = mp[target - nums[i]];
            return v;
        }
        mp[nums[i]] = i;
    }
    return v;        
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)      cin >> arr[i];
    int target;
    cin >> target;
    vector<int> ans = twoSum(arr, target);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}