#include <iostream>
#include <algorithm>
using namespace std;

class Trie {
    Trie* next[26] = {};
    bool isWord = false;
public:
    Trie() {
        
    }
    
    void insert(string word) {
        Trie* node = this;
        for(char ch: word) {
            ch -= 'a';
            if(!node->next[ch])
                node->next[ch] = new Trie();
            node = node->next[ch];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(char ch: word) {
            ch -= 'a';
            if(!node->next[ch])
                return false;
            node = node->next[ch];
        }
        return node->isWord;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(char ch: prefix) {
            ch -= 'a';
            if(!node->next[ch])
                return false;
            node = node->next[ch];
        }
        return true;
    }
};

int main(){
    // tree initialisation 
    
    return 0;
}