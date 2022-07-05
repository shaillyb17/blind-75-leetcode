#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    int cnt = 0;
    for(int i = 1; i < intervals.size(); i++) {
        if(intervals[i][0] < intervals[i - 1][1]) {
            cnt++;
            intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
        }
    }
    return cnt;        
}

int main(){
    int n;	cin >> n;
    vector<vector<int>> intervals;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        intervals.push_back({a, b});
    }
    cout << eraseOverlapIntervals(intervals);
    return 0;
}