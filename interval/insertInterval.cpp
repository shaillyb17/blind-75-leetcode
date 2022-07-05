#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    for(int i = 0; i < intervals.size(); i++) {
        if(newInterval[1] < intervals[i][0]) {
            ans.push_back(newInterval);
            for(int j = i; j < intervals.size(); j++)
                ans.push_back(intervals[j]);
            return ans;
        }
        else if(newInterval[0] > intervals[i][1])
            ans.push_back(intervals[i]);
        else
            newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
    }
    ans.push_back(newInterval);
    return ans;
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
    vector<vector<int>> ans = insert(intervals, {s, e});
    for(auto x: ans) {
        cout << x[0] << " " << x[1] << endl;
    }
    return 0;
}