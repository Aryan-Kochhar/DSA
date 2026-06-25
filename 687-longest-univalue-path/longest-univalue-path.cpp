class Solution {
public:
    int ans = 0;
    int len(TreeNode* root) {
        if (root == NULL) return 0;
        int left = len(root->left);
        int right = len(root->right);
        int l=0,r=0;
        if (root->left && root->left->val == root->val)
            l = left+1;
        if (root->right && root->right->val == root->val)
            r = right+ 1;
        ans = max(ans,l+r);
        return max(l, r);
    }

    int longestUnivaluePath(TreeNode* root) {
        len(root);
        return ans;
    }
};