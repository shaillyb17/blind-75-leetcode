#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    vector<int> v;
    vector<vector<int>> res;
    if(!root)
        return res;
    while(!q.empty()) {
        int qLen = q.size();
        for(int i = 0; i < qLen; i++) {
            TreeNode* temp = q.front();
            q.pop();
            v.push_back(temp->val);
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        res.push_back(v);
        v.clear();
    }
    return res;
}

int main(){
    // tree initialisation 
    
    return 0;
}