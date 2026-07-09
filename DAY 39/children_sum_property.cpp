/* class TreeNode {
       int val;
       TreeNode *left, *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
*/

class Solution {
public:
    bool checkChildrenSum(TreeNode* root) {
        if (root == NULL) return true;
        if (!root->left && !root->right) return true;

        int leftVal = root->left ? root->left->val : 0;
        int rightVal = root->right ? root->right->val : 0;

        return (root->val == leftVal + rightVal) &&
               checkChildrenSum(root->left) &&
               checkChildrenSum(root->right);
    }
};
