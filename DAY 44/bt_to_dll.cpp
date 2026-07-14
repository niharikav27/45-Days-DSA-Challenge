class Solution {
public:
    TreeNode* prev = nullptr;
    TreeNode* head = nullptr;

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (!prev) {
            head = node;
        } else {
            prev->right = node;
            node->left = prev;
        }
        prev = node;
        inorder(node->right);
    }
    TreeNode* bToDLL(TreeNode* root) {
        prev = nullptr;
        head = nullptr;
        inorder(root);
        return head;
    }
};