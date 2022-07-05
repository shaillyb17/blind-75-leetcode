#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canAttendMeetings(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    for(int i = 1; i < intervals.size(); i++) {
        if(intervals[i][0] < intervals[i - 1][1])
            return false;
    }
    return true;
}

int main(){
    int n;	cin >> n;
    vector<vector<int>> intervals;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        intervals.push_back({a, b});
    }
    cout << canAttendMeetings(intervals);
    return 0;
}