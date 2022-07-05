#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int>& nums) {
    int res = nums.size(), i = 0;
    for(int x: nums) {
        res ^= i;
        res ^= x;
        i++;
    }
    return res;
}

int main() {
    int n;  cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)  cin >> arr[i];
    cout << missingNumber(arr);
}