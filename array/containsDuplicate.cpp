#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {   
    set<int> s;
    for(int i = 0; i < nums.size(); i++)
        s.insert(nums[i]);
    if(nums.size() > s.size())
        return true;
    return false;
}

int main(){
    int n;  cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)      cin >> arr[i];
    cout << containsDuplicate(arr);
    return 0;
}