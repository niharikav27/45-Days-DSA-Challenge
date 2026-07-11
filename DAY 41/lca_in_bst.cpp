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
		TreeNode* lca(TreeNode* root, int p, int q){
	        if(root == NULL) return NULL;
            int curr = root -> data;
            if(curr < p && curr < q){
                return lca(root->right,p,q);
            }
            if(curr > p && curr > q){
                return lca(root->left,p,q);
            }
            return root;
		}
};