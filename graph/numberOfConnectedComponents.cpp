#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;

void dfs(int curr, vector<int>& vis, int parent) {
    cout << curr<< " " << parent << endl;
    vis[curr] = 1;
    for(auto x: adj[curr]) {
        if(vis[x] == 0)
            dfs(x, vis, curr);              
    }
}

int countComponents(int n, vector<vector<int>>& edges) {
    // making adjacency list
    adj.resize(n);
    for(auto x: edges) {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    
    // making visited memo
    vector<int> vis(n, 0);   
    
    int cnt = 0;
    
    // count components
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, vis, -1);
            cnt++;
        }
    }
    
    return cnt;        
}

int main(){
    // initialisation of graph is not implemented
    // only functions defined as required on leetcode
    
    return 0;
}