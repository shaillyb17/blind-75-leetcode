#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isIdentical(TreeNode* root1, TreeNode* root2) {
    if(!root1 && !root2)
        return true;
    if(!root1 || !root2)
        return false;
    return (root1->val == root2->val && isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right));
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(!root)
        return false;
    if(isIdentical(root, subRoot))
        return true;
    return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
}

int main(){
    // tree initialisation 
    
    return 0;
}