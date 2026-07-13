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
    vector<int> array;

    void inorder(TreeNode *root){
        if (root == nullptr) return;
        inorder(root->left);
        array.push_back(root->val);
        inorder(root->right);
    }

    bool findTarget(TreeNode* root, int k) {
        array.clear();
        inorder(root);
        int start = 0, end = array.size()-1;
        while (start<end){
            int sum = array[start]+array[end];
            if (sum == k) return true;
            else if (sum<k) start++;
            else end--;
        }
        return false;
    }
};