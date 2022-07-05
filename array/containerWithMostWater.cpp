#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& arr) {
    int i = 0, j = arr.size() - 1;
    int area = 0;
    while(i < j) {
        int h = min(arr[i], arr[j]);
        area = max(area, h * (j - i));
        while(i < j && arr[i] <= h) i++;
        while(i < j && arr[j] <= h) j--;
    }
    return area;
}

int main(){
    int n;  cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)      cin >> arr[i];
    cout << maxArea(arr);
    return 0;
}