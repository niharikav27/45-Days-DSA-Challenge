/* class TreeNode {
       int val;
       TreeNode *left, *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
*/

class Solution {
public:
    TreeNode* prev = nullptr;

    void flattenHelper(TreeNode* root) {
        if (!root) return;
        flattenHelper(root->right);
        flattenHelper(root->left);
        root->right = prev;
        root->left = nullptr;
        prev = root;
    }
    void flatten(TreeNode* root) {
        flattenHelper(root);
    }
};
