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
        void func(TreeNode* root, vector<int>& arr){
            if(root==NULL){
                return;
            }
            func(root->left, arr);
            func(root->right, arr);
            arr.push_back(root->data);
        }
		vector<int> postorder(TreeNode* root){
	        vector<int> arr;
            func(root, arr);
            return arr;
		}
};