class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> ans;
        for (int j=0;j<n;j++){
            vector<int> row;
            for (int i=n-1;i>=0;i--){
                row.push_back(matrix[i][j]);
            }
            ans.push_back(row);
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }
};