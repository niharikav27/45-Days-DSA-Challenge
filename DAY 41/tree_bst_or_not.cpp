/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
		bool isBST(TreeNode* root){
			return validate(root, LLONG_MIN, LLONG_MAX);
		}
        bool validate(TreeNode* node, long long min, long long max) {
        if (node == nullptr) return true;
        if (node->data <= min || node->data >= max) return false;
        return validate(node->left, min, node->data) && 
               validate(node->right, node->data, max);
    }
};