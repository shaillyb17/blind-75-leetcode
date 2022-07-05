#include <iostream>
#include <string>
using namespace std;

int countSubstrings(string s) {
    int l, r;
    int ans = 0;
    for(int i = 0; i < s.length(); i++) {
        // considering odd palindrome
        l = r = i;
        while(l >= 0 && r < s.length() && s[l] == s[r]) {
            ans++;
            l--;
            r++;
        }
        // considering even palindrome
        l = i;
        r = i + 1;
        while(l >= 0 && r < s.length() && s[l] == s[r]) {
            ans++;
            l--;
            r++;
        }
    }
    return ans;
}

int main(){
    string s;
    getline(cin, s);
    cout << countSubstrings(s);
    return 0;
}