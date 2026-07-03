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
        void func(TreeNode* node, vector<int>& ans) {
            if (node == nullptr) {
                return;
            }
            ans.push_back(node->data);
            func(node->left, ans);
            func(node->right, ans);
        }
		vector<int> preorder(TreeNode* root){
            vector<int> ans;
            func(root, ans);
            return ans;
		}
};