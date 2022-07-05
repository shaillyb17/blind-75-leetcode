#include <iostream>
#include <vector>
using namespace std;

int maxSubarray(vector<int>& nums) {   
    int maxSoFar = 0, sumUptilNow = 0;
    for(int i = 0; i < nums.size(); i++) {
        sumUptilNow += nums[i];
        if(maxSoFar < sumUptilNow)
            maxSoFar = sumUptilNow;
        if(sumUptilNow < 0)
            sumUptilNow = 0;
    }
    return maxSoFar;
}

int main(){
    int n;  cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)      cin >> arr[i];
    cout << maxSubarray(arr);
    return 0;
}