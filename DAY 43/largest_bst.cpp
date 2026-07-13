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
        struct NodeValue {
            int minNode, maxNode, maxSize;
             NodeValue(int minNode, int maxNode, int maxSize) : minNode(minNode), maxNode(maxNode), maxSize(maxSize) {}
        };
        NodeValue largestBSTSubtreeHelper(TreeNode* node) {
            if (!node) {
                return NodeValue(INT_MAX, INT_MIN, 0);
            }
            NodeValue left = largestBSTSubtreeHelper(node->left);
            NodeValue right = largestBSTSubtreeHelper(node->right);
            if (left.maxNode < node->data && node->data < right.minNode) {
                return NodeValue(
                    min(node->data, left.minNode),
                    max(node->data, right.maxNode),
                    left.maxSize + right.maxSize + 1
                );
            }
            return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
        }
		int largestBST(TreeNode* root){
			return largestBSTSubtreeHelper(root).maxSize;
		}
};