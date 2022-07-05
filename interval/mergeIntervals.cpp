#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    vector<int> interval = {intervals[0][0], intervals[0][1]};
    for(int i = 1; i < intervals.size(); i++) {
        if(interval[1] >= intervals[i][0])
            interval[1] = max(interval[1], intervals[i][1]);
        else if(interval[1] < intervals[i][0]) {
            res.push_back(interval);
            interval = {intervals[i][0], intervals[i][1]};
        }
        else
            res.push_back(intervals[i]);
    }
    res.push_back(interval);
    return res;
}

int main(){
    int n;	cin >> n;
    vector<vector<int>> intervals;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        intervals.push_back({a, b});
    }
    int s, e;
    cin >> s >> e;
    vector<vector<int>> ans = merge(intervals);
    for(auto x: ans) {
        cout << x[0] << " " << x[1] << endl;
    }
    return 0;
}