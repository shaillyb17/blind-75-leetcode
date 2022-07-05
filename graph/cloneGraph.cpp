#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneGraph(Node* node) {
    if(!node)
        return NULL;
    Node* res = new Node();
    res->val = node->val;
    queue<Node*> q;
    q.push(node);
    map<Node*, Node*> vis;
    vis[node] = res;
    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
        for(auto x: curr->neighbors) {
            if(vis[x] == NULL) {
                Node* copy = new Node();
                copy->val = x->val;
                vis[x] = copy;
                q.push(x);
            }
            vis[curr]->neighbors.push_back(vis[x]);
        }
    }
    return res;
}


int main(){
    // initialisation of graph is not implemented
    // only functions defined as required on leetcode
    
    return 0;
}