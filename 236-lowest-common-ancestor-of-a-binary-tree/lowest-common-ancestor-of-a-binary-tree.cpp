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
    bool getPath(TreeNode *root,vector<int> &ans,int n){
        if (!root) return false;
        ans.push_back(root->val);
        if (root->val == n) return true;
        if (getPath(root->left,ans,n) || getPath(root->right,ans,n)) return true;
        ans.pop_back();
        return false;
    }

    vector<int> rootToNode(TreeNode *root,int n){
        vector<int> ans;
        if (root == nullptr) return ans;
        getPath(root,ans,n);
        return ans;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        vector<int> path1 = rootToNode(root,p->val);
        vector<int> path2 = rootToNode(root,q->val);

        int i = 0;
        while (i<path1.size() && i<path2.size() && path1[i]==path2[i]) i++;
        return new TreeNode(path1[i-1]);
    }
};