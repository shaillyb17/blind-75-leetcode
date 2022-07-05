#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(vector<vector<char>>& board, int i, int j) {
    if(i >= 0 && i < board.size() && j >= 0 && j < board[0].size())
        return true;
    return false;
}

bool dfs(vector<vector<char>>& board, string word, int currWordSize, int i, int j) {
    
    // check if word found
    if(currWordSize == word.size())
        return true;       
    
    if(isSafe(board, i, j) && board[i][j] == word[currWordSize]) {
        
        // make choice
        char ch = board[i][j];
        board[i][j] = '*';
        
        bool ans = (dfs(board, word, currWordSize + 1, i+1, j) || dfs(board, word, currWordSize + 1, i-1, j) || dfs(board, word, currWordSize + 1, i, j+1) || dfs(board, word, currWordSize + 1, i, j-1));
        
        // backtrack
        board[i][j] = ch;            
        
        return ans;
    }
        
    return false;
    
}

bool exist(vector<vector<char>>& board, string word) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(board[i][j] == word[0] && dfs(board, word, 0, i, j))
                return true;
        }
    }
    return false;
}

int main(){
    int m, n;	cin >> m >> n;
    vector<vector<char>> matrix(m, vector<char>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    string word;
    getline(cin, word);
    cout << exist(matrix, word);    
    return 0;
}