#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Codec {
public:
    queue<int> hash;
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encoded = "";
        for(auto s: strs) {
            hash.push(s.length());
            encoded += s;
        }
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        int start = 0;
        while(!hash.empty()) {
            strs.push_back(s.substr(start, hash.front()));
            start += hash.front();
            hash.pop();
        }
        return strs;
    }
};