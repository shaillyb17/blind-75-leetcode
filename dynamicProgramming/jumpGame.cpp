#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canJump(vector<int>& nums) {
    int maxSoFar = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(maxSoFar < i)
            return false;
        maxSoFar = max(i + nums[i], maxSoFar);
    }
    return true;
}

int main(){
    int n;	cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)  cin >> arr[i];
    cout << canJump(arr);
    return 0;
}