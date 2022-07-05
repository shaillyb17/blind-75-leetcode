#include <iostream>
#include <vector>
using namespace std;

int maxSubarray(vector<int>& nums) {   
    int n = nums.size(), low = 0, high = n - 1, mid = 0;
    while (low < high) {
        mid = low + (high - low) / 2;
        if(nums[mid] > nums[high])
            low = mid + 1;
        else
            high = mid;
    }
    return nums[low];
}

int main(){
    int n;  cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)      cin >> arr[i];
    cout << maxSubarray(arr);
    return 0;
}