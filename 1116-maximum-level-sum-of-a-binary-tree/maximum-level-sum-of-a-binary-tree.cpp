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
    int maxLevelSum(TreeNode* root) {
        int maxLevel = 1,currLevel = 1;
        int ans = INT_MIN;
        if (root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int sum = 0;
            int level = q.size();
            for (int i=0;i<level;i++){
                TreeNode *curr = q.front();q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                sum+=curr->val;
            }
            if (sum>ans){
                ans = sum;
                maxLevel = currLevel;
            }
            currLevel++;
        }
        return maxLevel;
    }
};