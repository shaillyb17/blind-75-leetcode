#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> s;
    s.push(root);
    root = root->left;
    int count = 0;
    while(!s.empty() || root) {
        if(root) {
            s.push(root);
            root = root->left;
        }
        else {
            TreeNode* curr = s.top();
            s.pop();
            count++;
            if(count == k)
                return curr->val;
            root = curr->right;
        }
    }
    return -1;                      
}

int main(){
    // tree initialisation 
    
    return 0;
}