#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> mp;
    for(auto s: strs) {
        string t = s;
        sort(t.begin(), t.end());
        mp[t].push_back(s);
    }
    for(auto x: mp) {
        res.push_back(x.second);
    }
    return res;
}

int main(){
    int n;	cin >> n;
    
    return 0;
}