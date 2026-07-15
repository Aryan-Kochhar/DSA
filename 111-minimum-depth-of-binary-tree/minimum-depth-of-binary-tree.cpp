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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});

        while(!q.empty()){
            TreeNode *temp = q.front().first;
            int depth = q.front().second;
            q.pop();

            if(temp->left == nullptr && temp->right == nullptr) return depth;

            if(temp->left != nullptr){
                q.push({temp->left,depth + 1});
            }
            if(temp->right != nullptr){
                q.push({temp->right,depth + 1});
            }
        }
        return 0;
    }
};