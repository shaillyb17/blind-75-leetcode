#include <iostream>
#include <vector>
#include <utility>
#include <set>
using namespace std;

void dfs(int r, int c, set<pair<int, int>>& visit, int prevHeight, int rows, int cols, vector<vector<int>>& heights) {
    if(visit.find({r,c}) != visit.end() || r < 0 || c < 0 || r == rows || c == cols || heights[r][c] < prevHeight)
        return;
    visit.insert({r,c});
    dfs(r+1, c, visit, heights[r][c], rows, cols, heights);
    dfs(r-1, c, visit, heights[r][c], rows, cols, heights);
    dfs(r, c+1, visit, heights[r][c], rows, cols, heights);
    dfs(r, c-1, visit, heights[r][c], rows, cols, heights);
    return;
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    // start from the oceans instead of the islands
    // from the borders, see which acme points you can reach and add to the set of that ocean
    // if a particular coordinate occurs in both pac and atl set, it is a good point
    
    // get rows and cols
    int r = heights.size(), c = heights[0].size();
    
    // initialize data structures
    set<pair<int,int>> pac, atl;
    
    // start exploring top and bottom rows
    for(int cols = 0; cols < c; cols++) {
        dfs(0, cols, pac, heights[0][cols], r, c, heights);
        dfs(r - 1, cols, atl, heights[r - 1][cols], r, c, heights);
    }
    
    // start exploring leftmost and rightmost cols
    for(int rows = 0; rows < r; rows++) {
        dfs(rows, 0, pac, heights[rows][0], r, c, heights);
        dfs(rows, c - 1, atl, heights[rows][c - 1], r, c, heights);
    }
    vector<vector<int>> ans;
    // check the coordinates accessible to both oceans
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if((pac.find({i,j}) != pac.end()) && (atl.find({i,j}) != atl.end())) {
                ans.push_back({i,j});
            }                    
        }
    }
    return ans;
}

int main(){
    // initialisation of graph is not implemented
    // only functions defined as required on leetcode
    
    return 0;
}