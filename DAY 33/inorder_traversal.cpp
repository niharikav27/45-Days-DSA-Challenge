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
        void recursiveInorder(TreeNode* root, vector<int> &arr){
        if(root == nullptr){
            return;
        }
        recursiveInorder(root->left, arr);
        arr.push_back(root->data);
        recursiveInorder(root->right, arr);
    }
		vector<int> inorder(TreeNode* root){
            vector<int> arr;
            recursiveInorder(root, arr);
            return arr;
		}
};       