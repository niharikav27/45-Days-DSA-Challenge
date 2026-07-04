/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution {
public:
    void recursionRight(TreeNode* root, int level, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        if (res.size() == level) {
            res.push_back(root->data);
        }
        recursionRight(root->right, level + 1, res);
        recursionRight(root->left, level + 1, res);
    }
    void recursionLeft(TreeNode* root, int level, vector<int>& res) {
        if (root == nullptr) {
            return;
        }
        if (res.size() == level) {
            res.push_back(root->data);
        }
        recursionLeft(root->left, level + 1, res);
        recursionLeft(root->right, level + 1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursionRight(root, 0, res);
        return res;
    } 
    vector<int> leftsideView(TreeNode* root) {
        vector<int> res;
        recursionLeft(root, 0, res);
        return res;
    }   
};