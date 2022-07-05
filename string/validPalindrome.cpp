#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool isPalindrome(string s) {
    string pal = "";
    for(auto ch: s) {
        if(ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9') {
            pal += tolower(ch);
        }
    }
    cout<<pal;
    string t = pal;
    reverse(t.begin(), t.end());
    if(t == pal)
        return true;
    return false;
}

int main(){
    string a;
    getline(cin, a);
    
    cout << isPalindrome(a);
    
    return 0;
}