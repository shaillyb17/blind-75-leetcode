#include <iostream>
#include <algorithm>
using namespace std;

class Trie {
public:
    Trie* next[26] = {};
    bool isWord;
    Trie() {
        isWord = false;
    }
};

class WordDictionary {
    Trie* root = new Trie();
    
    bool search(const char* word, Trie* node) {
        for(int i = 0; word[i] && node; i++) {
            if(word[i] != '.') {
                node = node->next[word[i] - 'a'];
            }
            else {
                Trie* temp = node;
                for(int j = 0; j < 26; j++) {
                    node = temp->next[j];
                    if(search(word + i + 1, node))
                        return true;
                }
            }                
        }
        return node && node->isWord;
    }
    
public:
    WordDictionary() {}
    
    void addWord(string word) {
        Trie* node = root;
        for(char ch: word) {
            ch -= 'a';
            if(!node->next[ch])
                node->next[ch] = new Trie();
            node = node->next[ch];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return search(word.c_str(), root);
    }
    
};

int main(){
    // tree initialisation 
    
    return 0;
}