#include <iostream>
#include <vector>
#include <string>
using namespace std;

 bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for(int i = 0; i <= n; i++) {
        if(!dp[i])
            continue;
        for(auto word: wordDict) {
            int w = word.length();
            if(i + w > n)
                continue;
            if(word == s.substr(i, w))
                dp[i + w] = true;
        }
    }
    return dp[n];
}

int main(){
    string s;
    getline(cin, s);
    int n;	cin >> n;
    vector<string> dict;
    for(int i = 0; i < n; i++) {
        string t;
        getline(cin, t);
        dict.push_back(t);
    }
    cout << wordBreak(s, dict);
    return 0;
}