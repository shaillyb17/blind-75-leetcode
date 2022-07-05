#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t) {
    // store t char counts
    unordered_map <char, int> mp;
    for(auto ch: t)
        mp[ch]++;
    
    // two pointers + counter, minLen, minStart to keep track of (min) substring length
    int start = 0, end = 0, minStart = 0, minLen = INT_MAX, counter = t.size(), size = s.length();
    
    while(end < size) {
        if(mp[s[end]] > 0)  // if curr char found in t
            counter--;
        mp[s[end]]--;     // t character count decreases by 1 and non-t become negative
        end++;
        // when window is valid
        while(counter == 0) {
            // update minWindow if smaller window is found
            if(end - start < minLen) {
                minStart = start;
                minLen = end - start;
            }
            // this is where the negative characters are useful (can go max upto 0), t-chars become +ve
            mp[s[start]]++;
        
            if(mp[s[start]] > 0)
                counter++;
            start++;
        }
    }
    if(minLen != INT_MAX)
        return s.substr(minStart, minLen);
    return "";
}

int main(){
    string a, b;
    getline(cin, a);
    getline(cin, b);
    
    cout << minWindow(a, b);
    
    return 0;
}