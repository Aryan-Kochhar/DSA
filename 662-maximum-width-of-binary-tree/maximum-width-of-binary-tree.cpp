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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        long long maxW = 0;
        while (!q.empty()){
            long long L = q.front().second;
            long long R = q.back().second;
            maxW = max(maxW,R-L+1);
            int size = q.size();
            long long mmin = q.front().second;
            for (int i=0;i<size;i++){
                TreeNode *curr = q.front().first;
                long long idx = q.front().second-mmin;
                q.pop();
                if (curr->left) q.push({curr->left,2*idx+1});
                if (curr->right) q.push({curr->right,2*idx+2});
            }
        }
        return (int)maxW;
    }
};