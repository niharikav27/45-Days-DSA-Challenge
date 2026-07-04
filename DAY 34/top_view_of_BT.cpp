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
    vector<int> topView(TreeNode *root){
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        map<int, int> mpp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode *node = it.first;
            int line = it.second;
            if (mpp.find(line) == mpp.end()) {
                mpp[line] = node->data;
            }
            if (node->left != nullptr) {
                q.push({node->left, line - 1});
            }
            if (node->right != nullptr) {
                q.push({node->right, line + 1});
            }
        }
        for (auto it : mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};