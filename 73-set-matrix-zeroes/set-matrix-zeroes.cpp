class Solution {
public:
    void setColZeroes(vector<vector<int>> &matrix,int i,int j,int n,int m){
        for (int i=0;i<n;i++){
            if (matrix[i][j]!=0) matrix[i][j] = 69420;
        }
    }
    void setRowsZeroes(vector<vector<int>> &matrix,int i,int j,int n,int m){
        for (int j=0;j<m;j++){
            if (matrix[i][j]!=0) matrix[i][j] = 69420;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (matrix[i][j]==0){
                    setRowsZeroes(matrix,i,j,n,m);
                    setColZeroes(matrix,i,j,n,m);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 69420)
                    matrix[i][j] = 0;
            }
        }
    }
};