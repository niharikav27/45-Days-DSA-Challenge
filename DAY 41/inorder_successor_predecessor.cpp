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
		vector<int> succPredBST(TreeNode* root,int key){
			TreeNode* predecessor = NULL;
            TreeNode* successor = NULL;
            TreeNode* curr = root;

            while (curr != NULL) {
                if (key > curr->data) {
                    predecessor = curr;
                    curr = curr->right;
                } else if (key < curr->data) {
                    successor = curr;
                    curr = curr->left;
                } else {
                    if (curr->left) {
                        TreeNode* temp = curr->left;
                        while (temp->right)
                            temp = temp->right;
                            predecessor = temp;
                    }
                    if (curr->right) {
                        TreeNode* temp = curr->right;
                        while (temp->left)
                            temp = temp->left;
                        successor = temp;
                    }
                    break;
                }
            }
            int predVal = (predecessor ? predecessor->data : -1);
            int succVal = (successor ? successor->data : -1);
            return {predVal, succVal};
		   }
};