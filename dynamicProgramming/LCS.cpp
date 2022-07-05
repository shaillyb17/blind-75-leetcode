#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length(), n = text2.length();
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    
    for(int i = 0; i < m + 1; i++)
        for(int j = 0; j < n + 1; j++)
            if(i == 0 || j == 0)
                dp[i][j] = 0;
    
    
    for(int i = 1; i < m + 1; i++) {
        for(int j = 1; j < n + 1; j++) {
            if(text1[i-1] == text2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    
    // Print the LCS
    int a = m, b = n;
    vector<char> lcs;
    while(a && b) {
        
        if(text1[a - 1] == text2[b - 1]) {
            lcs.push_back(text1[a-1]);
            a--;
            b--;
        }
        
        else {
            
            if(dp[a-1][b] > dp[a][b-1])
                a--;
            else
                b--;
        }
    }
    reverse(lcs.begin(), lcs.end());
    for(auto x: lcs)
        cout<<x;
    
    // Print length
    return dp[m][n];
}

int main(){
    string a, b;
    getline(cin, a);
    getline(cin, b);
    cout << longestCommonSubsequence(a, b);
    
    return 0;
}
