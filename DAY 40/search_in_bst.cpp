/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {	
public:	
    TreeNode* searchBST(TreeNode* root, int val) {
    	while (root != nullptr && root->data != val) {
            root = (root->data > val) ? root->left : root->right;
        }
        return root;
    }
};