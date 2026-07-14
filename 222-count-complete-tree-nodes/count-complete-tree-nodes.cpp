/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int countNodes(TreeNode *root){
        cntNode(root);
        return ans;
    }
    void cntNode(TreeNode* root) {
        if (root == NULL) return;
        countNodes(root->left);
        ans++;
        countNodes(root->right);
    }
};