#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int characterReplacement(string s, int k) {
    unordered_map<char, int> mp;
    int start = 0, end = 0, maxLen = INT_MIN, size = s.length();
    pair<char, int> maxOcc = {' ', -1};
    while(end < size) {
        mp[s[end]]++;
        if(mp[s[end]] > maxOcc.second)
            maxOcc = {s[end], mp[s[end]]};
        int len = end - start + 1;
        if(len - maxOcc.second <= k)
            maxLen = max(maxLen, len);
        else {
            mp[s[start]]--;
            if(maxOcc.first == s[start])
                maxOcc.second--;
            start++;
        }
        end++;
    }
    return maxLen;
}

int main(){
    string a;
    getline(cin, a);
    int b;  cin >> b;
    
    cout << characterReplacement(a, b);
    
    return 0;
}