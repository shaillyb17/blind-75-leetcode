#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    vector<int> lis;
    for(auto x: nums) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if(it == lis.end())
            lis.push_back(x);
        else
            *it = x;
    }
    return lis.size();
}

int main(){
    int n;	cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)  cin >> arr[i];
    cout << lengthOfLIS(arr);
    return 0;
}