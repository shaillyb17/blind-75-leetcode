#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals) {
    map<int, int> meetings;
    for(auto interval: intervals) {
        meetings[interval[0]] += 1;
        meetings[interval[1]] -= 1;
    }
    int maxRooms = 0, rooms = 0;
    for(auto x: meetings) {
        rooms += x.second;
        maxRooms = max(maxRooms, rooms);
    }
    return maxRooms;
}

int main(){
    int n;	cin >> n;
    vector<vector<int>> intervals;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        intervals.push_back({a, b});
    }
    cout << minMeetingRooms(intervals);
    return 0;
}