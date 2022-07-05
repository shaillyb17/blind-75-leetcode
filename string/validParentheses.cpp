#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<int> st;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else {
            if(st.empty())
                return false;
            if(s[i] == ')') {
                if(st.top() != '(')
                    return false;
                st.pop();
            }
            else if(s[i] == '}') {
                if(st.top() != '{')
                    return false;
                st.pop();
            }
            else if(s[i] == ']') {
                if(st.top() != '[')
                    return false;
                st.pop();
            }
        }
    }
    if(st.empty())
        return true;
    return false;
}

int main(){
    string s;
    getline(cin, s);
    cout << isValid(s);    
    return 0;
}