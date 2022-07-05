#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string longestPalindrome(string s) {
    int size = s.length();
    int l, r, maxLen = INT_MIN;
    string res;
    for(int i = 0; i < size; i++) {
        // odd palindromes
        l = i, r = i;
        while(l >= 0 && r < size && s[l] == s[r]) {
            if(r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                res = s.substr(l, maxLen);
            }
            r++;
            l--;
        }
        // even palindromes
        l = i, r = i + 1;
        while(l >= 0 && r < size && s[l] == s[r]) {
            if(r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                res = s.substr(l, maxLen);
            }
            r++;
            l--;
        }
    }
    return res;
}

int main(){
    string s;
    getline(cin, s);
    cout << longestPalindrome(s);
    return 0;
}