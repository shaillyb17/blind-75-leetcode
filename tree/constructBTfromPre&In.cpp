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

int idPre = 0;
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int start, int end) {
    if(start > end)
        return NULL;
    TreeNode* curr = new TreeNode(preorder[idPre++]);
    int pos;
    for(int i = start; i <= end; i++) {
        if(inorder[i] == curr->val) {
            pos = i;
            break;
        }
    }
    curr->left = buildTree(preorder, inorder, start, pos - 1);
    curr->right = buildTree(preorder, inorder, pos + 1, end);
    return curr;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size() == 0)
        return NULL;
    return buildTree(preorder, inorder, 0, preorder.size() - 1);        
}

int main(){
    // tree initialisation 
    
    return 0;
}