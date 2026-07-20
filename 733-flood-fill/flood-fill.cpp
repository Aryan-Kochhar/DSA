class Solution {
public:
    void dfs(vector<vector<int>> &image,int r,int c,int oldColour,int colour){
        int n = image.size();
        int m = image[0].size();
        if (r<0 || c<0 || r>=n || c>=m) return;
        if (image[r][c] != oldColour) return;
        image[r][c] = colour;
        dfs(image,r-1,c,oldColour,colour);
        dfs(image,r+1,c,oldColour,colour);
        dfs(image,r,c-1,oldColour,colour);
        dfs(image,r,c+1,oldColour,colour);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int colour) {
        int oldColour = image[sr][sc];
        if (oldColour == colour) return image;
        dfs(image,sr,sc,oldColour,colour);
        return image;
    }
};