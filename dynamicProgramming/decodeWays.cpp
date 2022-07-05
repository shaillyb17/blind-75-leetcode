#include <iostream>
#include <vector>
#include <string>
using namespace std;

int numDecodings(string s) {
    int n = s.length();
    vector<int> dp(n + 1);
    dp[n] = 1;
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == '0')
            dp[i] = 0;
        else {
            dp[i] = dp[i + 1];
            if(i < n-1 && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')))
                dp[i] += dp[i + 2];
        }
    }
    return dp[0];            
}

int main(){
    string s;
    getline(cin, s);
    cout << numDecodings(s);    
    return 0;
}