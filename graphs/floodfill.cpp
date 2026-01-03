floodfill algo
https://leetcode.com/problems/flood-fill/submissions/1843647910/
// can do via both dfs nd bfs
class Solution {
public:
    // Can be done using both bfs nd dfs
    void dfs(int r,int c, int ocolor , int ncolor, vector<vector<int>>&image){
        int m=image.size();
        int n=image[0].size();
        if(r<0 || c<0 || r>=m || c>=n)return;
        if(image[r][c]!=ocolor)return;
        image[r][c]=ncolor;
        dfs(r-1,c,ocolor,ncolor,image);
        dfs(r+1,c,ocolor,ncolor,image);
        dfs(r,c-1,ocolor,ncolor,image);
        dfs(r,c+1,ocolor,ncolor,image);

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        int ocolor=image[sr][sc];
        if(ocolor==color)return image;
        dfs(sr,sc,ocolor,color,image);
        return image;

        
    }
};