#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if(!root)
        return "x";
    string leftSerialized = serialize(root->left);
    string rightSerialized = serialize(root->right);
    return to_string(root->val) + "," + leftSerialized + rightSerialized;
}

TreeNode* desUtil(string& data) {
    //cout<<data<<endl;
    if(data.size() == 0)
        return NULL;
    if(data[0] == 'x') {
        data = data.substr(1);
        return NULL;
    }
    int pos = 0;
    string num = "";
    while(data[pos] != ',') {
        num += data[pos++];
    }
    TreeNode *curr = new TreeNode(stoi(num));
    data = data.substr(pos + 1);
    curr->left = desUtil(data);
    curr->right = desUtil(data);
    return curr;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data.size() <= 1)
        return NULL;
    return desUtil(data);
}

int main(){
    // tree initialisation 
    
    return 0;
}