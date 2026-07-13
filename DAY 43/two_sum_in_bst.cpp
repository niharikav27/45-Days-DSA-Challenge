/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/
class BSTIterator{
    stack<TreeNode*>mystack;
    bool reverse = true;
public:
    BSTIterator(TreeNode*root,bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }  
    bool hasNext(){
        return !stack.empty();
    }  
    int next(){
        TreeNode *tmpNode = stack.top();
        stack.pop();
        if(!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->data;
    }
    void pushAll(TreeNode *node){
        for(;node!= NULL;){
            stack.push(node);
            if(reverse == true){
                node = node->right;
            }else{
                node = node->left;
            }
        }
    }
};
class Solution{	
	public:
		bool twoSumBST(TreeNode* root, int k){
			if(!root) return false;
            BSTIterator l(root , false);
            BSTIterator r(root , true);
            int i = l.next();
            int j = r.next();
            while(i < j){
                if(i + j == k) return true;
                else if (i + j < k) i = l.next();
                else j = r.next();
            }
            return false;
		}
};