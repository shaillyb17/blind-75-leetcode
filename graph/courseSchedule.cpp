#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

vector<int> vis;
vector<vector<int>> adj;
int courses = 0;

bool dfs(int v) {
    if(vis[v] == -1)
        return false;
    if(vis[v] == 1)
        return true;
    vis[v] = -1;
    
    for(auto neighbor: adj[v]) {
        if(!dfs(neighbor))
            return false;
    }
    vis[v] = 1;
    courses++;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
    // build graph
    adj.resize(numCourses);
    vis.resize(numCourses, 0);
    for(auto x: prerequisites) {
        adj[x[1]].push_back(x[0]);
    }
    
    // start dfs
    for(int i = 0; i < numCourses; i++) {
            if(!vis[i])
                dfs(i);
    }
            
    return courses == numCourses;
}

int main(){
    // initialisation of graph is not implemented
    // only functions defined as required on leetcode
    
    return 0;
}