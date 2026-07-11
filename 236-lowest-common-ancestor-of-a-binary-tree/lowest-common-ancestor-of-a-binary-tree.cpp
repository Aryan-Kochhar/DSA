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
    // bool getPath(TreeNode *root,vector<TreeNode*> &ans,TreeNode *n){
    //     if (!root) return false;
    //     ans.push_back(root);
    //     if (root == n) return true;
    //     if (getPath(root->left,ans,n) || getPath(root->right,ans,n)) return true;
    //     ans.pop_back();
    //     return false;
    // }

    // vector<TreeNode*> rootToNode(TreeNode *root,TreeNode *n){
    //     vector<TreeNode*> ans;
    //     getPath(root,ans,n);
    //     return ans;
    // }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);

        if (left == NULL) return right;
        else if (right == NULL) return left;
        else return root;
    }
};