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
    vector<int> getInorder(TreeNode* root) {
    	vector<int> inorder;
        TreeNode* cur = root; 
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                inorder.push_back(cur->data); 
                cur = cur->right; 
            } else {
                TreeNode* prev = cur->left; 
                while (prev->right && prev->right != cur) {
                    prev = prev->right;
                }
                if (prev->right == nullptr) {
                    prev->right = cur; 
                    cur = cur->left; 
                } else {    
                    prev->right = nullptr; 
                    inorder.push_back(cur->data); 
                    cur = cur->right;
                }
            }
        }
        return inorder;
    }
};