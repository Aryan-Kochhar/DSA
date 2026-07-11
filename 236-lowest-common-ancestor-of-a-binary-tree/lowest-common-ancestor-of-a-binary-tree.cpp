/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode *root,vector<TreeNode*> &ans,TreeNode *n){
        if (!root) return false;
        ans.push_back(root);
        if (root == n) return true;
        if (getPath(root->left,ans,n) || getPath(root->right,ans,n)) return true;
        ans.pop_back();
        return false;
    }

    vector<TreeNode*> rootToNode(TreeNode *root,TreeNode *n){
        vector<TreeNode*> ans;
        getPath(root,ans,n);
        return ans;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        vector<TreeNode*> path1 = rootToNode(root,p);
        vector<TreeNode*> path2 = rootToNode(root,q);

        int i = 0;
        while (i<path1.size() && i<path2.size() && path1[i]==path2[i]) i++;
        return path1[i-1];
    }
};