/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root == NULL || isSymmetricHelp(root->left , root->right);
    }
    bool isSymmetricHelp(TreeNode* left , TreeNode* right){
        if(left == NULL || right == NULL) return left == right;
        if(left->data != right->data) return false;

        return isSymmetricHelp(left->left, right->right) 
                    && isSymmetricHelp(left->right, right->left);
    }
};