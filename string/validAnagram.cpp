#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if(s == t)
        return true;
    return false;
}

int main(){
    string s, t;
    getline(cin, s);
    getline(cin, t);    
    return 0;
}