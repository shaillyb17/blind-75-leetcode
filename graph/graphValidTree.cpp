#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;

bool findCycleDFS(int curr, vector<int>& vis, int parent) {
    cout << curr<< " " << parent << endl;
    vis[curr] = 1;
    for(auto x: adj[curr]) {
        if(x != parent) {
            if(vis[x] == 1)
                return true;
            if(vis[x] == 0) {
                if(findCycleDFS(x, vis, curr))
                    return true;                    
            }
        }             
    }
    vis[curr] = 2;
    return false;
}

bool validTree(int n, vector<vector<int>>& edges) {
    // obvious base case
    if(edges.size() != n - 1)        return false;
    
    // making adjacency list
    adj.resize(n);
    for(auto x: edges) {
        adj[x[0]].push_back(x[1]);
        adj[x[1]].push_back(x[0]);
    }
    
    // making visited memo
    vector<int> vis(n, 0);       
    
    // find cycle         
    if(findCycleDFS(0, vis, -1))
        return false;
    
    // find unvisited 
    for(int x: vis)    if(x == 0)  return false;
    
    return true;
}

int main(){
    // initialisation of graph is not implemented
    // only functions defined as required on leetcode
    
    return 0;
}