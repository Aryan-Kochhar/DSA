
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;
        queue<TreeNode *> q;
        q.push(root);
        bool flag = false;
        while (!q.empty()){
            vector<int> level;
            int size = q.size();
            for (int i=0;i<size;i++){
                TreeNode *curr = q.front();q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                level.push_back(curr->val);
            }
            if (!flag){
                ans.push_back(level);
                flag = !flag;
            } else {
                reverse(level.rbegin(),level.rend());
                ans.push_back(level);
                flag = !flag;
            }
        }
        return ans;
    }
};