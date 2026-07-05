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
		vector<vector<int>> allRootToLeaf(TreeNode* root) {
            vector<vector<int>> allPaths; 
            vector<int> currentPath;
            dfs(root, currentPath, allPaths);
            return allPaths;
		}
        void dfs(TreeNode* node, vector<int>& path, vector<vector<int>>& allPaths) {
            if (!node) {
                return;
            }
            path.push_back(node->data);
            if (!node->left && !node->right) {
                allPaths.push_back(path); 
            } else {
                dfs(node->left, path, allPaths); 
                dfs(node->right, path, allPaths); 
            }
            path.pop_back();
        }
};