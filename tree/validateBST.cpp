#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inOrderF(TreeNode* root, vector<int>& inOrder) {
    if(!root)    
        return;
    inOrderF(root->left, inOrder);
    inOrder.push_back(root->val);
    inOrderF(root->right, inOrder);
}

bool isValidBST(TreeNode* root) {
    vector<int> inOrder;
    inOrderF(root, inOrder);
    for(int i = 1; i < inOrder.size(); i++) {
        if(inOrder[i] <= inOrder[i - 1])
            return false;
    }
    return true;
}

int main(){
    // tree initialisation 
    
    return 0;
}