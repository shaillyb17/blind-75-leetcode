#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    
    for(auto x: nums)
        mp[x]++;
    
    priority_queue<pair<int, int>> pq;
    for(auto x: mp)
        pq.push({x.second, x.first});
    
    vector<int> res;
    while(k--) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    
    return res; 
}

int main(){
    int n;	cin >> n;
    
    return 0;
}