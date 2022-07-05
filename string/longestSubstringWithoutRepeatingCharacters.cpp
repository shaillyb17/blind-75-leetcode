#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    if (s.length()==0)
        return 0;
    int maxCount = 1, counter = 0;
    unordered_map<char,int> mp;
    for(int i=0;i<s.length();i++){            
        if(mp[s[i]]){
            maxCount = max(counter,maxCount);
            counter=0;
            mp.clear();
        }
        mp[s[i]]++;
        counter++;
    }
    maxCount = max(counter,maxCount);
    return maxCount;        
}

int main(){
    string s;
    getline(cin, s);
    cout << lengthOfLongestSubstring(s);    
    return 0;
}